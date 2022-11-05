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

struct edge {
    i32 u{}, v{};
};

int32_t main() {
    i32 T; std::cin >> T;
    while (T--) {
        i32 n, m; std::cin >> n >> m;
        vc<i32, 2> G(n + 1);
        vc<edge> E(m);
        vc<i32> ind(n + 1);
        for (i32 i = 0; i < m; ++i) {
            i32 tp;
            std::cin >> tp >> E[i].u >> E[i].v;
            if (tp) {
                G[E[i].u].pb(E[i].v);
                ind[E[i].v]++;
            }
        }
        std::queue<i32> q;
        vc<i32> ht(n + 1);
        i32 cnt = 0;
        for (i32 i = 1; i <= n; ++i) {
            if (ind[i] == 0) {
                ht[i] = ++cnt;
                q.push(i);
            }
        }
        while (!q.empty()) {
            i32 u = q.front(); q.pop();
            for (auto v: G[u]) {
                if (--ind[v] == 0) {
                    ht[v] = ++cnt;
                    q.push(v);
                }
            }
        }
        bool fail = false;
        for (i32 i = 1; i <= n; ++i) {
            if (ind[i] != 0) {
                fail = true;
            }
            if (ht[i] == 0) {
                ht[i] = ++cnt;
            }
        }
        if (fail) {
            std::cout << "NO\n";
            continue;
        }
        std::cout << "YES\n";
        for (auto [u, v]: E) {
            if (ht[u] > ht[v]) std::swap(u, v);
            std::cout << u << ' ' << v << '\n';
        }
    }
    return 0;
}
