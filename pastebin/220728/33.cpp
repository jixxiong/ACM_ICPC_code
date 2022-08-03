#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

std::pair<int,int> dij(vvc<std::pair<int,int>>&G,int n){
    vc<int>dis(n+1,0x3f3f3f3f3f3f3f3f); dis[1]=0;
    vc<int>cnt(n+1);
    std::priority_queue<std::pair<int,int>>q;
    q.push(std::pair<int,int>{0,1});;
    while(!q.empty()){
        auto t=q.top(); q.pop();
        int u=t.second;
        if(-t.first!=dis[u]) continue;
        for(auto e:G[u]){
            int v=e.first, d=e.second;
            if(dis[v]>dis[u]+d){
                dis[v]=dis[u]+d;
                cnt[v]=cnt[u]+1;
                q.push(std::pair<int,int>{-dis[v],v});
            }
        }
    }
    return std::pair<int,int>(dis[n],cnt[n]);
}

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,m; std::cin>>n>>m;
        vvc<std::pair<int,int>>G1(n+1);
        vvc<std::pair<int,int>>G2(n+1);
        int mx=1;
        for(int i=1;i<=m;++i){
            int u,v,e,p; std::cin>>u>>v>>e>>p;
            mx+=p;
            G1[u].pb(std::pair<int,int>{v,p});
            G2[u].pb(std::pair<int,int>{v,e});
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<(int)G1[i].size();++j){
                G1[i][j].second=(G2[i][j].second+2)*mx-G1[i][j].second;
            }
        }
        auto f1=dij(G1,n);
        auto f2=dij(G2,n);
        std::cout<<f2.first<<' '<<(mx-f1.first%mx)%mx<<'\n';
    }
    return 0;
}