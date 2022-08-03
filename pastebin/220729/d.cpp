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

int32_t main(){
    int n,m,s,t; std::cin>>n>>m>>s>>t;
    vvc<int>G(n+1);
    vvc<char>g(n+1,vc<char>(n+1));
    for(int i=1;i<=m;++i){
        int u,v; std::cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
        g[u][v]=g[v][u]=true;
    }
    auto bfs=[&](int s){
        vc<int>lv(n+1);
        vc<char>vis(n+1);
        std::queue<int>q;
        vis[s]=true;
        q.push(s);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto v:G[u]){
                if(vis[v]) continue;
                vis[v]=true;
                q.push(v);
                lv[v]=lv[u]+1;
            }
        }
        return lv;
    };
    auto lv1=bfs(s);
    auto lv2=bfs(t);
    int tot=lv1[t];
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(g[i][j]) continue;
            if(lv1[i]+lv2[j]+1<tot||lv2[i]+lv1[j]+1<tot) continue;
            ans++;
        }
    }
    std::cout<<ans<<'\n';
    return 0;
}