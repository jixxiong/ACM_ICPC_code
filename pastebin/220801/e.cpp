#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;

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
            if(y&1) ret=ret*x;
            x*=x; y>>=1;
        }
        return ret;
    }
    self inv()const{ return pow(p-2); }
};
using mint=ModInt<int32_t,mod>;

struct Conbi{
    vc<mint>fac,invfac;
    Conbi(int n):fac(n+1),invfac(n+1){ 
        fac[0]=1;
        for(int i=1;i<=n;++i){
            fac[i]=fac[i-1]*i;
        }
        invfac[n]=fac[n].inv();
        for(int i=n-1;i>=0;--i){
            invfac[i]=invfac[i+1]*(i+1);
        }
    }
    mint operator()(int x,int y)const{
        if(y<0||y>x) return mint(0);
        return fac[x]*invfac[x-y]*invfac[y];
    }
};

int32_t main(){
    int n,m,k; std::cin>>n>>m>>k;
    vc<int>d(n+1);
    Conbi conbi(n+1);
    for(int i=1;i<=m;++i){
        int u,v; std::cin>>u>>v;
        d[u]++; d[v]++;
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(d[i]&1) cnt++;
    }
    mint ans=0;
    for(int i=0;i<=k;i+=2){
        ans+=conbi(cnt,i)*conbi(n-cnt,k-i);
    }
    std::cout<<ans<<'\n';
    return 0;
}