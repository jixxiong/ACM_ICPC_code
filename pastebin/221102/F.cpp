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
#define ll long long
#define i128 __int128
#define int long long
#define ld long double
#define pb emplace_back
#define all(x) x.begin(),x.end()
template<class T> T INF() { return std::numeric_limits<T>::max(); }
template<class T,i32 D=1> struct vc: std::vector<std::conditional_t<D==1,T,vc<T,D-1>>>{
    using VC = std::conditional_t<D == 1, T, vc<T, D - 1>>;
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

i32 constexpr base = 233;

// 求前缀子串的最大 border
struct Next:vc<i32>{
    // 构建 next 数组 O(n)
    template<typename T>
    Next(T const* s,i32 n):vc<i32>(n+1){
        auto&p=*this;
        for(i32 i=2,j=0;i<=n;++i){
            while(j&&s[i]!=s[j+1]) j=p[j];
            if(s[i]==s[j+1]) j++;
            p[i]=j;
        }
    }
};

int32_t main() {
    i32 n, q; std::cin >> n >> q;
    vc<mint, 2>row(n + 1, n + 1), col(n + 1, n + 1);
    vc<mint> pw(std::max(n, n) + 1); pw[0] = 1;
    for (i32 i = 1; i <= std::max(n, n); ++i) {
        pw[i] = pw[i - 1] * base;
    }
    for (i32 i = 1; i <= n; ++i) {
        for (i32 j = 1; j <= n; ++j) {
            char ch; std::cin >> ch;
            row[i][j] = row[i][j - 1] * base + ch;
            col[j][i] = col[j][i - 1] * base + ch;
        }
    }
    auto hash = [&](i32 i, i32 l, i32 r, vc<mint, 2> const& f) -> mint {
        return f[i][r] - f[i][l - 1] * pw[r - l + 1];
    };
    while (q--) {
        i32 x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
        vc<mint> A(y2 - y1 + 2), B(x2 - x1 + 2);
        for (i32 y = y1; y <= y2; ++y) {
            A[y - y1 + 1] = hash(y, x1, x2, col);
        }
        for (i32 x = x1; x <= x2; ++x) {
            B[x - x1 + 1] = hash(x, y1, y2, row);
        }
        auto na = Next(A.data(), y2 - y1 + 1), nb = Next(B.data(), x2 - x1 + 1);
        std::cout << (y2 - y1 + 1 - na[y2 - y1 + 1]) * (x2 - x1 + 1 - nb[x2 - x1 + 1]) << '\n';
    }
    return 0;
}
