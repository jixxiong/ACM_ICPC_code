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
    std::vector<int>f(m+1);
    for(int i=1;i<=n;++i){
        int u,v,l; std::cin>>u>>v>>l;
        for(int k=1;l;l-=k,k=std::min(k<<1,l)){
            for(int j=m;j>=k*u;--j){
                f[j]=std::max(f[j],f[j-k*u]+k*v);
            }
        }
    }
    std::cout<<f[m]<<'\n';
    return 0;
}