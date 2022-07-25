#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
    #define de(...) 4933
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int fcmp(ld x,ld y=0,ld EPS=EPS){
    if(std::fabs(x-y)<EPS) return 0;
    if(x<y) return -1;
    return 1;
}

struct Point{
    ld x,y;
    bool operator<(Point o)const{ return fcmp(x,o.x)==0?fcmp(y,o.y)<0:fcmp(x,o.x)<0; }
    Point operator+(Point o){ return Point{x+o.x,y+o.y}; }
    Point operator/(ld k){ return Point{x/k,y/k}; }
    Point rot(ld cosr,ld sinr,Point ori=Point{0,0}){
        return Point{
            (x-ori.x)*cosr-(y-ori.y)*sinr+ori.x,
            (x-ori.x)*sinr+(y-ori.y)*cosr+ori.y
        };
    }
    
};

int32_t main(){
    int n,m; std::cin>>n>>m; n++,m++;
    std::vector<Point>A;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            Point p{(ld)i,(ld)j};
            A.pb(p);
        }
    }
    auto is_integer=[&](ld x){
        return fcmp(std::round(x),x)==0;
    };
    auto is_cross=[&](Point o1){
        return is_integer(o1.x)&&is_integer(o1.y)&&
                fcmp(1,o1.x)<=0&&fcmp(o1.x,n)<=0&&
                fcmp(1,o1.y)<=0&&fcmp(o1.y,m)<=0;
    };
    auto check=[&](Point o1,Point o2){
        Point mid=(o1+o2)/2;
        return is_cross(o1.rot(0,1,mid))&&
                is_cross(o2.rot(0,1,mid));
    };
    int cnt=0;
    for(int i=0;i<n*m;++i){
        for(int j=i+1;j<n*m;++j){
            if(check(A[i],A[j])){
                cnt++;
            }
        }
    }
    std::cout<<cnt/2<<'\n';
    return 0;
}