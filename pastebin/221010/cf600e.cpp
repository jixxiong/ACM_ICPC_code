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
    i32 n; std::cin >> n;
    vc<i32> A(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> A[i];
    }
    auto G = vcc<i32>(n + 1);
    for (i32 i = 1; i < n; ++i) {
        i32 u, v; std::cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    vc<i32> L(n + 1), R(n + 1), S(n + 1);
    i32 tic = 0;
    std::function<void(i32, i32)> dfs = [&](i32 u, i32 f) -> void {
        L[u] = ++tic;
        S[tic] = u;
        for (auto v: G[u]) {
            if (v == f) continue;
            dfs(v, u);
        }
        R[u] = tic;
    };
    dfs(1, 1);
    vc<i32> Q(n + 1);
    std::iota(all(Q), 0);
    i32 const BLOCKSIZE = 500;
    std::sort(1 + all(Q), [&](i32 i, i32 j) -> bool {
        return L[i] / BLOCKSIZE == L[j] / BLOCKSIZE ? R[i] < R[j] : L[i] < L[j];
    });
    i64 sum = 0;
    i32 cur = 0;
    vc<i32> cnt(*std::max_element(1 + all(A)) + 1);
    vc<i64> tot(n + 1);
    auto del = [&](i32 x) {
        tot[cnt[x]] -= x;
        tot[--cnt[x]] += x;
        if (tot[cnt[x] + 1] == 0 && cur == cnt[x] + 1) sum = tot[cnt[x]], cur = cnt[x];
        if (tot[cnt[x] + 1] != 0 && cur == cnt[x] + 1) sum = tot[cnt[x] + 1];
    };
    auto add = [&](i32 x) {
        tot[cnt[x]] -= x;
        tot[++cnt[x]] += x;
        if (cur == cnt[x] - 1) sum = tot[cnt[x]], cur = cnt[x];
        if (cur == cnt[x]) sum = tot[cnt[x]];
    };
    vc<i64> ans(n + 1);
    for (i32 k = 1, i = 1, j = 0; k <= n; ++k) {
        i32 l = L[Q[k]], r = R[Q[k]];
        while (i > l) add(A[S[--i]]);
        while (j < r) add(A[S[++j]]);
        while (i < l) del(A[S[i++]]);
        while (j > r) del(A[S[j--]]);
        ans[Q[k]] = sum;
    }
    for (i32 i = 1; i <= n; ++i) {
        std::cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
