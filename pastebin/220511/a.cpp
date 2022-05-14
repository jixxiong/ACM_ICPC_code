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
        ll x,k; std::cin>>x>>k;
        auto fun=[](ll x){
            ll min=x%10,max=x%10;
            while(x){
                auto ch=x%10;
                x/=10;
                min=std::min(min,ch);
                max=std::max(max,ch);
            }
            return min*max;
        };
        while(--k){
            auto y=fun(x);
            if(y==0) break;
            x+=y;
        }
        std::cout<<x<<'\n';
    }
    return 0;
}