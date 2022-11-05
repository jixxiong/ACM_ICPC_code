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

i32 fcmp(ld x, ld y=0) {
    if (std::abs(x - y) < EPS) return 0;
    return x < y ? -1 : 1;
}

struct node {
    ld x{};
    int w{};
};

int32_t main() {
    int n; int D; std::cin >> n >> D;
    vc<int> W(n), X(n), V(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> W[i] >> X[i] >> V[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int const x1 = X[i], v1 = V[i];
        vc<node> A;
        for (int j = 0; j < n; ++j) {
            int w2 = W[j], x2 = X[j], v2 = V[j];
            if (v1 == v2) {
                if (x2 >= x1 && x2 <= x1 + D) {
                    A.pb(node{0, w2});
                    A.pb(node{1e10, -w2});
                }
                continue;
            }
            ld l = (ld)(x1 - x2) / (v2 - v1);
            ld r = (ld)(D + x1 - x2) / (v2 - v1);
            if (fcmp(l, r) > 0) std::swap(l, r);
            if (fcmp(r, 0) < 0) continue;
            A.pb(node{l, w2});
            A.pb(node{r, -w2});
        }
        std::sort(all(A), [](node const& o1, node const& o2) {
            return fcmp(o1.x, o2.x) == 0 ? o1.w > o2. w : fcmp(o1.x, o2.x) < 0;
        });
        int tot = 0;
        for (auto [x, w]: A) {
            tot += w;
            ans = std::max(ans, tot);
        }
    }
    std::cout << ans << '\n';
    return 0;
}
