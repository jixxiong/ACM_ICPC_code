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
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<std::string>A(2);
        std::cin>>A[0]>>A[1];
        for(int i=0;i<2;++i) for(char& ch:A[i]) ch=ch=='*'?1:0;
        std::vector<std::vector<int>>dp(2,std::vector<int>(n+1));
        int l=-1,r=-1;
        for(int i=0;i<n;++i){
            if(A[0][i]||A[1][i]){
                if(l==-1) l=i+1;
                r=i+1;
            }
        }
        if(l==-1){
            std::cout<<"0\n";
            continue;
        }
        dp[0][l]=A[1][l-1],dp[1][l]=A[0][l-1];
        for(int i=l+1;i<=r;++i){
            dp[0][i]=std::min(dp[1][i-1]+2,dp[0][i-1]+1+A[1][i-1]);
            dp[1][i]=std::min(dp[0][i-1]+2,dp[1][i-1]+1+A[0][i-1]);
        }
        std::cout<<std::min(dp[0][r],dp[1][r])<<'\n';;
    }
    return 0;
}

/*

1
4
..**
**..

*/