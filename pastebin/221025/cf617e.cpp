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

struct Node {
    static i32 constexpr S = 500;
    i32 l{}, r{}, id{};
    bool operator<(Node const& o) const {
        return l / S == o.l / S ? r < o.r : l < o.l;
    }
};

int32_t main() {
    i32 n, q, k; std::cin >> n >> q >> k;
    vc<i32> A(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> A[i];
        A[i] ^= A[i - 1];
    }
    vc<Node> Q(q);
    for (i32 i = 0; i < q; ++i) {
        std::cin >> Q[i].l >> Q[i].r;
        Q[i].l--;
        Q[i].id = i;
    }
    std::sort(Q.begin(), Q.end());
    vc<i64> ans(q);
    vc<i32> cnt(1 << 21);
    i64 tot = 0;
    auto del = [&](i32 x) {
        tot -= cnt[x ^ k] - (k == 0);
        cnt[x]--;
    };
    auto add = [&](i32 x) {
        tot += cnt[x ^ k];
        cnt[x]++;
    };
    for (i32 l = 0, r = -1, i = 0; i < q; ++i) {
        auto [ql, qr, id] = Q[i];
        while (l > ql) add(A[--l]);
        while (r < qr) add(A[++r]);
        while (l < ql) del(A[l++]);
        while (r > qr) del(A[r--]);
        ans[id] = tot;
    }
    for (auto ret: ans) {
        std::cout << ret << '\n';
    }
    return 0;
}
