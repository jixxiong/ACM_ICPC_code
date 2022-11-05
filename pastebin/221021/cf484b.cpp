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
template<class T> T INF() { return std::numeric_limits<T>::max(); }
template<class T,i32 D=1> struct vc: std::vector<std::conditional_t<D==1,T,vc<T,D-1>>>{
    using VC = std::conditional_t<D == 1, T, vc<T, D - 1>>;
    template<class...A> vc(i32 s=0, A... a): std::vector<VC>(s, VC(a...)) { }
    template<class...A> vc(A... a): std::vector<VC>(a...) { }
};

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;

int32_t main() {
    i32 n; std::cin >> n;
    std::set<i32> st;
    for (i32 i = 1; i <= n; ++i) {
        i32 x; std::cin >> x;
        st.insert(x);
    }
    vc<i32>A(st.begin(), st.end());
    i32 m = *std::max_element(all(A));
    i32 ans = 0;
    for (auto x: A) {
        for (i32 i = 2 * x - 1; i <= m + x - 1; i += x) {
            auto p = std::lower_bound(A.rbegin(), A.rend(), i, std::greater<i32>());
            if (p != A.rend() && *p > i - x) ans = std::max(ans, *p % x);
        }
    }
    std::cout << ans << '\n';
    return 0;
}
