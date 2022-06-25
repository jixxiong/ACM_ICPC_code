#include<iostream>
#include<vector>
#include<utility>
#include<queue>

__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#define ll long long

std::vector<std::pair<int,int> > G[50010];
std::priority_queue<std::pair<int,int> >q;
int dis[50010];
int val[50010];

int main(){
    for(int i=1;i<=50000;++i) G[i].reserve(128);
    int T; std::cin>>T;
    while(T--){
        int n, m; std::cin>>n>>m;
        for(int i=1;i<=n;++i) G[i].resize(0);
        for(int i=1;i<=n;++i) std::cin>>val[i];
        for(int i=1;i<=m;++i){
            int u,v,d; std::cin>>u>>v>>d;
            G[u].push_back({v,d});
            G[v].push_back({u,d});
        }
        std::fill_n(dis+1,n,0x3f3f3f3f);
        dis[1]=0; q.push({0,1});
        while(!q.empty()){
            std::pair<int,int> front=q.top(); q.pop();
            if(-front.first != dis[front.second]) continue;
            int u = front.second;
            for(int i=0,sz=(int)G[u].size();i<sz;++i){
                std::pair<int,int> e=G[u][i];
                int v=e.first,d=e.second;
                if(dis[v]>dis[u]+d) q.push({-(dis[v]=dis[u]+d),v});
            }
        }
        ll ret=0;
        for(int i=1;i<=n;++i){
            ret+=(ll)val[i]*dis[i];
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}