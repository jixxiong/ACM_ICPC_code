#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

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

using i32=int64_t;
using i64=int64_t;
using i128=__int128;
ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

int32_t main(){
    i32 T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        vvc<i32>G(n+1);
        for(i32 i=1;i<n;++i){
            i32 u,v; std::cin>>u>>v;
            G[u].pb(v);G[v].pb(u);
        }
        vc<i32>sz(n+1);
        std::function<void(i32,i32)>dfs1=[&](i32 u,i32 f){
            sz[u]++;
            for(i32 v:G[u]){
                if(v==f) continue;
                dfs1(v,u);
                sz[u]+=sz[v];
            }
        };
        dfs1(1,1);
        vc<i64>dp(n+1);
        std::function<void(i32,i32)>dfs2=[&](i32 u,i32 f){
            i64 mx=0;
            for(i32 v:G[u]){
                if(v==f) continue;
                dfs2(v,u);
                mx=std::max(mx,dp[v]);
            }
            dp[u]=mx+sz[u];
        };
        dfs2(1,1);
        std::cout<<dp[1]<<'\n';
    }
    return 0;
}