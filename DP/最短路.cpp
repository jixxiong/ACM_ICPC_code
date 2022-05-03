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
    std::vector<std::vector<std::pair<int,int>>>G(n+1);
    for(int i=1;i<=m;++i){
        int u,v,d; std::cin>>u>>v>>d;
        G[v].push_back({u,d});
    }
    std::vector<int>f(n+1,0x3f3f3f3f);
    f[1]=0;
    for(int i=2;i<=n;++i){
        for(auto [v,d]:G[i]){
            f[i]=std::min(f[i],f[v]+d);
        }
    }
    std::cout<<f[n]<<'\n';
    return 0;
}