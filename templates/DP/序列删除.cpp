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
    std::vector<std::vector<int>>f(n+2,std::vector<int>(n+2,0));
    for(int i=2;i<=n-1;++i)f[i][i]=A[i]*A[i-1]*A[i+1];
    for(int l=2;l<=n-2;++l){
        for(int i=2;i+l-1<=n-1;++i){
            int j=i+l-1;
            f[i][j]=0x3f3f3f3f;
            for(int k=i;k<=j;++k){
                f[i][j]=std::min(f[i][j],f[i][k-1]+f[k+1][j]+A[k]*A[i-1]*A[j+1]);
            }
        }
    }
    std::cout<<f[2][n-1]<<'\n';
    return 0;
}