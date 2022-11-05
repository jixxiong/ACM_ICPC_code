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
};

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;

i32 dijk(vc<std::tuple<i32, i32, bool>, 2> const& G, i32 n, vc<i32> const& dd) {
    vc<i64> dis(n + 1, INF<i64>());
    std::priority_queue<std::pair<i64, i32>> pq;
    pq.push({0, 1}); dis[1] = 0;
    vc<i32> pre(n + 1, -1);
    while (!pq.empty()) {
        auto [fi, u] = pq.top(); pq.pop();
        if (-fi != dis[u]) continue;
        for (auto [v, d, f]: G[u]) {
            if (dis[v] >= dis[u] + d) {
                if (dis[v] > dis[u] + d) {
                    pq.push({-(dis[v] = dis[u] + d), v});
                    if (f) pre[v] = 0;
                    else pre[v] = u;
                } else if (!f) {
                    pre[v] = u;
                }
            }
        }
    }
    i32 ret = 0;
    for (i32 i = 2; i <= n; ++i) {
        if (pre[i] && dd[i] != INF<i32>()) ret++;
    }
    return ret;
}

int32_t main() {
    i32 n, m, k; std::cin >> n >> m >> k;
    vc<std::tuple<i32, i32, bool>, 2> G(n + 1);
    for (i32 i = 1; i <= m; ++i) {
        i32 u, v, x; std::cin >> u >> v >> x;
        if (u > v) std::swap(u, v);
        G[u].pb(v, x, false);
        G[v].pb(u, x, false);
    }
    i32 ans = 0;
    auto dd = vc<i32>(n + 1, INF<i32>());
    for (i32 i = 1; i <= k; ++i) {
        i32 x, d; std::cin >> x >> d;
        if (d >= dd[x]) {
            ans++;
        } else {
            if (dd[x] != INF<i32>()) ans++;
            dd[x] = d;
            G[1].pb(x, d, true);
        }
    }
    std::cout << ans + dijk(G, n, dd) << '\n';
    return 0;
}
