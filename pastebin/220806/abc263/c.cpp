#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;
using i32=int32_t;
using i64=int64_t;
using i128=__int128;

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

int32_t main(){
    i32 n,L,R; std::cin>>n>>L>>R;
    vc<i32>A(n+1);
    for(i32 i=1;i<=n;++i){
        std::cin>>A[i];
    }
    vc<i64>f(n+1);
    for(i32 i=1;i<=n;++i){
        f[i]=std::min(f[i-1]+A[i],(i64)L*i);
    }
    vc<i64>g(n+2);
    for(i32 i=n;i>=1;--i){
        g[i]=std::min(g[i+1]+A[i],(i64)R*(n-i+1));
    }
    i64 ret=std::min({(i64)L*n,(i64)R*n});
    for(i32 i=1;i<n;++i){
        ret=std::min(ret,f[i]+g[i+1]);
    }
    std::cout<<ret<<'\n';
    return 0;
}