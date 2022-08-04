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

struct point{
    ld x,y; // cos,sin
    point(ld x=0,ld y=0):x(x),y(y){ }
    point operator+(point o){ return point(x+o.x,y+o.y); }
    point operator-(point o){ return point(x-o.x,y-o.y); }
    point operator-(){ return point(-x,-y); }
    point operator-=(point o){ return *this=*this-o; }
    point rot(point ang){ return point(x*ang.x-y*ang.y,x*ang.y+y*ang.x); }
    ld len(){ return std::sqrt(x*x+y*y); }
    point reg(){ ld r=len(); return point(x/r,y/r); }
    friend std::istream& operator>>(std::istream&is,point&o){
        return is>>o.x>>o.y;
    }
};

int32_t main(){
    std::cout<<std::fixed<<std::setprecision(10);
    i32 T; std::cin>>T;
    while(T--){
        point A,B,C,D;
        point a,b,c,d;
        std::cin>>D>>C>>B>>A>>d>>c>>b>>a;
        auto k=(b-a).len()/(B-A).len();
        B-=A;C-=A;D-=A;a-=A,b-=A,c-=A,d-=A;
        auto _ang=B.reg(); _ang.y*=-1;
        B=B.rot(_ang);C=C.rot(_ang);D=D.rot(_ang);a=a.rot(_ang),b=b.rot(_ang),c=c.rot(_ang),d=d.rot(_ang);
        auto alp=(b-a).reg();
        auto ca=alp.x,sa=alp.y;
        du(ca,sa);
        auto x=a.x,y=a.y;
        auto f1=std::sqrt(x*x+y*y+k*k*sa*sa+k*k*ca*ca-2*k*ca+1);
        auto f2=(std::sqrt(k*k*x*x*sa*sa+k*k*x*x*ca*ca+k*k*y*y*sa*sa+k*k*y*y*ca*ca-2*k*x*x*ca-2*k*y*y*ca+x*x+y*y));
        auto f3=(k*x*ca+k*y*sa-x)*std::sqrt((x*x+y*y)*(k*k*sa*sa+k*k*ca*ca-2*k*ca+1));
        auto R=(-((k*k*x*y*ca*ca)/((k*x*ca+k*y*sa-x)*f1))+(k*k*x*y*y*sa*sa)/((k*x*ca+k*y*sa-x)*f1)-(x*y*y)/((k*x*ca+k*y*sa-x)*f1)+(2*k*x*y*y*ca)/((k*x*ca+k*y*sa-x)*f1)-(k*x*x*y*sa)/((k*x*ca+k*y*sa-x)*f1)+(k*k*x*x*y*sa*ca)/((k*x*ca*k*y*sa-x)*f1)-k*x*y*sa/f2+x*x/f2-(k*x*x*ca)/f2-k*x*x*ca/f2+k*y*y*y*sa/f3-k*k*y*y*y*sa*ca/f3)/(k*ca-1);
        auto ct=-(k*x*ca+k*y*sa-x)/(std::sqrt(k*k*x*x*sa*sa+k*k*x*x*ca*ca+k*k*y*y*sa*sa+k*k*y*y*ca*ca-2*k*x*x*ca-2*k*y*y*ca+x*x+y*y));
        auto st=std::sqrt(1-ct*ct);
        point ret(R*ct,R*st); 
        _ang.y*=-1;
        ret=ret.rot(_ang)+A;
        std::cout<<ret.x<<' '<<ret.y<<'\n';
    }
    return 0;
}