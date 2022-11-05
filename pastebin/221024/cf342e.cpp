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

struct LCA {
    vc<i32, 2> st;
    vc<i32> dep;
    i32 const n;
    LCA(i32 n, i32 rt, vc<i32, 2> const& G): st(std::__lg(n) + 1, n + 1), dep(n + 1), n(n) {
        std::function<void(i32, i32)> dfs = [&](i32 u, i32 f) {
            for (auto v: G[u]) {
                if (v == f) continue;
                dep[v] = dep[u] + 1;
                st[0][v] = u;
                for (i32 i = 1; i <= std::__lg(dep[v]); ++i) {
                    st[i][v] = st[i - 1][st[i - 1][v]];
                }
                dfs(v, u);
            }
        };
        dep[rt] = 1;
        dfs(rt, rt);
    }
    i32 get(i32 x, i32 y) {
        if (dep[x] < dep[y]) std::swap(x, y);
        for (i32 i = std::__lg(n); i >= 0; --i) {
            if (dep[st[i][x]] >= dep[y]) {
                x = st[i][x];
            }
        }
        if (x == y) return x;
        for (i32 i = std::__lg(n); i >= 0; --i) {
            if (st[i][x] != st[i][y]) {
                x = st[i][x];
                y = st[i][y];
            }
        }
        return st[0][x];
    }
    i32 dis(i32 x, i32 y) {
        du(x, y, get(x, y));
        return dep[x] + dep[y] - 2 * dep[get(x, y)];
    }
};

int32_t main() {
    i32 n, q; std::cin >> n >> q;
    vc<i32, 2> G(n + 1);
    for (i32 i = 1; i < n; ++i) {
        i32 u, v; std::cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    LCA lca(n, 1, G);
    i32 const S = std::sqrt((ld)n) + 1;
    vc<i32> q1, q2; q2.pb(1);
    vc<i32> dis(n + 1, n + 1);
    for (i32 i = 1; i <= q; ++i) {
        i32 op, x; std::cin >> op >> x;
        if (op == 1) {
            q2.pb(x);
        }
        if (op == 2) {
            i32 ans = dis[x];
            for (auto y: q2) {
                ans = std::min(ans, lca.dis(x, y));
            }
            std::cout << ans << '\n';
        }
        if (i % S == 0) {
            std::queue<i32> q;
            std::fill(dis.begin(), dis.end(), n + 1);
            q1.insert(q1.end(), q2.begin(), q2.end());
            vc<i32>().swap(q2);
            for (auto y: q1) {
                q.push(y);
                dis[y] = 0;
            }
            while (!q.empty()) {
                i32 u = q.front(); q.pop();
                for (auto v: G[u]) {
                    if (dis[v] > dis[u] + 1) {
                        dis[v] = dis[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return 0;
}
