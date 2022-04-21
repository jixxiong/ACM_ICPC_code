#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    int n,m,T; std::cin>>n>>m>>T;
    std::vector<int>w(n+1);
    for(int i=2;i<=n;++i){
        std::cin>>w[i];
    }
    std::vector<std::vector<std::pair<int,int>>>G(n+1);
    for(int i=1;i<=n;++i) G[i].reserve(256);
    for(int i=1;i<=m;++i){
        int u,v,t; std::cin>>u>>v>>t;
        G[u].emplace_back(std::pair<int,int>(v,t));
        G[v].emplace_back(std::pair<int,int>(u,t));
    }
    std::vector<int>dis(n+1,0x3f3f3f3f);
    std::priority_queue<std::pair<int,int>>pq;
    dis[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [fi,u]=pq.top(); pq.pop();
        if(-fi!=dis[u]) continue;
        for(const auto& [v,t]:G[u])
            if(dis[u]+t<dis[v])
                pq.push({-(dis[v]=dis[u]+t),v});
    }
    for(int i=2;i<=n;++i) dis[i]<<=1;
    std::vector<int>f(T+1);
    for(int i=2;i<=n;++i)
        for(int j=T;j>=dis[i];--j)
            f[j]=std::max(f[j],f[j-dis[i]]+w[i]);
    std::cout<<f[T]<<'\n';
    return 0;
}