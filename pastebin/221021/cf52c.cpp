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
template<class T> T INF() { return std::numeric_limits<T>::max(); }
template<class T,i32 D=1> struct vc: std::vector<std::conditional_t<D==1,T,vc<T,D-1>>>{
    using VC = std::conditional_t<D == 1, T, vc<T, D - 1>>;
    template<class...A> vc(i32 s=0, A... a): std::vector<VC>(s, VC(a...)) { }
    template<class...A> vc(A... a): std::vector<VC>(a...) { }
};

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;

struct SGT {
    vc<i64> min, tag;
    SGT(i32 n): min(n << 2 | 3), tag(n << 2 | 3) { }
    void pushdown(i32 ni) {
        if (tag[ni]) {
            min[ni << 1] += tag[ni];
            min[ni << 1 | 1] += tag[ni];
            tag[ni << 1] += tag[ni];
            tag[ni << 1 | 1] += tag[ni];
            tag[ni] = 0;
        }
    }
    void add(i32 ni, i32 nl, i32 nr, i32 l, i32 r, i64 x) {
        if (l <= nl && nr <= r) {
            min[ni] += x;
            tag[ni] += x;
            return ;
        }
        pushdown(ni);
        i32 mid = (nl + nr) >> 1;
        if (l <= mid) add(ni << 1, nl, mid, l, r, x);
        if (r >  mid) add(ni << 1 | 1, mid + 1, nr, l, r, x);
        min[ni] = std::min(min[ni << 1], min[ni << 1 | 1]);
    }
    i64 get(i32 ni, i32 nl, i32 nr, i32 l, i32 r) {
        if (l <= nl && nr <= r) {
            return min[ni];
        }
        pushdown(ni);
        i32 mid = (nl + nr) >> 1;
        i64 ret = INF<i64>();
        if (l <= mid) ret = get(ni << 1, nl, mid, l, r);
        if (r >  mid) ret = std::min(ret, get(ni << 1 | 1, mid + 1, nr, l, r));
        return ret;
    }
};

int32_t main() {
    i32 n; std::cin >> n;
    SGT sgt(n);
    for (i32 i = 1; i <= n; ++i) {
        i32 x;
        std::cin >> x;
        sgt.add(1, 1, n, i, i, x);
    }
    i32 q; std::cin >> q;
    while (q--) {
        i32 a, b; std::cin >> a >> b; a++, b++;
        if (std::cin.get() == '\n') {
            du("1", a, b);
            if (a <= b) {
                std::cout << sgt.get(1, 1, n, a, b) << '\n';
            } else {
                std::cout << std::min(sgt.get(1, 1, n, 1, b), sgt.get(1, 1, n, a, n)) << '\n';
            }
        } else {
            i32 c; std::cin >> c;
            du("2", a, b, c);
            if (a <= b) {
                sgt.add(1, 1, n, a, b, c);
            } else {
                sgt.add(1, 1, n, 1, b, c);
                sgt.add(1, 1, n, a, n, c);
            }
        }
    }
    return 0;
}
