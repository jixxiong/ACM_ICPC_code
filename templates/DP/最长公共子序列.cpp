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
    std::vector<int>A(n+1),B(m+1);
    std::for_each(1+all(A),[](int&x){std::cin>>x;});
    std::for_each(1+all(B),[](int&x){std::cin>>x;});
    std::vector<std::vector<int>>f(n+1,std::vector<int>(m+1));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(A[i]==B[j])f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=std::max(f[i-1][j],f[i][j-1]);
        }
    }
    std::cout<<f[n][m]<<'\n';
    return 0;
}