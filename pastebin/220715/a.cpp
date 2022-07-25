#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
    #define de(...) 4933;
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const int INF=0x3f3f3f3f;
const ld EPS1=1e-18;
const ld EPS2=1e-8;
const ld PI=std::acos((ld)-1.0);

int fcmp(ld x,ld y=0,ld EPS=EPS1){
    if(std::abs(x-y)<EPS) return 0;
    if(x<y) return -1;
    return 1;
}

struct Point{
    ld x,y;
    Point(ld x=0,ld y=0):x(x),y(y){ }
    ld len2(){ return x*x+y*y; }
    ld len(){  return std::sqrt(len2()); }
    Point get_polar(){
        ld d=len();
        return Point{x/d,y/d};
    }
    int quad(){
        int fx=fcmp(x),fy=fcmp(y);
        if(fx>0&&fy>=0) return 1;
        if(fy>0&&fx<=0) return 2;
        if(fx<0&&fy<=0) return 3;
        if(fy<0&&fx>=0) return 4;
        return 0;
    }
    ld det(Point o){
        return x*o.y-y*o.x;
    }
    friend std::istream& operator>>(std::istream& is,Point& o){
        return is>>o.x>>o.y;
    }
    bool operator==(Point o)const{
        return fcmp(x,o.x)==0&&fcmp(y,o.y)==0;
    }
};

struct Stamp:Point{
    int k;
};

int32_t main(){
    int n; std::cin>>n;
    std::vector<Point>A(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i];
    }
    auto ang_plus=[&](ld sinr,ld cosr,ld sint,ld cost){
        return Point(cosr*cost-sinr*sint,sinr*cost+sint*cosr);
    };
    auto check=[&](ld d)->bool{
        std::vector<Stamp>B;
        int m=0;
        auto add=[&](Point a1, Point a2){
            if(a1.quad()==4&&a2.quad()==1){
                B.pb(Stamp{{0,0},1}); B.pb(Stamp{a2,-1});
                B.pb(Stamp{a1,1});
            }else{
                B.pb(Stamp{a1,1});B.pb(Stamp{a2,-1});
            }
        };
        for(int i=0;i<n;++i){
            if(fcmp(A[i].len2(),2*d*d)>=0) continue;
            ld r=A[i].len(); m++;
            auto [cosr,sinr]=A[i].get_polar(); sinr*=-1;
            ld sint=std::sqrt(r*r-d*d)/r,cost=d/r;
            add(ang_plus(sinr,cosr,-sint,cost),ang_plus(sinr,cosr,sint,cost));
            add(ang_plus(sinr,cosr,cost,sint),ang_plus(sinr,cosr,cost,-sint));
            add(ang_plus(sinr,cosr,sint,-cost),ang_plus(sinr,cosr,-sint,-cost));
            add(ang_plus(sinr,cosr,-cost,-sint),ang_plus(sinr,cosr,-cost,sint));
        }
        if(m==0) return true;
        auto cmp=[](Stamp o1,Stamp o2){
            if(o1.quad()!=o2.quad()) return o1.quad()<o2.quad();
            if(fcmp(o1.det(o2))==0) return o1.k>o2.k;
            return fcmp(o1.det(o2))>0;
        };
        std::sort(all(B),cmp);
        for(auto x:B){
            de('(',x.x,", ",x.y,')', x.k);
        }
        int cnt=0;
        for(int sz=B.size(),i=0,j=0;i<sz;i=j){
            cnt+=B[i].k;
            j=i+1;
            while(j<sz&&B[i]==B[j]){
                cnt+=B[j].k;
                j++;
            }
            if(cnt>=m) return true;
        }
        return B.empty();
    };
    ld l=1,r=1e10;
    for(int i=0;i<n;++i){
        if(fcmp(r,A[i].len())>0){
            r=A[i].len();
        }
    }
    de(l,r);
    while(fcmp(l,r,EPS2)<0){
        ld mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    std::cout<<std::fixed<<std::setprecision(4);
    std::cout<<l*8<<'\n';
    return 0;
}
