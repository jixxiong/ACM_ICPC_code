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

struct SGT {
    vc<i32> max; vc<i64> sum;
    SGT(i32 n): max(n << 2 | 3), sum(n << 2 | 3) { }
    void pushup(i32 ni){
        max[ni] = std::max(max[ni << 1], max[ni << 1 | 1]);
        sum[ni] = sum[ni << 1] + sum[ni << 1 | 1];
    }
    void set(i32 ni, i32 nl, i32 nr, i32 x, i32 v) {
        if (nl == nr) {
            max[ni] = sum[ni] = v;
            return ;
        }
        i32 mid = (nl + nr) >> 1;
        if (x <= mid) set(ni << 1, nl, mid, x, v);
        else set(ni << 1 | 1, mid + 1, nr, x, v);
        pushup(ni);
    }
    i64 get(i32 ni, i32 nl, i32 nr, i32 l, i32 r) {
        if (l <= nl && nr <= r) {
            return sum[ni];
        }
        i32 mid = (nl + nr) >> 1;
        i64 ret = 0;
        if (l <= mid) ret += get(ni << 1, nl, mid, l, r);
        if (r >  mid) ret += get(ni << 1 | 1, mid + 1, nr, l, r);
        return ret;
    }
    void mod(i32 ni, i32 nl, i32 nr, i32 l, i32 r, i32 x) {
        if (max[ni] < x) return ;
        if (nl == nr) {
            max[ni] = sum[ni] = max[ni] % x;
            return ;
        }
        i32 mid = (nl + nr) >> 1;
        if (l <= mid) mod(ni << 1, nl, mid, l, r, x);
        if (r >  mid) mod(ni << 1 | 1, mid + 1, nr, l, r, x);
        pushup(ni);
    }
};

int32_t main() {
    i32 n, q; std::cin >> n >> q;
    SGT sgt(n);
    for (i32 i = 1; i <= n; ++i) {
        i32 x; std::cin >> x;
        sgt.set(1, 1, n, i, x);
    }
    while (q--) {
        i32 op; std::cin >> op;
        if (op == 1) {
            i32 l, r; std::cin >> l >> r;
            std::cout << sgt.get(1, 1, n, l, r) << '\n';
        }
        if (op == 2) {
            i32 l, r, x; std::cin >> l >> r >> x;
            sgt.mod(1, 1, n, l, r, x);
        }
        if (op == 3) {
            i32 x, v; std::cin >> x >> v;
            sgt.set(1, 1, n, x, v);
        }
    }
    return 0;
}
