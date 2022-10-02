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
template<class T>using vc    =std::vector<T>;
template<class T>using vvc   =vc<vc<T>>;
template<class T>using vvvc  =vc<vvc<T>>;
template<class T>using vvvvc =vc<vvvc<T>>;
template<class T>using vvvvvc=vc<vvvvc<T>>;
template<class T> auto vcc   (i32 _1=0,i32 _2=0,const T&init=T()){ return vvc<T>(_1,vc<T>(_2,init)); }
template<class T> auto vccc  (i32 _1=0,i32 _2=0,i32 _3=0,const T&init=T()){ return vvvc<T>(_1,vcc(_2,_3,init)); }
template<class T> auto vcccc (i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,const T&init=T()){ return vvvvc<T>(_1,vccc(_2,_3,_4,init)); }
template<class T> auto vccccc(i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,i32 _5=0,const T&init=T()){ return vvvvvc<T>(_1,vcccc(_2,_3,_4,_5,init)); }
template<class T>T INF(){ return std::numeric_limits<T>::max(); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;

template<class fint,fint p,class LargerInt=i64>
struct ModInt{
    using Self=ModInt<fint,p,LargerInt>;
    fint _x;
    ModInt(LargerInt x=0):_x(x){ }
    ModInt(LargerInt x,bool arg):_x(arg?(x%p+p)%p:x){ }
    fint val()const{ return _x; }
    Self inv()const{ return pow(p-2); }
    Self pow(Self _y)const{ Self x=*this; fint y=_y.val(); if(y==0) return Self(1); Self ret(1); for(;y;x*=x,y>>=1) if(y&1) ret*=x; return ret; }
    Self operator+(Self o)const{ fint x=_x+o._x; if(x<0) x+=p; if(x>=p) x-=p; return Self(x); }
    Self operator-(Self o)const{ fint x=_x-o._x; if(x<0) x+=p; if(x>=p) x-=p; return Self(x); }
    Self operator*(Self o)const{ fint x=(LargerInt)_x*o._x%p; return Self(x); }
    Self operator/(Self o)const{ return *this*o.inv(); }
    bool operator< (Self o)const{ return _x< o._x; }
    bool operator==(Self o)const{ return _x==o._x; }
    bool operator!=(Self o)const{ return _x!=o._x; }
    Self& operator+=(Self o){ return *this=*this+o; }
    Self& operator-=(Self o){ return *this=*this-o; }
    Self& operator*=(Self o){ return *this=*this*o; }
    friend std::istream& operator>>(std::istream& is,Self& o){ return is>>o._x; }
    friend std::ostream& operator<<(std::ostream& os,Self  o){ return os<<o._x; }
};
using mint=ModInt<i32,mod>;

// pre=>O(n), qry=>O(1), large prime number
struct Conbi{
    std::vector<mint>fac,inv;
    Conbi(int n):fac(n+1),inv(n+1){
        fac[0]=1;
        for(int i=1;i<=n;++i)
            fac[i]=fac[i-1]*i;
        inv[n]=fac[n].inv();
        for(int i=n-1;i>=0;--i)
            inv[i]=inv[i+1]*(i+1);
    }
    mint operator()(int x,int y){
        if(y<0||y>x)
            return 0;
        return (fac[x]*inv[y]*inv[x-y]);
    }
};

int32_t main(){
    Conbi conbi(101);
    i32 T; std::cin>>T;
    vc<mint>A(101),B(101),C(101,1);
    A[1]=1,A[2]=3,A[3]=12,A[4]=42;
    B[2]=2,B[3]=7,B[4]=27;
    for(i32 i=5;i<=100;++i){
        A[i]=conbi(2*i-1,i);
        A[i]+=B[i-1];
        B[i]=conbi(2*i,i)-1-A[i];
    }
    while(T--){
        i32 n; std::cin>>n; n>>=1;
        std::cout<<A[n]<<' '<<B[n]<<' '<<C[n]<<'\n';
    }
    return 0;
}
