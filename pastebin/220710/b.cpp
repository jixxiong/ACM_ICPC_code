#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define de(...) void()
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){std::cerr<<"[DEBUG: LINE "<<__LINE__<<"]: ";_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

template<typename T>int fcmp(T x, T y=0){ if(std::fabs(x-y)<EPS) return 0; if(x<y) return -1; return 1; }

template<typename fint=ll>
struct Point{
	using Self=Point<fint>;
	fint x, y;
	Point(fint x=0,fint y=0):x(x),y(y){ }
	template<typename G>Point(Point<G> o):x(o.x),y(o.y){ }
	friend std::istream& operator>>(std::istream&is, Self&self){ return is>>self.x>>self.y; }
	friend std::ostream& operator<<(std::ostream&os, Self self){ return os<<"("<<self.x<<", "<<self.y<<")\n"; }
	friend Self operator+(Self self,Self rhs){ return Self{self.x+rhs.x, self.y+rhs.y}; }
	friend Self operator-(Self self,Self rhs){ return Self{self.x-rhs.x, self.y-rhs.y}; }
	friend bool operator==(Self self,Self rhs){ return self.x==rhs.x&&self.y==rhs.y; }
	friend bool operator!=(Self self,Self rhs){ return !(self.x==rhs.x&&self.y==rhs.y); }
	friend Point<ld> operator*(Self self,ld x){ return Point<ld>{self.x*x, self.y*x}; }
	friend Point<ld> operator/(Self self,ld x){ return Point<ld>{self.x/x, self.y/x}; }
	int get_quad(){ if(fcmp(x)>0&&fcmp(y)>=0) return 1; if(fcmp(x)<=0&&fcmp(y)>0) return 2; if(fcmp(x)<0&&fcmp(y)<=0) return 3; if(fcmp(x)>=0&&fcmp(y)<0) return 4; return 0; }
	Point<ld> rot(ld cosr,ld sinr){ return Point<ld>{x*cosr-y*sinr,y*cosr+x*sinr}; }
	fint dot(Self rhs){ return x*rhs.x+y*rhs.y; }
	fint det(Self rhs){ return x*rhs.y-rhs.x*y; }
	fint dis2(Self rhs){ return (x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y); }
	fint len2(){ return x*x+y*y; }
	ld dis(Self rhs){ return std::sqrt(dis2(rhs)); }
	ld len(){ return std::sqrt(len2()); }
	int to_left(Self o1, Self o2){ return fcmp((o2-o1).det(*this-o2)); }
	bool is_par(Self o){ return fcmp(det(o))==0; }
	bool is_ver(Self o){ return fcmp(dot(o))==0; }
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



int32_t main(){
    Point<ld> a; std::cin>>a;
    ld d; std::cin>>d;
    d = d * PI / 180;
    auto ans=a.rot(std::cos(d),std::sin(d));
    std::cout<<std::fixed<<std::setprecision(10);
    std::cout<<ans.x<<' '<<ans.y<<'\n';
    return 0;
}