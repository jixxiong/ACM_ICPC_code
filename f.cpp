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
template<class T>T INF(){ return std::numeric_limits<T>::max(); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;

struct edge {
    i32 u{}, v{};
    i64 w{};
    i32 tag{};
    bool operator<(edge const& o) const {
        return w < o.w;
    }
};

struct DSU : vc<i32> {
    DSU(i32 n): vc<i32>(n + 1) {
        std::iota(begin(),end(),0);
    }
    i32 get(i32 x) {
        return (*this)[x] == x ? x : ((*this)[x] = get((*this)[x]));
    }
    void merge(i32 x, i32 y) {
        x = get(x), y = get(y);
        if (x != y) (*this)[x] = y;
    }
};

int32_t main(){
    i32 n, m; std::cin >> n >> m;
    vc<i32> X(n + 1), Y(n + 1);
    vc<edge> E;
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> X[i];
        E.pb(edge{i, n + 1, X[i], 1});
    }
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> Y[i];
        E.pb(edge{i, n + 2, Y[i], 2});
    }
    for (i32 i = 1; i <= m; ++i) {
        i32 u, v, w; std::cin >> u >> v >> w;
        E.pb(edge{u, v, w, 0});
    }
    std::sort(all(E));
    auto solve = [&](i32 tp) -> i64 {
        DSU dsu(n + 2);
        i64 ret = 0;
        i32 cnt = 0;
        for (auto [u, v, w, tag]: E) {
            if (dsu.get(u) == dsu.get(v) || (tag & tp)) continue;
            dsu.merge(u, v);
            ret += w;
            cnt++;
        }
        if ((2 - __builtin_popcount(tp)) + n - 1 == cnt) return ret;
        else return (i64)0x3f3f3f3f3f3f3f3f;
    };
    std::cout << std::min({solve(0), solve(1), solve(2), solve(3)}) << '\n';
    return 0;
}
