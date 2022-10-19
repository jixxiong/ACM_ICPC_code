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

// 求前缀子串的最大 border
struct Next:vc<i32>{
    // 构建 next 数组 O(n)
    Next(const char* s,i32 n):vc<i32>(n+1){
        auto&p=*this;
        for(int i=2,j=0;i<=n;++i){
            while(j&&s[i]!=s[j+1]) j=p[j];
            if(s[i]==s[j+1]) j++;
            p[i]=j;
        }
    }
};

int32_t main() {
    std::string s; std::cin >> s;
    i32 n = s.length();
    s = ' ' + s;
    Next nxt(s.data(), n);
    vc<i32> cnt(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        cnt[nxt[i]]++;
    }
    auto G = vcc<i32>(n + 1);
    for (i32 i = 1; i <= n; ++i) {
        if (nxt[i]) {
            G[nxt[nxt[i]]].pb(nxt[i]);
        }
    }
    for (i32 i = 0; i <= n; ++i) {
        std::sort(all(G[i]));
        G[i].erase(std::unique(all(G[i])), G[i].end());
    }
    std::function<void(i32)> dfs = [&](i32 u) -> void{
        for (auto v: G[u]) {
            du(u, v);
            dfs(v);
            cnt[u] += cnt[v];
        }
    };
    dfs(0);
    vc<std::tuple<i32, i32>>ans;
    for (i32 u = nxt[n]; u; u = nxt[u]) {
        ans.pb(u, cnt[u] + 1);
    }
    std::reverse(all(ans));
    std::cout << ans.size() + 1 << '\n';
    for (auto [p, c]: ans) {
        std::cout << p << ' ' << c << '\n';
    }
    std::cout << n << ' ' << 1 << '\n';
    return 0;
}
