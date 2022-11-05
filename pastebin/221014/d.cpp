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
    vc<std::pair<i32, i32>> move_vec;
    for (i32 dx = 0; dx * dx <= m; ++dx) {
        i32 dy = (i32)std::sqrt((ld)(m - dx * dx));
        if (dy * dy + dx * dx == m) {
            move_vec.pb(dx, dy);
            move_vec.pb(dx, -dy);
            move_vec.pb(-dx, dy);
            move_vec.pb(-dx, -dy);
        }
    }
    auto f = vcc<i32>(n + 1, n + 1, -1);
    std::queue<std::tuple<i32, i32, i32>> q;
    q.push({1, 1, 0}); f[1][1] = 0;
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        for (auto [dx, dy]: move_vec) {
            i32 nx = x + dx, ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > n || f[nx][ny] != -1) continue;
            f[nx][ny] = d + 1;
            q.push({nx, ny, d + 1});
        }
    }
    for (i32 i = 1; i <= n; ++i) {
        for (i32 j = 1; j <= n; ++j) {
            std::cout << f[i][j] << " \n"[j == n];
        }
    }
    return 0;
}
