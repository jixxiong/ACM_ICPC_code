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
        int x,y;std::cin>>x>>y;
        std::vector<int>ret;
        while(y!=1){
            ret.pb(x/y);
            auto tmp=x;
            x=y;
            y=tmp%y;
        }
        ret.pb(x);
        std::cout<<(int)ret.size()-1;
        for(auto x:ret) std::cout<<' '<<x;
        std::cout<<'\n';
    }
    return 0;
}