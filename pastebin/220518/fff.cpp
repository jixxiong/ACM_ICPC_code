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
    std::array<int,3>cnt{1,0,0};
    ll ret=0;
    for(int i=1,s=0,x;i<=n;++i){
        std::cin>>x; s=(s+x)%3;
        ret+=cnt[s];
        cnt[s]++;
    }
    std::cout<<ret<<'\n';
    return 0;
}