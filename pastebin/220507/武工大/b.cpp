#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;

int main(){
    std::vector<ld>ans(1000010);
    ans[1]=-0.57721566490153286060651209008240243104215933593992;
    for(int i=1;i<=1000000;++i){
        ans[i+1]=ans[i]+(ld)1.0/i;
    }
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::cout<<std::fixed<<std::setprecision(6)<<ans[n]<<'\n';
    }
    return 0;
}