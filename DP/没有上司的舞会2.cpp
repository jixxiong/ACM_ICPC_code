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
    // 二维树上分组背包
    int n,m; std::cin>>n>>m;
    std::vector<std::vector<int>>G(n+1);
    for(int i=2;i<=n;++i){
        int fa; std::cin>>fa;
        G[fa].pb(i);
    }
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    std::vector<std::vector<std::vector<int>>>f(n+1,
        std::vector<std::vector<int>>(m+1,
            std::vector<int>(2)));
    std::function<void(int)>dfs=[&](int u){
        for(auto v:G[u]){
            dfs(v);
            for(int i=m;i>=0;--i){
                for(int j=0;j<=i;++j){
                    f[u][i][0]=std::max(f[u][i][0],f[u][i-j][0]+std::max(f[v][j][1],f[v][j][0]));
                    f[u][i][1]=std::max(f[u][i][1],f[u][i-j][1]+f[v][j][0]);
                }
            }
        }
        for(int i=m;i>=1;--i) f[u][i][1]=f[u][i-1][1]+A[u];
    };
    dfs(1);
    std::cout<<std::max(f[1][m][0],f[1][m][1])<<'\n';
    return 0;
}