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
        int n; std::cin>>n;
        std::map<int,int>mp;
        for(int i=1;i<=n;++i){
            int x; std::cin>>x;
            mp[x]++;
        }
        bool fail=true;
        for(auto [x,cnt]:mp){
            if(cnt>=3){
                std::cout<<x<<'\n';
                fail=false;
                break;
            }
        }
        if(fail){
            std::cout<<"-1\n";
        }
    }
    return 0;
}