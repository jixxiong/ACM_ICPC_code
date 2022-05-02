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
    int n,m,o; std::cin>>n>>m>>o;
    std::vector<std::vector<int>>f(m+1,std::vector<int>(o+1));
    for(int i=1;i<=n;++i){
        int v,w,t; std::cin>>v>>w>>t;
        for(int j=m;j>=v;--j){
            for(int k=o;k>=t;--k){
                f[j][k]=std::max(f[j][k],f[j-v][k-t]+w);
            }
        }
    }
    std::cout<<f[m][o]<<'\n';
    return 0;
}