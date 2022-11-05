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

// 双hash; O(1) 求子串 hash <= O(n) 预处理
struct DoubleHash{
    const static i32 p1=1123456969,p2=1123456793;
    const static i32 b1=233,b2=241;
    i32 n; vc<i32>pw1,pw2,f1,f2;
    DoubleHash(char* s,i32 n):n(n),pw1(n+1),pw2(n+1),f1(n+1),f2(n+1){
        pw1[0]=pw2[0]=1;
        for(i32 i=1;i<=n;++i){
            pw1[i]=(i64)pw1[i-1]*b1%p1;
            pw2[i]=(i64)pw2[i-1]*b2%p2;
            f1[i]=((i64)f1[i-1]*b1+s[i])%p1;
            f2[i]=((i64)f2[i-1]*b2+s[i])%p2;
        }
    }
    i32 get(i32 l,i32 r,i32 t){
        if(t==1) return (f1[r]-(i64)f1[l-1]*pw1[r-l+1]%p1+p1)%p1;
        else return (f2[r]-(i64)f2[l-1]*pw2[r-l+1]%p2+p2)%p2;
    }
    std::pair<i32,i32>get(i32 l,i32 r){
        return {get(l,r,1),get(l,r,2)};
    }
};

int32_t main() {
    i32 T; std::cin >> T;
    while (T--) {
        std::string s; std::cin >> s;
        i32 n = s.length();
        s = ' ' + s;
        i32 ans = 0;
        DoubleHash hash(s.data(), n);
        for (i32 i = 2; i <= n; ++i) {
            i32 l = i - 1, r = n + 1;
            while (l + 1 < r) {
                i32 mid = (l + r) >> 1;
                if (hash.get(1, mid - i + 1) == hash.get(i, mid)) l = mid;
                else r = mid;
            }
            i32 len = l - i + 1;
            ans = std::max(ans, n - len + n - i + 1 - len);
        }
        std::cout << ans << '\n';
    }
    return 0;
}
