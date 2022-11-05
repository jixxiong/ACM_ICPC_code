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
    i64 h, w, x, y; std::cin >> h >> w >> x >> y;
    auto rows = std::map<i64, vc<i64>>();
    auto cols = std::map<i64, vc<i64>>();
    i32 n; std::cin >> n;
    for (i32 i = 1; i <= n; ++i) {
        i64 bx, by; std::cin >> bx >> by;
        rows[bx].pb(by);
        cols[by].pb(bx);
    }
    for (auto& [_, vec]: rows) {
        vec.pb(0), vec.pb(w + 1);
        std::sort(all(vec));
    }
    for (auto& [_, vec]: cols) {
        vec.pb(0), vec.pb(h + 1);
        std::sort(all(vec));
    }
    i32 q; std::cin >> q;
    while (q--) {
        char dir;
        i64 rep;
        std::cin >> dir >> rep;
        rep = std::min(rep, std::max(h, w));
        if (dir == 'U') {
            if (!cols.count(y)) {
                cols[y] = {0, h + 1};
            }
            auto xp = *std::upper_bound(cols[y].rbegin(), cols[y].rend(), x, std::greater<i64>());
            x = std::max(xp + 1, x - rep);
        }
        if (dir == 'D') {
            if (!cols.count(y)) {
                cols[y] = {0, h + 1};
            }
            auto xp = *std::upper_bound(cols[y].begin(), cols[y].end(), x, std::less<i64>());
            x = std::min(xp - 1, x + rep);
        }
        if (dir == 'L') {
            if (!rows.count(x)) {
                rows[x] = {0, w + 1};
            }
            auto yp = *std::upper_bound(rows[x].rbegin(), rows[x].rend(), y, std::greater<i64>());
            y = std::max(yp + 1, y - rep);
        }
        if (dir == 'R') {
            if (!rows.count(x)) {
                rows[x] = {0, w + 1};
            }
            auto yp = *std::upper_bound(rows[x].begin(), rows[x].end(), y, std::less<i64>());
            y = std::min(yp - 1, y + rep);
        }
        assert(x >= 1 && x <= h && y >= 1 && y <= w);
        std::cout << x << ' ' << y << '\n';
    }
    return 0;
}
