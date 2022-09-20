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
    int n; std::cin>>n;
    std::vector<std::vector<int>>G(n+1);
    for(int i=2;i<=n;++i){
        int fa; std::cin>>fa;
        G[fa].pb(i);
    }
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    std::vector<std::array<ll,2>>f(n+1,std::array<ll,2>{});
    std::function<void(int)>dfs=[&](int u){
        for(auto v:G[u]){
            dfs(v);
            f[u][0]+=std::max(f[v][0],f[v][1]);
            f[u][1]+=f[v][0];
        }
        f[u][1]+=A[u];
    };
    dfs(1);
    std::cout<<std::max(f[1][0],f[1][1])<<'\n';
    return 0;
}