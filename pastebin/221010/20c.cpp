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
    i32 n, m; std::cin >> n >> m;
    auto G = vcc<std::pair<i32, i32>>(n + 1);
    for (i32 i = 1; i <= m; ++i) {
        i32 u, v, d; std::cin >> u >> v >> d;
        G[u].pb(std::pair<i32, i32>(v, d));
        G[v].pb(std::pair<i32, i32>(u, d));
    }
    std::priority_queue<std::pair<i64, i32>> q;
    vc<i64> dis(n + 1, INF<i64>());
    dis[1] = 0; q.push({0, 1});
    vc<i32> pre(n + 1);
    while (!q.empty()) {
        auto [fi, u] = q.top(); q.pop();
        if (-fi != dis[u]) continue;
        for (auto [v, d]: G[u]) {
            if (dis[v] > dis[u] + d) {
                q.push({-(dis[v] = dis[u] + d), v});
                pre[v] = u;
            }
        }
    }
    if (pre[n] == 0) {
        std::cout << "-1\n";
    } else {
        vc<i32> stk;
        for (i32 u = n; u; u = pre[u]) stk.pb(u);
        while (!stk.empty()) {
            std::cout << stk.back() << ' ';
            stk.pop_back();
        }
        std::cout << '\n';
    }
    return 0;
}
