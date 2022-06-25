#include <bits/stdc++.h>
#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define er(args...) void()
#else
    #define vwn(x) #x"=",x,"\n"
    void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
    #define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;
const ld eps=1e-8;
const ld PI=std::acos((ld)-1.0);

template<typename T>int fcmp(T x, T y=0){ if(fabs(x-y)<eps) return 0; if(x<y) return -1; return 1; }

template<typename fint=ll>
struct Point{
    using Self=Point<fint>;
    fint x, y;
    Point(fint x=0,fint y=0):x(x),y(y){ }
    friend std::istream& operator>>(std::istream&is, Self&self){ return is>>self.x>>self.y; }
    friend std::ostream& operator<<(std::ostream&os, Self self){ return os<<"("<<self.x<<", "<<self.y<<")"; }
    friend Self operator+(Self self,Self rhs){ return Self{self.x+rhs.x, self.y+rhs.y}; }
    friend Self operator-(Self self,Self rhs){ return Self{self.x-rhs.x, self.y-rhs.y}; }
    friend bool operator==(Self self,Self rhs){ return self.x==rhs.x&&self.y==rhs.y; }
    friend bool operator!=(Self self,Self rhs){ return !(self.x==rhs.x&&self.y==rhs.y); }
    friend Point<ld> operator*(Self self,ld x){ return Point<ld>{self.x*x, self.y*x}; }
    friend Point<ld> operator/(Self self,ld x){ return Point<ld>{self.x/x, self.y/x}; }
    int get_quad(){
        if(fcmp(x)>0&&fcmp(y)>=0) return 1;
        if(fcmp(x)<=0&&fcmp(y)>0) return 2;
        if(fcmp(x)<0&&fcmp(y)<=0) return 3;
        if(fcmp(x)>=0&&fcmp(y)<0) return 4;
        assert(false);
    }
    Point<ld> rotate(ld t){ return Point<ld>{x*cos(t)-y*sin(t),y*cos(t)+x*sin(t)}; }
    fint dot(Self rhs){ return x*rhs.x+y*rhs.y; }
    fint det(Self rhs){ return x*rhs.y-rhs.x*y; }
    fint dis2(Self rhs){ return (x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y); }
    ld dis(Self rhs){ return std::sqrt(dis2(rhs)); }
    bool left(Self o1, Self o2){ return fcmp((o2-o1).det(*this-o2))>0; }
    friend ld min_dis2(std::vector<Self>&vec,int l,int r){
        std::vector<Point<ld>>A;
        ld ang=rand()%360/180.0*PI;
        for(int i=l;i<=r;++i) A.pb(vec[i].rotate(ang));
        std::sort(all(A),[](Point<ld>o1,Point<ld>o2){ return fcmp(o1.x,o2.x)==0?fcmp(o1.x,o2.x)<0:fcmp(o1.y,o2.y)<0; });
        ld ret=std::numeric_limits<ld>::max();
        for(int i=0;i<(int)A.size();++i)
            for(int j=i+1;j<=std::min((int)A.size()-1,i+10);++j)
                ret=std::min(ret,A[i].dis2(A[j]));
        return ret;
    }
    friend ld min_dis(std::vector<Self>&vec,int l,int r){ return std::sqrt(min_dis2(vec,l,r)); }
};

