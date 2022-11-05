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
    auto& operator()(i32 i){ return (*this)[i]; }
    using VC = std::conditional_t<D == 1, T, vc<T, D - 1>>;
    template<class...A> vc(A... a): std::vector<VC>(a...) { }
    auto const& operator()(i32 i) const { return (*this)[i]; }
    template<class...A> vc(i32 s=0, A... a): std::vector<VC>(s, VC(a...)) { }
    template<class...A> auto& operator()(i32 i,A... a){ return (*this)[i](a...); }
    template<class...A> auto const& operator()(i32 i,A... a) const { return (*this)[i](a...); }
};

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;

template<typename T>
i32 fcmp(T x, T y = 0) {
    if (std::abs(x - y) <= EPS) return 0;
    return x < y ? -1 : 1;
}

struct node {
    ld l{}, r{};
    i64 val{};
    bool operator<(node const& o) const {
        return fcmp(l, o.l) == 0 ? fcmp(r, o.r) < 0 : fcmp(l, o.l) < 0;
    }
    bool operator>(node const& o) const {
        return fcmp(r, o.r) < 0;
    }
};

int32_t main() {
    i32 n, d; std::cin >> n >> d;
    vc<i64> W(n + 1), X(n + 1), V(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> W[i] >> X[i] >> V[i];
    }
    vc<i32> id(n + 1);
    i64 ret = 0;
    for (i32 i = 1; i <= n; ++i) {
        vc<node>Lines;
        for (i32 j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (V[i] == V[j]) {
                if (std::abs(X[i] - X[j]) > d) continue;
                Lines.pb(node{0, 1e18, W[j]});
            }
            ld t1 = (ld)(X[i] - X[j]) / (V[j] - V[i]);
            ld t2 = (ld)(X[i] - X[j] + d) / (V[j] - V[i]);
            if (fcmp(t1, t2) > 0) std::swap(t1, t2);
            if (fcmp(t2, (ld)0) < 0) continue;
            t1 = std::max((ld)0, t1);
            Lines.pb(node{t1, t2, W[j]});
        }
        if (Lines.empty()) {
            ret = std::max(ret, W[i]);
            continue;
        }
        std::sort(all(Lines));
        std::priority_queue<node, vc<node>, std::greater<node>> q;
        i64 sum = W[i];
        for (auto [l, r, w]: Lines) {
            while (!q.empty() && fcmp(q.top().r, l) < 0) {
                sum -= q.top().val;
                q.pop();
            }
            q.push(node{l, r, w});
            sum += w;
            ret = std::max(sum, ret);
        }
    }
    std::cout << ret << '\n';
    return 0;
}
