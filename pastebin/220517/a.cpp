#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

std::vector<ll>dijkstra(std::vector<std::vector<std::pair<int,ll>>> const& G,int n,int s){
    std::vector<ll>dis(n+1,0x3f3f3f3f3f3f3f3f);
    std::priority_queue<std::pair<ll,int>>Q;
    dis[s]=0; Q.push({0,s});
    while(!Q.empty()){
        auto [fi,u]=Q.top(); Q.pop();
        if(-fi!=dis[u]) continue;
        for(auto [v,w]:G[u])
            if(dis[v]>dis[u]+w)
                Q.push({-(dis[v]=dis[u]+w),v});
    }
    return dis;
}

int main(){
    int n,m; std::cin>>n>>m;
    std::vector<int>w(n+1);
    for(int i=2;i<n;++i) std::cin>>w[i];
    std::vector<std::vector<std::pair<int,ll>>>G(n+1);
    for(int i=1;i<=m;++i){
        int u,v,d; std::cin>>u>>v>>d;
        G[u].pb(std::pair<int,ll>{v,(ll)d+w[v]});
        G[v].pb(std::pair<int,ll>{u,(ll)d+w[u]});
    }
    std::vector<ll>d1=dijkstra(G,n,1);
    std::vector<ll>d2=dijkstra(G,n,n);
    ll ret=std::min(d1[n],d2[1]);
    for(int i=2;i<n;++i)
        ret=std::min(ret,d1[i]+d2[i]-2*w[i]);
    std::cout<<ret<<'\n';
    return 0;
}