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
    int n,m,k;
    std::cin>>n>>m>>k;
    std::cout<<((ll)n*(n+1)/2)%mod*(k-1)%mod*(m-k+1)%mod<<'\n';
    return 0;
}