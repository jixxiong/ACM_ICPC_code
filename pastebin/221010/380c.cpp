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
    using node = std::array<i32, 3>; // good, left, right
    vc<node> A;
    static node merge(node const& l, node const& r) {
        node ret{};
        i32 extra = std::min(l[1], r[2]);
        ret[0] = l[0] + r[0] + extra;
        ret[1] = l[1] + r[1] - extra;
        ret[2] = l[2] + r[2] - extra;
        return ret;
    }
    void pushup(i32 ni) {
        A[ni] = merge(A[ni << 1], A[ni << 1 | 1]);
    }
    void build(i32 ni, i32 nl, i32 nr, std::string const& s) {
        if (nl == nr) {
            if (s[nl] == '(') A[ni][1] = 1;
            if (s[nl] == ')') A[ni][2] = 1;
            return ;
        }
        i32 mid = (nl + nr) >> 1;
        build(ni << 1, nl, mid, s);
        build(ni << 1 | 1, mid + 1, nr, s);
        pushup(ni);
    }
    SGT(std::string const& s, i32 n): A(n << 2 | 3) {
        build(1, 1, n, s);
    }
    node query(i32 ni, i32 nl, i32 nr, i32 l, i32 r) {
        if (l <= nl && nr <= r) {
            return A[ni];
        }
        i32 mid = (nl + nr) >> 1;
        node ret{};
        if (l <= mid) ret = merge(ret, query(ni << 1, nl, mid, l, r));
        if (r >  mid) ret = merge(ret, query(ni << 1 | 1, mid + 1, nr, l, r));
        return ret;
    }
};

int32_t main() {
    std::string s; std::cin >> s;
    i32 n = s.length();
    s = ' ' + s;
    SGT sgt(s, n);
    i32 q; std::cin >> q;
    while (q--) {
        i32 l, r; std::cin >> l >> r;
        std::cout << sgt.query(1, 1, n, l, r)[0] * 2 << '\n';
    }
    return 0;
}
