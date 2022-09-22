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
ll const mod=998244353;

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
using Mint=ModInt<i32,mod>;

int norm(int x) {
    x%=mod; // 可以常数优化
    if(x<0) x+=mod;
    // if(x>=mod) x-=mod;
    return x;
}

int ksm(int x,int y) {
    if(x==0&&y==0) return 1;
    if(x==0) return 0;
    int ret=1;
    while(y) {if(y&1) ret=ret*x%mod; x=x*x%mod; y>>=1;}
    return ret;
}

struct mint {
    int x;
    mint(int x=0):x(norm(x)) {}
    int val() const {return x;}
    mint operator-() const {return mint(norm(mod-x));}
    mint inv() const {return mint(ksm(x,mod-2));}
    mint &operator*=(const mint &eax) {x=x*eax.x%mod; return *this;}
    mint &operator-=(const mint &eax) {x=norm(x-eax.x); return *this;}
    mint &operator+=(const mint &eax) {x=norm(x+eax.x); return *this;}
    mint &operator/=(const mint &eax) {return *this*=eax.inv();}
    friend mint operator*(const mint &eax,const mint &ebx) {mint ret=eax; ret*=ebx; return ret;}
    friend mint operator-(const mint &eax,const mint &ebx) {mint ret=eax; ret-=ebx; return ret;}
    friend mint operator+(const mint &eax,const mint &ebx) {mint ret=eax; ret+=ebx; return ret;}
    friend mint operator/(const mint &eax,const mint &ebx) {mint ret=eax; ret/=ebx; return ret;}
    friend std::istream &operator>>(std::istream &ins,mint &eax) {int value; ins>>value; eax=mint(value); return ins;}
    friend std::ostream &operator<<(std::ostream &outs,const mint &eax) {return outs<<eax.val();}
};


int32_t main(){
    std::mt19937 rng(4933);
    while(true){
        int a=rng()%mod,b=rng()%mod;
        assert((mint(a)*mint(b)).val()==(Mint(a)*Mint(b)).val());
        assert((mint(a)+mint(b)).val()==(Mint(a)+Mint(b)).val());
        assert((mint(a)-mint(b)).val()==(Mint(a)-Mint(b)).val());
    }
    return 0;
}
