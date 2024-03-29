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

int32_t main() {
    i32 T; std::cin >> T;
    while (T--) {
        i32 n, k; std::cin >> n >> k;
        auto G = vcc<i32>(n + 1);
        for (i32 v = 2; v <= n; ++v) {
            i32 u; std::cin >> u;
            G[u].pb(v);
        }
        vc<i32> val(n + 1);
        for (i32 i = 1; i <= n; ++i) {
            std::cin >> val[i];
        }
        std::map<std::pair<i32, i32>, i64> mem;
        std::function<i64(i32, i32)> dfs = [&](i32 u, i32 k) -> i64 {
            if (mem.count({u, k})) return mem[{u, k}];
            if (k == 0) return mem[{u, k}] = 0;
            i32 tot = G[u].size();
            i64 ret = (i64)k * val[u];
            if (tot == 0) return mem[{u, k}] = ret;
            i32 avg = k / tot;
            i32 rst = k % tot;
            if (rst) {
                vc<std::array<i64, 2>> g;
                for (auto v: G[u]) {
                    g.pb(std::array<i64, 2>{dfs(v, avg), dfs(v, avg + 1)});
                }
                std::sort(all(g),
                [&](std::array<i64, 2> const& o1,
                    std::array<i64, 2> const& o2) -> bool {
                    return (o1[1] - o1[0]) > (o2[1] - o2[0]);
                });
                for (i32 i = 0; i < (i32)g.size(); ++i) {
                    ret += g[i][i < rst];
                }
            } else {
                for (auto v: G[u]) {
                    ret += dfs(v, avg);
                }
            }
            return mem[{u, k}] = ret;
        };
        std::cout << dfs(1, k) << '\n';
    }
    return 0;
}
