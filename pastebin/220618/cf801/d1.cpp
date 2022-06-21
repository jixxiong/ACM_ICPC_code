#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define er(args...) void()
#else
    #define vwn(x) #x"=",x,"\n"
    void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
    #define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<std::vector<int>>G(n+1);
        for(int i=1;i<n;++i){
            int u,v; std::cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        if(n==1){
            std::cout<<"0\n";
            continue;
        }
        int ret=n;
        for(int i=1;i<=n;++i){
            std::vector<int>ht(n+1);
            std::vector<int>vis(n+1);
            std::function<void(int,int)>dfs=[&](int u,int fa){
                if(u!=i&&G[u].size()==1){
                    vis[u]=true;
                }
                for(auto v:G[u]){
                    if(v==fa) continue;
                    ht[v]=ht[u]+1;
                    dfs(v,u);
                }
            };
            ht[i]=1;
            dfs(i,i);
            std::vector<int>cnt(n+1);
            for(int j=1;j<=n;++j){
                if(vis[j]) cnt[ht[j]]++;
            }
            int c=0;
            int cz=0;
            for(int j=1;j<=n;++j){
                if(cnt[j]>=1) c+=std::max(cnt[j]-1,1);
                if(cnt[j]==1) cz++;
            }
            if(cz<1) c++;
            // std::cout<<i<<' '<<cz<<' '<<c<<'\n';
            ret=std::min(c,ret);
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}