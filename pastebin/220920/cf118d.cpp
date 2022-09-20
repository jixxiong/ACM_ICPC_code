#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
#define ld long double
#define ll long long
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;
template<typename T>using vvvvvc=std::vector<vvvvc<T>>;
template<typename T>vvc<T> vcc(i32 s1=0,i32 s2=0,const T&init=T()){ return vvc<T>(s1,vc<T>(s2,init)); }
template<typename T>vvvc<T> vccc(i32 s1=0,i32 s2=0,i32 s3=0,const T&init=T()){ return vvvc<T>(s1,vcc(s2,s3,init)); }
template<typename T>vvvvc<T> vcccc(i32 s1=0,i32 s2=0,i32 s3=0,i32 s4=0,const T&init=T()){ return vvvvc<T>(s1,vccc(s2,s3,s4,init)); }
template<typename T>vvvvvc<T> vccccc(i32 s1=0,i32 s2=0,i32 s3=0,i32 s4=0,i32 s5=0,const T&init=T()){ return vvvvvc<T>(s1,vcccc(s2,s3,s4,s5,init)); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=100000000;

template<class fint,fint p,class LargerInt=i64>
struct ModInt{
    using Self=ModInt<fint,p,LargerInt>;
    fint _x;
    ModInt(LargerInt x=0):_x(x){ }
    ModInt(LargerInt x,bool arg):_x(arg?(x%p+p)%p:x){ }
    fint val()const{ return _x; }
    Self operator+(Self o)const{ fint x=_x+o._x; if(x<0) x+=p; if(x>=p) x-=p; return Self(x); }
    Self operator-(Self o)const{ fint x=_x-o._x; if(x<0) x+=p; if(x>=p) x-=p; return Self(x); }
    Self operator*(Self o)const{ fint x=(LargerInt)_x*o._x%p; return Self(x); }
    friend std::istream& operator>>(std::istream& is,Self& o){ return is>>o._x; }
    friend std::ostream& operator<<(std::ostream& os,Self  o){ return os<<o._x; }
    bool operator==(Self o)const{ return _x==o._x; }
    bool operator< (Self o)const{ return _x< o._x; }
    bool operator!=(Self o)const{ return _x!=o._x; }
    Self& operator+=(Self o){ return *this=*this+o; }
    Self& operator-=(Self o){ return *this=*this-o; }
    Self& operator*=(Self o){ return *this=*this*o; }
    Self pow(Self _y)const{
        Self x=*this; fint y=_y.val(); if(y==0) return Self(1);
        Self ret(1); for(;y;x*=x,y>>=1) if(y&1) ret*=x;
        return ret;
    }
    Self inv()const{ return pow(p-2); }
    Self operator/(Self o)const{ return *this*o.inv(); }
};
using mint=ModInt<i32,mod>;

int32_t main(){
    i32 n1,n2,k1,k2; std::cin>>n1>>n2>>k1>>k2;
    auto f=vcccc<mint>(n1+2,n2+2,2,std::max({n1,n2,k1,k2})+2);
    for(i32 x1=1;x1<=std::min(n1,k1);++x1){
        f[x1][0][0][x1]=1;
    }
    for(i32 x2=1;x2<=std::min(n2,k2);++x2){
        f[0][x2][1][x2]=1;
    }
    for(i32 x1=1;x1<=n1;++x1){
        for(i32 x2=1;x2<=n2;++x2){
            // last one is white
            // k = 1
            for(i32 y2=1;y2<=std::min(x2,k2);++y2){
                f[x1][x2][0][1] += f[x1-1][x2][1][y2];
            }
            // last one is white
            // 2 <= k <= x1
            for(i32 k=2;k<=std::min(x1,k1);++k){
                f[x1][x2][0][k] += f[x1-1][x2][0][k-1];
            }
            // last one is black
            // k = 1
            for(i32 y1=1;y1<=std::min(x1,k1);++y1){
                f[x1][x2][1][1] += f[x1][x2-1][0][y1];
            }
            // last one is black
            // 2 <= k <= x2
            for(i32 k=2;k<=std::min(x2,k2);++k){
                f[x1][x2][1][k] += f[x1][x2-1][1][k-1];
            }
        }
    }
    mint ret=0;
    for(i32 x=0;x<2;++x){
        for(i32 y=0;y<=std::max({n1,n2,k1,k2});++y){
            ret+=f[n1][n2][x][y];
        }
    }
    std::cout<<ret<<'\n';
    return 0;
}
