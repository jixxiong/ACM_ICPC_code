#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
const int mod=1000000007;

int main(){
    std::vector<std::vector<int>>dp(40010,std::vector<int>(310));
    std::vector<int>f(40010);
    std::vector<int>g(40010);
    int m=300;
    int n=40000;
    f[0]=g[0]=1;
    for(int i=1;i<=m;++i){
        for(int j=0;j+j<=n;++j){
            f[i+j]=(f[i+j]+f[j])%mod;
        }
    }
    dp[m][1]=1;
    for(int i=m;i<=n;++i){
        for(int j=1;j<=m;++j){
            dp[i][j]=((ll)dp[i][j]+dp[i-j][j]+dp[i-m][j-1])%mod;
            g[i]=(g[i]+dp[i][j])%mod;
        }
    }
    // int q=12;
    int ans=0;
    for(int i=0;i<=q;++i){
        ans=(ans+(ll)g[i]*f[q-i])%mod;
    }
    std::cout<<ans<<'\n';
    return 0;
}