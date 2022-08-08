#include <bits/stdc++.h>

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
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;
using i32=int32_t;
using i64=int64_t;
using i128=__int128;

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

template<class fint,fint p>
struct ModInt{
    using self=ModInt<fint,p>;
    fint _x;
    ModInt(fint x=0):_x((x%p+p)%p){ }
    fint val()const{ return _x; }
    self operator+(self o)const{ fint x=_x+o._x; if(x<0) x+=p; if(x>=p) x-=p; return self(x); }
    self operator-(self o)const{ fint x=_x-o._x; if(x<0) x+=p; if(x>=p) x-=p; return self(x); }
    self operator*(self o)const{ fint x=(int64_t)_x*o._x%p; if(x<0) x+=p; return self(x); }
    friend std::istream& operator>>(std::istream& is,self& o){ return is>>o._x; }
    friend std::ostream& operator<<(std::ostream& os,self  o){ return os<<o._x; }
    bool operator==(self o)const{ return _x==o._x; }
    bool operator!=(self o)const{ return _x!=o._x; }
    self& operator+=(self o){ return *this=*this+o; }
    self& operator-=(self o){ return *this=*this-o; }
    self& operator*=(self o){ return *this=*this*o; }
    self pow(self _y)const{
        self x=*this; fint y=_y.val();
        if(y==0) return self(1);
        self ret(1);
        while(y){
            if(y&1) ret*=x;
            x*=x; y>>=1;
        }
        return ret;
    }
    self inv()const{ return pow(p-2); }
};
using mint=ModInt<int32_t,mod>;

int32_t main(){
    i32 n; std::cin>>n;
    vc<i32>A(n);
    for(i32 i=1;i<n;++i){
        std::cin>>A[i];
    }
    vc<mint>f(n+2);
    for(i32 i=n-1;i>=1;--i){
        f[i]=(f[i+1]-f[std::min(i+A[i]+1,n+1)]+1)*(mint(A[i]).inv())+1;
        f[i]+=f[i+1];
        du(f[i]);
    }
    std::cout<<f[1]-f[2]<<'\n';
    return 0;
}