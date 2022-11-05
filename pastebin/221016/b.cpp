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
    std::string s;
    i32 k;
    std::cin >> s >> k;
    vc<i32> A;
    std::reverse(all(s));
    for (auto ch: s) {
        A.pb(ch ^ '0');
    }
    for (i32 _ = 1; _ <= 18; ++_) A.pb(0);
    for (i32 i = 0; i < k; ++i) {
        if (A[i] == 10) A[i] = 0, A[i + 1] += 1;
        if (A[i] <= 4) A[i] = 0;
        else A[i] = 0, A[i + 1] += 1;
    }
    for (i32 i = 1; i < (i32)A.size(); ++i) {
        if (A[i - 1] == 10) A[i - 1] = 0, A[i] += 1;
    }
    while ((i32)A.size() >= 2 && A.back() == 0) A.pop_back();
    for (auto it = A.rbegin(); it != A.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << '\n';
    return 0;
}
