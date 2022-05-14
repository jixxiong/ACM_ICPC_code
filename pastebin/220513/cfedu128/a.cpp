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
        int l1,r1,l2,r2; std::cin>>l1>>r1>>l2>>r2;
        if(l1<=r2&&l2<=r1){
            std::cout<<std::max(l1,l2)<<'\n';
        }else{
            std::cout<<(l1+l2)<<'\n';
        }
    }
    return 0;
}