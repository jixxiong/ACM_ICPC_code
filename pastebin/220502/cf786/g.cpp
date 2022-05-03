#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int n,m; std::cin>>n>>m;
    std::vector<std::vector<int>>G(n+1);
    std::vector<int>ind(n+1),oud(n+1);
    for(int i=1;i<=m;++i){
        int u,v; std::cin>>u>>v;
        G[u].push_back(v);
        ind[v]++,oud[u]++;
    }
    std::vector<char>no_out(n+1),no_in(n+1);
    for(int i=1;i<=n;++i){
        if(ind[i]<2)no_in[i]=true;
        if(oud[i]<2)no_out[i]=true;
    }
    std::vector<char>vis(n+1);
    std::vector<int>dp(n+1);
    std::function<void(int)>dfs=[&](int u){
        if(vis[u]) return ;
        vis[u]=true;
        int pt=0;
        if(!no_out[u]){
            for(auto v:G[u]){
                if(no_in[v]) continue;
                dfs(v);
                pt=std::max(pt,dp[v]);
            }
        }
        dp[u]=pt+1;
    };
    for(int i=1;i<=n;++i){
        dfs(i);
    }
    std::cout<<std::accumulate(all(dp),1,[](int x,int y){return std::max(x,y); })<<'\n';
    return 0;
}