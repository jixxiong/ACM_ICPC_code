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
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    std::vector<int>f(m+1);
    f[0]=1;
    const int mod=1000007;
    for(int i=1;i<=n;++i){
        auto g=f; std::fill(all(f),0);
        for(int j=0;j<=m;++j){
            for(int k=0;k<=std::min(j,A[i]);++k){
                f[j]=(f[j]+g[j-k])%mod;
            }
        }
    }
    std::cout<<f[m]<<'\n';
    return 0;
}