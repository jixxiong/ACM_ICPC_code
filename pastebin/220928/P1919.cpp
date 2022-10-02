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

template<class fint,fint const p,class LargerInt=i64>
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
    poly(i32 n=0):vc<mint>(n){ }
    poly(vc<mint>const &o):vc<mint>(o){ }
    static void init(i32 n){
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
    friend poly mul(poly a,poly b,i32 upper=0x3f3f3f3f){
        if((i32)a.size()>upper+1) a.resize(upper+1);
        if((i32)b.size()>upper+1) b.resize(upper+1);
        i32 n=a.size()-1,m=b.size()-1;
        init(n+m);
        a.dft(true), b.dft(true);
        poly c(limit);
        for(i32 i=0;i<limit;++i) c[i]=a[i]*b[i];
        c.dft(false);
        c.resize(std::min(upper+1,n+m+1));
        return c;
    }
    void regular(){
        while((i32)size()>0&&back()==0) pop_back();
    }
    friend std::istream& operator>>(std::istream& is, poly& p){
        for(auto& x:p) is>>x;
        return is;
    }
};
   i32  poly::limit{};
vc<i32> poly::R{};


int32_t main(){
    std::string a,b; std::cin>>a>>b;
    poly A(a.size()),B(b.size());
    for(i32 i=(i32)a.size()-1;i>=0;--i){
        A[(i32)a.size()-i-1]=a[i]^'0';
    }
    for(i32 i=(i32)b.size()-1;i>=0;--i){
        B[(i32)b.size()-i-1]=b[i]^'0';
    }
    auto C=mul(A,B);
    C.regular();
    for(i32 i=0;i<(i32)C.size();++i){
        if(C[i].val()>=10){
            if(i==(i32)C.size()-1) C.resize(C.size()+1);
            C[i+1]+=C[i].val()/10;
            C[i]._x%=10;
        }
    }
    for(i32 i=C.size()-1;i>=0;--i){
        std::cout<<C[i];
    }
    std::cout<<'\n';
    return 0;
}
