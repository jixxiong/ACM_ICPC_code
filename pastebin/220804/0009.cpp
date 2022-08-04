#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;

using i32=int32_t;
using i64=int64_t;
using i128=__int128;
ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

i32 fcmp(ld x,ld y=0,ld eps=EPS){
    if(std::abs(x-y)<eps) return 0;
    return x<y?-1:1;
}

struct point{
    ld x,y; // cos,sin
    point(ld x=0,ld y=0):x(x),y(y){ }
    point operator+(point o){ return point(x+o.x,y+o.y); }
    point operator-(point o){ return point(x-o.x,y-o.y); }
    point operator-(){ return point(-x,-y); }
    point operator-=(point o){ return *this=*this-o; }
    friend point operator*(ld k,point o){ return point(o.x*k,o.y*k); }
    ld len(){ return std::sqrt(x*x+y*y); }
    point reg(){ ld r=len(); return point(x/r,y/r); }
    friend std::istream& operator>>(std::istream&is,point&o){
        i32 x,y; is>>x>>y;
        o.x=x,o.y=y;
        return is;
    }
};

int32_t main(){
    std::cout<<std::fixed<<std::setprecision(10);
    i32 T; std::cin>>T;
    while(T--){
        point A,B,C,D;
        point a,b,c,d;
        std::cin>>A>>B>>C>>D>>a>>b>>c>>d;
        A-=D,B-=D,C-=D,a-=D,b-=D,c-=D,d-=D;
        ld x1=A.x-(a-d).x;
        ld x2=C.x-(c-d).x;
        ld x3=d.x;
        ld y1=A.y-(a-d).y;
        ld y2=C.y-(c-d).y;
        ld y3=d.y;
        ld alp=(x3*y2-x2*y3)/(x1*y2-x2*y1);
        ld bet=(x3*y1-x1*y3)/(x2*y1-x1*y2);
        auto ret=D+alp*A+bet*C;
        std::cout<<ret.x<<' '<<ret.y<<'\n';
    }
    return 0;
}

/*
1

4 1
6 3
4 5
2 3

3 2
5 2
5 4
3 4

1

0 5
15 5
15 0
0 0

3 2
9 5
10 3
4 0

*/