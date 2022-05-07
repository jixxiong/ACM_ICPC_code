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
    std::vector<int>f(n+1);
    std::function<void(int)> dfs=[&](int u){
        for(auto v:G[u]){
            dfs(v);
            f[u]+=f[v];
        }
        f[u]+=1;
    };
    dfs(1);
    for(int i=1;i<=n;++i) std::cout<<f[i]<<" \n"[i==n];
    return 0;
}