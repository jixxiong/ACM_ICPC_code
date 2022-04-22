#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int T; std::cin>>T;
    while(T--){
        int l,r,k; std::cin>>l>>r>>k;
        if(l==r){
            if(l==1) std::cout<<"NO\n";
            else std::cout<<"YES\n";
            continue;
        }
        if(!(l&1))l++;
        if(!(r&1))r--;
        std::cout<<(k>=(r-l+2)/2?"YES\n":"NO\n");
    }
    return 0;
}