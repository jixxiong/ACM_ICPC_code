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
    point rot(point ang){ return point(x*ang.x-y*ang.y,x*ang.y+y*ang.x); }
    ld len(){ return std::sqrt(x*x+y*y); }
    point reg(){ ld r=len(); return point(x/r,y/r); }
    friend std::istream& operator>>(std::istream&is,point&o){
        i32 x,y; is>>x>>y;
        o.x=x,o.y=y;
        return is;
    }
};

int32_t main(){
    // point p(1,0);
    // p=p.rot(point(1,-1).reg());
    // du(p.x,p.y);
    std::cout<<std::fixed<<std::setprecision(10);
    i32 T; std::cin>>T;
    while(T--){
        point A,B,C,D;
        point a_,b_,c_,d_;
        std::cin>>A>>B>>C>>D>>a_>>b_>>c_>>d_;
        A-=D;
        B-=D;
        C-=D;
        a_-=D;
        b_-=D;
        c_-=D;
        d_-=D;
        auto _ang=(C).reg(); 
        _ang.y*=-1;
        A=A.rot(_ang);
        B=B.rot(_ang);
        C=C.rot(_ang);
        a_=a_.rot(_ang);
        b_=b_.rot(_ang);
        c_=c_.rot(_ang);
        d_=d_.rot(_ang);

        auto W=C.len(),H=A.len();
        auto a=d_.x,c=a_.x,d=c_.x,e=d_.y,f=a_.y,h=c_.y;
        point ret;
        if((fcmp(a*(h+H)+c*(e-h)+W*(e+H),f*(a+W)+d*(e-f+H))!=0)&&(fcmp(a*(h+H)+c*e+d*f,a*f+c*h+d*(e+H))!=0)&&(fcmp(H*W)!=0)){
            ret=point((W*(a*(H-f)+c*e))/(-a*f+a*h+a*H+c*(e-h)-d*(e-f+H)+e*W-f*W+H*W),
                      (H*(a*h-d*e+e*W))/(-a*f+a*h+a*H+c*(e-h)-d*(e-f+H)+e*W-f*W+H*W));
        _ang.y*=-1;
        ret=ret.rot(_ang)+D;

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


*/