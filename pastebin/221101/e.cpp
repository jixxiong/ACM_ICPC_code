#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
decltype(clock()) tic, toc;
__attribute((constructor))void before(){tic=clock();}
__attribute((destructor)) void after (){toc=clock(); std::cerr<<"\nFinished in "<<toc-tic<<" ms.\n"; }
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define i32 int32_t
#define i64 int64_t
#define i128 __int128
#define ld long double
#define pb emplace_back
#define all(x) x.begin(),x.end()
template<class T> T INF() { return std::numeric_limits<T>::max(); }
template<class T,i32 D=1> struct vc: std::vector<std::conditional_t<D==1,T,vc<T,D-1>>>{
    using VC = std::conditional_t<D == 1, T, vc<T, D - 1>>;
    template<class...A> vc(A... a): std::vector<VC>(a...) { }
    template<class...A> vc(i32 s=0, A... a): std::vector<VC>(s, VC(a...)) { }
};

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

int32_t main() {
    i32 n, m, k; std::cin >> n >> m >> k;
    vc<mint, 2> f(m * k + 1, k + 1);
    f[0][0] = 1;
    mint ans = 0;
    for (i32 i = 0; i < k; ++i) {
        for (i32 j = 0; j <= i * m; ++j) {
            if (i && j % n == 0) {
                ans += f[j][i];
                f[j][i] = 0;
                continue;
            }
            for (i32 t = 1; t <= m; ++t) {
                f[j + t][i + 1] += f[j][i] / m;
            }
        }
    }
    for (i32 j = n; j <= k * m; j += n) {
        ans += f[j][k];
    }
    std::cout << ans << '\n';
    return 0;
}
