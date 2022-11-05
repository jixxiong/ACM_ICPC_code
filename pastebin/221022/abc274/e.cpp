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
    i32 n, m; std::cin >> n >> m;
    vc<std::pair<i32, i32>> A(n + m);
    for (i32 i = 0; i < n + m; ++i) {
        std::cin >> A[i].first >> A[i].second;
    }
    auto dis = [](std::pair<i32, i32> const& o1, std::pair<i32, i32> const& o2) -> ld {
        return std::sqrt((ld)(o1.first - o2.first) * (o1.first - o2.first) + (ld)(o1.second - o2.second) * (o1.second - o2.second));
    };
    vc<ld, 2> f(n + m, 1 << (n + m), (i64)1e18);
    for (i32 i = 0; i < n + m; ++i) {
        f[i][1 << i] = dis({0, 0}, A[i]);
    }
    for (i32 s = 0; s < (1 << (n + m)); ++s) {
        for (i32 i = 0; i < (n + m); ++i) {
            if ((s >> i) & 1) {
                for (i32 j = 0; j < (n + m); ++j) {
                    if (i != j && ((s >> j) & 1)) {
                        f[i][s] = std::min(f[i][s], f[j][s ^ (1 << i)] + dis(A[i], A[j]) / (1 << __builtin_popcount((s ^ (1 << i)) >> n)));
                    }
                }
            }
        }
    }
    ld ans = 1e18;
    for (i32 i = 0; i < n + m; ++i) {
        for (i32 s = 0; s < (1 << m); ++s) {
            ans = std::min(f[i][(s << n) | ((1 << n) - 1)] + dis({0, 0}, A[i]) / (1 << __builtin_popcount(s)), ans);
        }
    }
    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
    return 0;
}
