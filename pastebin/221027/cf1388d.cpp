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

int32_t main() {
    i32 n; std::cin >> n;
    vc<i32> A(n + 1), B(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> A[i];
    }
    vc<i32, 2> G(n + 1);
    vc<i32> ind(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> B[i];
        if (~B[i]) ind[B[i]]++;
    }
    std::queue<i32> q;
    for (i32 i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    vc<i64> s(n + 1);
    while (!q.empty()) {
        i32 u = q.front(); q.pop();
        i32 v = B[u];
        if (~v) {
            
        }
    }
    return 0;
}
