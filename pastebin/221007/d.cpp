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
template<class T>using vc    =std::vector<T>;
template<class T>using vvc   =vc<vc<T>>;
template<class T>using vvvc  =vc<vvc<T>>;
template<class T>using vvvvc =vc<vvvc<T>>;
template<class T>using vvvvvc=vc<vvvvc<T>>;
template<class T> auto vcc   (i32 _1=0,i32 _2=0,const T&init=T()){ return vvc<T>(_1,vc<T>(_2,init)); }
template<class T> auto vccc  (i32 _1=0,i32 _2=0,i32 _3=0,const T&init=T()){ return vvvc<T>(_1,vcc(_2,_3,init)); }
template<class T> auto vcccc (i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,const T&init=T()){ return vvvvc<T>(_1,vccc(_2,_3,_4,init)); }
template<class T> auto vccccc(i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,i32 _5=0,const T&init=T()){ return vvvvvc<T>(_1,vcccc(_2,_3,_4,_5,init)); }
template<class T> T INF() { return std::numeric_limits<T>::max(); }

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;

struct edge {
    i32 u{}, v{};
    i64 d{};
};

int32_t main() {
    i32 T; std::cin >> T;
    while (T--) {
        i32 n, m; std::cin >> n >> m;
        vc<edge> E(m);
        auto G = vcc<i32>(n + 1, n + 1, 0x3f3f3f3f);
        for (i32 i = 1; i <= n; ++i) {
            G[i][i] = 0;
        }
        for (i32 i = 0; i < m; ++i) {
            std::cin >> E[i].u >> E[i].v >> E[i].d;
            if (E[i].u > E[i].v) std::swap(E[i].u, E[i].v);
            G[E[i].u][E[i].v] = G[E[i].v][E[i].u] = 1;
        }
        for (i32 k = 1; k <= n; ++k) {
            for (i32 i = 1; i <= n; ++i) {
                for (i32 j = 1; j <= n; ++j) {
                    if (G[i][k] + G[k][j] < G[i][j]) {
                        G[i][j] = G[i][k] + G[k][j];
                    }
                }
            }
        }
        i64 ans = INF<i64>();
        for (auto [u, v, d]: E) {
            if (u == 1 && v == n) {
                ans = std::min(ans, d);
            } if (u == 1) {
                i32 d1 = G[v][n];
                ans = std::min(ans, d * (1 + d1));
            } if (v == n) {
                i32 d1 = G[u][1];
                ans = std::min(ans, d * (1 + d1));
            } else {
                for (i32 i = 2; i < n; ++i) {
                    i32 d1;
                    if (u == i || v == i || G[u][i] == G[v][i]) {
                        d1 = G[u][i];
                    } else {
                        d1 = std::max(G[u][i], G[v][i]);
                    }
                    ans = std::min(ans, d * (1 + d1 + std::min({G[v][1], G[u][1], G[i][1]}) + std::min({G[v][n], G[u][n], G[i][n]})));
                }
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
