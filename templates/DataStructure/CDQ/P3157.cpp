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
template<class T>T INF(){ return std::numeric_limits<T>::max(); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;

struct node {
    i32 x{}, y{}, z{}, tag{}, *ans{};
};

int32_t main(){
    i32 n, m; std::cin >> n >> m;
    vc<i32> ori(n + 1);
    vc<i32> pos(n + 1);
    vc<node> A(n + 1), B(n + 1), C(n + 1);
    vc<i32> ans(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> ori[i];
        pos[ori[i]] = i;
        A[i].x = n + 1;
        A[i].y = i;
        A[i].z = ori[i];
        A[i].ans = ans.data() + i;
    }
    vc<i32> to_del(m + 1);
    for (i32 i = 1; i <= m; ++i) {
        std::cin >> to_del[i];
        A[pos[to_del[i]]].x = i;
    }
    std::sort(1 + all(A), [&](node const& o1, node const& o2) -> bool {
        return o1.x > o2.x;
    });
    std::function<bool(node const&, node const&)> cmp1 =
        [](node const& o1, node const& o2) {
            return o1.y <= o2.y;
        };
    std::function<bool(node const&, node const&)> cmp2 =
        [](node const& o1, node const& o2) {
            return o1.z >= o2.z;
        };
    std::function<void(i32, i32)> dfs2 = [&](i32 l, i32 r) -> void {
        if (l >= r) return ;
        i32 mid = (l + r) >> 1;
        dfs2(l, mid);
        dfs2(mid + 1, r);
        for (i32 i = l, j = l, k = mid + 1, cnt = 0; i <= r; ++i) {
            if ((j <= mid) && (k > r || cmp2(B[j], B[k]))) {
                C[i] = B[j++];
                cnt += C[i].tag;
            } else {
                C[i] = B[k++];
                if (!C[i].tag) *C[i].ans += cnt;
            }
        }
        for (i32 i = l; i <= r; ++i) {
            B[i] = C[i];
        }
    };
    std::function<void(i32, i32)> dfs1 = [&](i32 l, i32 r) -> void {
        if (l >= r) return ;
        i32 mid = (l + r) >> 1;
        dfs1(l, mid);
        dfs1(mid + 1, r);
        for (i32 i = l, j = l, k = mid + 1; i <= r; ++i) {
            if ((j <= mid) && (k > r || cmp1(A[j], A[k]))) {
                B[i] = A[j++];
                B[i].tag = 1;
            } else {
                B[i] = A[k++];
                B[i].tag = 0;
            }
        }
        for(i32 i = l; i <= r; ++i) {
            A[i] = B[i];
        }
        dfs2(l, r);
    };
    // for each i count the number of j
    // where A[j].x > A[i].x, A[j].y < A[i].y, A[j].z > A[i].z
    dfs1(1, (i32)n);
    std::sort(1 + all(A), [&](node const& o1, node const& o2) -> bool {
        return o1.x > o2.x;
    });
    cmp1 = [](node const& o1, node const& o2) { return o1.y >= o2.y; };
    cmp2 = [](node const& o1, node const& o2) { return o1.z <= o2.z; };
    // for each i count the number of j
    // where A[j].x > A[i].x, A[j].y > A[i].y, A[j].z < A[i].z
    dfs1(1, (i32)n);
    std::sort(1 + all(A), [&](node const& o1, node const& o2) -> bool {
        return o1.y < o2.y;
    });
    std::function<i64(i32, i32)> msort=[&](i32 l, i32 r) -> i64 {
        if (l >= r) return 0;
        i64 res = 0;
        i32 mid = (l + r) >> 1;
        res += msort(l, mid);
        res += msort(mid + 1, r);
        for (i32 i = l, j = l, k = mid + 1; i <= r; ++i) {
            if ((j <= mid) && (k > r || (cmp2(A[j], A[k])))) {
                B[i] = A[j++];
            } else {
                B[i] = A[k++];
                res += mid - j + 1;
            }
        }
        for (i32 i = l; i <= r; ++ i) {
            A[i] = B[i];
        }
        return res;
    };
    i64 ret = msort(1, n);
    std::sort(1 + all(A), [&](node const& o1, node const& o2) -> bool {
        return o1.x < o2.x;
    });
    for (i32 i = 1; i <= m; ++i) {
        std::cout << ret << '\n';
        ret -= *A[i].ans;
    }
    return 0;
}
