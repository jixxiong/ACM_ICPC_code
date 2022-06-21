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
    int n,m; std::cin>>n>>m;
    std::vector<std::vector<int>>G(n+1);
    std::vector<std::pair<int,int>>E;
    for(int i=1;i<=m;++i){
        int u,v; std::cin>>u>>v;
        G[u].pb(v);
        E.pb(std::pair<int,int>(u,v));
    }
    std::queue<int>q;
    q.push(1);
    std::vector<int>vis(n+1,-1); vis[1]=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto v:G[u]){
            if(~vis[v]) continue;
            vis[v]=vis[u]+1;
            q.push(v);
        }
    }
    std::vector<int>tk(n+1);
    int ans=0;
    for(auto [u,v]:E){
        if(vis[u]>vis[v]) ans++;
        else if(vis[u]==vis[v]){
            tk[vis[u]]++;
        }
    }
    std::vector<int>B;
    int s=0;
    for(auto x:tk) if(x) B.pb(x),s+=x;
    std::sort(all(B),std::greater<int>());
    int t=vis[n];
    int ret=vis[n]+s;
    for(auto x:B){
        t++;
        s-=x;
        ret=std::min(t+s,ret);
    }
    std::cout<<ret+ans<<'\n';
    return 0;
}