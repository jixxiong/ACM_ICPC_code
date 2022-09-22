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
using mint=ModInt<i32,mod>;

struct poly:vc<mint>{
    i32 static const p=mod, g=3, gi=p/g+1;
    static i32 limit;
    static vc<i32>R;
    poly(i32 n):vc<mint>(n){ }
    poly(vc<mint>const &o):vc<mint>(o){ }
    void pre(i32 n){
        i32 L=std::__lg(n)+1; limit=1<<L;
        if((i32)R.size()==limit) return ;
        R.resize(limit);
        for(i32 i=0;i<limit;++i) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
    }
    void dft(bool tp){ // true -> dft, false -> idft
        auto& A=*this;
        if((i32)A.size()<limit) A.resize(limit);
        for(i32 i=0;i<limit;++i) if(i<R[i]) std::swap(A[i],A[R[i]]);
        for(i32 mid=1;mid<limit;mid<<=1){
            mint const wn=mint(tp?g:gi).pow((p-1)/(mid<<1));
            for(i32 len=mid<<1,j=0;j<limit;j+=len){
                mint w=1;
                for(i32 k=0;k<mid;++k,w*=wn){
                    mint x=A[j+k],y=w*A[j+k+mid];
                    A[j+k]=x+y, A[j+k+mid]=x-y;
                }
            }
        }
        if(tp) return ;
        mint inv=mint(limit).pow(p-2);
        for(i32 i=0;i<limit;++i) A[i]*=inv;
    }
    poly mul(poly &b,i32 upper=0x3f3f3f3f){
        auto& a=*this;
        if((i32)a.size()>upper+1) a.resize(upper+1);
        if((i32)b.size()>upper+1) b.resize(upper+1);
        i32 n=a.size()-1,m=b.size()-1;
        pre(n+m);
        a.dft(true), b.dft(true);
        poly c(limit);
        for(i32 i=0;i<limit;++i) c[i]=a[i]*b[i];
        c.dft(false);
        c.resize(std::min(upper+1,n+m+1));
        return c;
    }
};
i32 poly::limit{};
vc<i32>poly::R{};

int32_t main(){
    i32 n,m; std::cin>>n>>m;
    poly A(n+1),B(m+1);
    for(i32 i=0;i<=n;++i) std::cin>>A[i];
    for(i32 i=0;i<=m;++i) std::cin>>B[i];
    auto C=A.mul(B);
    for(int i=0;i<=n+m;++i) std::cout<<C[i]<<' ';
    return 0;
}
