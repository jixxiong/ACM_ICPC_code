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
    auto& operator()(i32 i){ return (*this)[i]; }
    using VC = std::conditional_t<D == 1, T, vc<T, D - 1>>;
    template<class...A> vc(A... a): std::vector<VC>(a...) { }
    auto const& operator()(i32 i) const { return (*this)[i]; }
    template<class...A> vc(i32 s=0, A... a): std::vector<VC>(s, VC(a...)) { }
    template<class...A> auto& operator()(i32 i,A... a){ return (*this)[i](a...); }
    template<class...A> auto const& operator()(i32 i,A... a) const { return (*this)[i](a...); }
};

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;

int32_t main() {
    i32 T; std::cin >> T;
    while (T--) {
        i32 n; std::cin >> n;
        vc<i32> A(n + 1);
        for (i32 i = 1; i <= n; ++i) {
            std::cin >> A[i];
        }
        auto rep = [](i32& i, i32 j) {
            i32 bk = i;
            i = std::__gcd(i, j);
            return bk;
        };
        auto check = [&]() {
            i32 g = 0;
            for (i32 i = 1; i <= n; ++i) {
                g = std::__gcd(g, A[i]);
            }
            return g == 1;
        };
        i32 ans = 100000000;
        if (check()) ans = 0;
        for (i32 i = 1; i <= n; ++i) {
            auto bi = rep(A[i], i);
            if (check()) ans = std::min(ans, n - i + 1);
            for (i32 j = i + 1; j <= n; ++j) {
                auto bj = rep(A[j], i);
                if (check()) ans = std::min(ans, n - i + 1 + n - j + 1);
                for (i32 k = j + 1; k <= n; ++k) {
                    auto bj = rep(A[j], i);
                    if (check()) ans = std::min(ans, n - i + 1 + n - j + 1);
                    A[j] = bj;
                }
                A[j] = bj;
            }
            A[i] = bi;
        }
        std::cout << ans << '\n';
    }
    return 0;
}
