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
    std::vector<ll>A;
    for(int i=1;i<=n/i;++i){
        A.pb((ll)i*i);
    }
    std::cout<<A.size();
    for(auto x:A) std::cout<<' '<<x;
    std::cout<<'\n';
    return 0;
}