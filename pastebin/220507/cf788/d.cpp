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
    std::vector<int>fuk{0,0};
    [&](){
        int i=0,j=1;
        while(i<=1000000000){
            if(j&1){
                i+=j*2;
                fuk.pb(i);
            }else{
                i+=j*2;
                fuk.pb(i);
                i+=j*2;
                fuk.pb(i);
            }
            j++;
        }
    }();
    int T; std::cin>>T;
    while(T--){
        int x; std::cin>>x;
        std::cout<<(std::lower_bound(all(fuk),x)-fuk.begin())<<'\n';
    }
    return 0;
}