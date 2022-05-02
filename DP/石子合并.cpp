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
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    std::vector<std::vector<int>>f(n+1,std::vector<int>(n+1,0x3f3f3f3f));
    for(int i=1;i<=n;++i) f[i][i]=A[i];
    for(int k=2;k<=n;++k){
        for(int i=1;i<=n-k+1;++i){
            for(int j=i;j<i+k-1;++j){
                f[i][i+k-1]=std::min(f[i][i+k-1],f[i][j]+f[j+1][i+k-1]);
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            std::cout<<f[i][j]<<" \n"[j==n];
        }
    }
    std::cout<<f[1][n]<<'\n';
    return 0;
}