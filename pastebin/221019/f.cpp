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
template<class T> T INF() { return std::numeric_limits<T>::max(); }

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;

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

// pre=>O(n), qry=>O(1)
struct Conbi{
    vc<mint>fac,inv;
    Conbi(i32 n):fac(n+1),inv(n+1){
        fac[0]=1;
        for(i32 i=1;i<=n;++i)
            fac[i]=fac[i-1]*i;
        inv[n]=fac[n].inv();
        for(i32 i=n-1;i>=0;--i)
            inv[i]=inv[i+1]*(i+1);
    }
    mint operator()(i32 x,i32 y)const{
        if(y<0||y>x) return 0;
        return (fac[x]*inv[y]*inv[x-y]);
    }
};

int32_t main() {
    i32 n, m; std::cin >> n >> m; n <<= 1;
    Conbi C(n);
    auto G = vcc<char>(n + 1, n + 1);
    for (i32 i = 1; i <= m; ++i) {
        i32 u, v; std::cin >> u >> v;
        G[u][v] = G[v][u] = true;
    }
    auto f = vcc<mint>(n + 1, n + 1);
    for (i32 i = 1; i < n; ++i) {
        if (G[i][i + 1]) {
            f[i][i + 1] = 1;
        }
    }
    for (i32 i = 1; i <= n; ++i) {
        for (i32 j = 1; j < i; ++j) {
            f[i][j] = 1;
        }
    }
    for (i32 len = 4; len <= n; len += 2) {
        for (i32 l = 1; l + len - 1 <= n; ++l) {
            i32 r = l + len - 1;
            if (G[l][r]) f[l][r] += f[l + 1][r - 1];
            for (i32 m = l + 1; m < r; m += 2) {
                i32 l1 = (m - l + 1) >> 1;
                i32 l2 = (r - m) >> 1;
                if (G[l][m] && G[m + 1][r]) {
                    f[l][r] += f[l + 1][m - 1] * f[m + 2][r - 1] * C(l1 + l2, l1);
                }
            }
        }
    }
    std::cout << f[1][n] << '\n';
    return 0;
}
