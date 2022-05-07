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
        std::vector<int>A(m+1);
        for(int j=1;j<=m;++j) std::cin>>A[j];
        for(int j=m;j>=1;--j){
            for(int k=1;k<=j;++k){
                f[j]=std::max(f[j],f[j-k]+A[k]);
            }
        }
    }
    std::cout<<f[m]<<'\n';
    return 0;
}