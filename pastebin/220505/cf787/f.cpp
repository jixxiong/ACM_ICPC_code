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
    int T; std::cin>>T;
    while(T--){
        int n,k; std::cin>>n>>k;
        int x,y; std::cin>>x>>y;
        std::vector<int>A(k);
        for(auto&x:A) std::cin>>x;
        std::vector<std::vector<int>>G(n+1);
        for(int i=1;i<n;++i){
            int u,v; std::cin>>u>>v;
            G[u].pb(v); G[v].pb(u);
        }
        std::vector<int>fa(n+1),ht(n+1);
        std::function<void(int,int)> dfs=[&](int u,int f){
            fa[u]=f;
            for(auto v:G[u]){
                if(v==f) continue;
                ht[v]=ht[u]+1;
                dfs(v,u);
            }
        };
        dfs(x,-1);
        std::queue<int>q;
        std::vector<char>vis(n+1);
        int nd=0;
        for(auto x:A) if(!vis[x]) q.push(x),vis[x]=true;
        while(!q.empty()){
            nd++;
            int u=q.front(); q.pop();
            int v=fa[u];
            if(~v){
                if(vis[v]) continue;
                vis[v]=true;
                q.push(v);
            }
        }
        int tot=(nd-1)*2+ht[y];
        while(!vis[y]) y=fa[y];
        tot-=2*ht[y];
        std::cout<<tot<<'\n';
    }
    return 0;
}