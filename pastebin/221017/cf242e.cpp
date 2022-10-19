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

struct SGT {
    i32 const MB = 25;
    vvc<i32>s;
    vvc<char>t;
    SGT(i32 n): s(MB, vc<i32>(n << 2 | 3)), t(MB, vc<char>(n << 2 | 3)) { }
    void pushup(i32 ni) {
        for (i32 i = 0; i < MB; ++i) {
            s[i][ni] = s[i][ni << 1] + s[i][ni << 1 | 1];
        }
    }
    void pushdown(i32 ni, i32 l1, i32 l2) {
        for (i32 i = 0; i < MB; ++i) {
            if (t[i][ni]) {
                t[i][ni << 1] ^= 1;
                t[i][ni << 1 | 1] ^= 1;
                s[i][ni << 1] = l1 - s[i][ni << 1];
                s[i][ni << 1 | 1] = l2 - s[i][ni << 1 | 1];
                t[i][ni] = false;
            }
        }
    }
    void XOR(i32 ni, i32 nl, i32 nr, i32 l, i32 r, i32 x) {
        if (l <= nl && nr <= r) {
            for (i32 i = 0; i < MB; ++i) {
                if ((x >> i) & 1) {
                    s[i][ni] = nr - nl + 1 - s[i][ni];
                    t[i][ni] ^= 1;
                }
            }
            return ;
        }
        i32 mid = (nl + nr) >> 1;
        pushdown(ni, mid - nl + 1, nr - mid);
        if (l <= mid) XOR(ni << 1, nl, mid, l, r, x);
        if (r >  mid) XOR(ni << 1 | 1, mid + 1, nr, l, r, x);
        pushup(ni);
    }
    i64 get(i32 ni, i32 nl, i32 nr, i32 l, i32 r) {
        if (l <= nl && nr <= r) {
            i64 ret = 0;
            for (i32 i = 0; i < MB; ++i) {
                ret += s[i][ni] * (1ll << i);
            }
            return ret;
        }
        i32 mid = (nl + nr) >> 1;
        pushdown(ni, mid - nl + 1, nr - mid);
        i64 ret = 0;
        if (l <= mid) ret += get(ni << 1, nl, mid, l, r);
        if (r >  mid) ret += get(ni << 1 | 1, mid + 1, nr, l, r);
        return ret;
    }
};

int32_t main() {
    i32 n; std::cin >> n;
    SGT sgt(n);
    for (i32 i = 1; i <= n; ++i) {
        i32 x; std::cin >> x;
        sgt.XOR(1, 1, n, i, i, x);
    }
    i32 q; std::cin >> q;
    while (q--) {
        i32 op; std::cin >> op;
        if (op == 1) {
            i32 l, r; std::cin >> l >> r;
            std::cout << sgt.get(1, 1, n, l, r) << '\n';
        } else {
            i32 l, r, x; std::cin >> l >> r >> x;
            sgt.XOR(1, 1, n, l, r, x);
        }
    }
    return 0;
}
