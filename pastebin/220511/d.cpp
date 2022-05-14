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
    int n,s; std::cin>>n>>s;
    if(s<2*n){
        std::cout<<"NO"<<'\n';
        return 0;
    }
    std::cout<<"YES"<<'\n';
    for(int i=1;i<n;++i) std::cout<<"1 ";
    std::cout<<(s-(n-1))<<'\n';
    std::cout<<(s/2)<<'\n';
    return 0;
}