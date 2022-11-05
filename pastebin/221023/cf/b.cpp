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
    // freopen("a.out", "w", stdout);
    // for (i32 n = 2; n <= 10; ++n) {
    //     vc<i32> A(n + 1);
    //     std::iota(all(A), 0);
    //     du(n, "===============");
    //     do {
    //         i32 mn = n;
    //         for (i32 i = 2; i <= n; ++i) {
    //             mn = std::min(mn, std::abs(A[i] - A[i - 1]));
    //         }
    //         if (mn == n / 2) {
    //             for (i32 i = 1; i <= n; ++i) {
    //                 std::cout << A[i] << " ";
    //             }
    //             std::cout << '\n';
    //         }
    //     } while (std::next_permutation(1 + all(A)));
    // }
    i32 T; std::cin >> T;
    while (T--) {
        i32 n; std::cin >> n;
        if (n & 1) {
            std::set<i32> st;
            for (i32 i = 1; i < n; ++i) {
                st.insert(i);
            }
            std::cout << n << ' ';
            i32 lst = n;
            for (i32 _ = 1; _ < n; ++_) {
                if (st.lower_bound(lst + n / 2) != st.end()) {
                    std::cout << *st.lower_bound(lst + n / 2) << ' ';
                    lst = *st.lower_bound(lst + n / 2);
                    st.erase(lst);
                } else {
                    auto p = std::prev(st.upper_bound(lst - n / 2));
                    std::cout << *p << ' ';
                    lst = *p;
                    st.erase(p);
                }
            }
            std::cout << '\n';
        } else {
            for (i32 i = 1; i <= n; ++i) {
                if (i & 1) {
                    std::cout << (n / 2 + (i / 2) + 1) << ' ';
                } else {
                    std::cout << (i / 2) << ' ';
                }
            }
            std::cout << '\n';
        }
    }
    return 0;
}
// even
// 5 1 6 2 7 3 8 4
