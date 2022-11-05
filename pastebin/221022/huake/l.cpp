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

i64 round(i64 fz, i64 fm) {
    i64 ret = fz / fm;
    if (fz % fm >= (fm + 1) / 2) ret++;
    return ret;
}

int32_t main() {
    i32 n, k; std::cin >> n >> k;
    i32 comb = 0, max = 0;
    i32 a = 0, b = 0;
    for (i32 i = 1; i <= n; ++i) {
        std::string s;
        if (i <= k) std::cin >> s;
        else s = "perfect";
        if (s == "perfect") {
            comb++;
            a++;
        }
        if (s == "good") {
            comb++;
            b++;
        }
        if (s == "miss" || s == "bad") {
            max = std::max(comb, max);
            comb = 0;
        }
    }
    max = std::max(max, comb);
    std::cout << round((i64)900000 * a + (i64)585000 * b + (i64)100000 * max, n) << '\n';
    return 0;
}
