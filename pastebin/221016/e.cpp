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
    vc<i64> A(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> A[i];
    }
    vc<vc<i64>> B(m + 1);
    for (i32 i = 1; i <= n; ++i) {
        i64 x = A[i];
        i64 b = (-x + i - 1) / i;
        i64 e = (n - x) / i;
        if (b > m || e < 1) continue;
        for (i64 k = std::max(b, (i64)1); k <= std::min(e, (i64)m); ++k) {
            B[k].pb(x + i * k);
        }
    }
    for (i32 i = 1; i <= m; ++i) {
        std::sort(all(B[i]));
        B[i].erase(std::unique(all(B[i])), B[i].end());
        for (i32 j = 0; ; ++j) {
            if (j == (i32)B[i].size() || B[i][j] != j) {
                std::cout << j << '\n';
                break;
            }
        }
    }
    return 0;
}