template<typename fint=ll>
struct Convex:std::vector<Point<fint>>{
    using inner=Point<fint>;
    using Self=Convex<fint>;
    Convex(int n=0):std::vector<Point<fint>>(n){ }
    friend std::istream& operator>>(std::istream&is,Self&self){ for(auto&x:self) is>>x; return is; }
    friend std::ostream& operator<<(std::ostream&os,Self&self){ for(auto&x:self) os<<x; return os; }
    void sort_by_quad(){
        std::sort(this->begin(),this->end(),[](inner o1,inner o2){ return o1.get_quad()==o2.get_quad()?fcmp(o1.det(o2))>0:o1.get_quad()<o2.get_quad(); });
    }
    void sort_by_ltl(){
        inner ltl=*std::min_element(this->begin(),this->end(),[](inner o1,inner o2){ return fcmp(o1.x,o2.x)==0?fcmp(o1.y,o2.y)<0:fcmp(o1.x,o2.x)<0; });
        std::sort(this->begin(),this->end(),[ltl](inner o1,inner o2){
            auto cross=(o1-ltl).det(o2-ltl);
            return fcmp(cross)==0?(fcmp(o1.x,o2.x)==0?fcmp(o1.y,o2.y)<0:fcmp(o1.x,o2.x)<0):fcmp(cross)>0;
        });
    }
    void to_convex(){
        sort_by_ltl();
        this->erase(std::unique(this->begin(),this->end()),this->end());
        if((int)this->size()==1) return ;
        Self& A=*this;
        std::vector<int>B{0,1};
        for(int i=2;i<(int)this->size();++i){
            while(((int)B.size()>=2)&&(!A[i].left(A[*next(B.rbegin())],A[B.back()]))) B.pop_back();
            B.pb(i);
        }
        Self ret; ret.reserve(B.size());
        std::for_each(all(B),[&](int i){ ret.pb(A[i]); });
        A=ret;
    }
    fint diameter2(){
        auto& g=*this;
        int p=1,n=g.size();
        auto area=[&](int i,int j,int q){
            return (g[j]-g[i]).det(g[q]-g[i]);
        };
        fint ret=0;
        for(int i=0;i<n;++i){
            while(area(i,(i+1)%n,p)<area(i,(i+1)%n,(p+1)%n))p=(p+1)%n;
            ret=std::max({ret,g[i].dis2(g[p]),g[(i+1)%n].dis2(g[p])});
        }
        return ret;
    }
    ld diameter(){
        return std::sqrt(diameter2());
    }
    ld perimeter(){
        Self& g=*this;
        int n=g.size();
        if(n<=1) return 0;
        if(n==2) return g[0].dis(g[1]) * 2; // unsure
        ld ret=0;
        for(int i=0;i<n;++i){
            ret+=g[i].dis(g[(i+1)%n]);
        }
        return ret;
    }
};

template<typename fint=ll>
struct Point3{
    using Self=Point3<fint>;
    fint x,y,z;
    Point3(fint x=0,fint y=0,fint z=0):x(x),y(y),z(z){ }
    friend std::istream& operator>>(std::istream&is, Self&self){ return is>>self.x>>self.y>>self.z; }
    friend std::ostream& operator<<(std::ostream&os, Self&self){ return os<<"("<<self.x<<", "<<self.y<<", "<<self.z<<")"; }
    friend Self operator+(Self self,Self rhs){ return Self{self.x+rhs.x, self.y+rhs.y, self.z+rhs.z}; }
    friend Self operator-(Self self,Self rhs){ return Self{self.x-rhs.x, self.y-rhs.y, self.z-rhs.z}; }
    friend Point3<ld> operator*(Self self,ld x){ return Point3<ld>{self.x*x, self.y*x, self.z*x}; }
    friend Point3<ld> operator/(Self self,ld x){ return Point3<ld>{self.x/x, self.y/x, self.z/x}; }
    fint dot(Self rhs){ return x*rhs.x+y*rhs.y+z*rhs.z; }
    Self det(Self rhs){ return { (y*rhs.z-rhs.y*z), -(x*rhs.z-rhs.x*z), (x*rhs.y-rhs.x*y) }; }
    fint dis2(Self rhs){ return (x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y)+(z-rhs.z)*(z-rhs.z); }
    ld dis(Self rhs){ return std::sqrt(dis2(rhs)); }
};

template<typename fint=ll>
struct Circle3{
    using Self=Circle3<fint>;
    Point3<fint>cen;
    fint rad;
    Circle3(fint x=0,fint y=0,fint z=0,fint rad=0):cen(x,y,z),rad(rad){ }
    bool rela(Self o){
        // -1=> 外不相交, 0 => 外切, 1 => 相交, 2 => 内切, 3 => 内涵
        fint dis = cen.dis2(o.cen);
        if(fcmp(dis,(rad+o.rad)*(rad+o.rad))>0) return -1;
        if(fcmp(dis,(rad+o.rad)*(rad+o.rad))==0) return 0;
        if(fcmp(std::sqrt(dis)+std::min(rad,o.rad),std::max(rad,o.rad))==0) return 2;
        if(fcmp(std::sqrt(dis)+std::min(rad,o.rad),std::max(rad,o.rad))<0) return 3;
        return 1;
    }
};

int32_t main(){
    int n; std::cin>>n;
    Convex<ld>A(n);
    std::cin>>A;
    A.to_convex();
    std::cout<<std::fixed<<std::setprecision(2)<<(A.perimeter())<<'\n';
    return 0;
}