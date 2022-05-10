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
    std::vector<ll>ans;
    std::vector<ll>pm;
    std::vector<char>vis(1000010);
    [&](){
        for(int i=2;i<=1000000;++i){
            if(!vis[i]){
                pm.pb(i);
                for(int j=i;j<=1000000;j+=i) vis[j]=true;
            }
        }
        for(int i=0;i<(int)pm.size();++i){
            for(int j=i+1;j<(int)pm.size();++j){
                if(pm[i]*pm[j]>1000000000000000000/(pm[j]*pm[j])) break;
                ans.pb(pm[i]*pm[j]*pm[j]*pm[j]);
            }
        }
        std::sort(all(ans));
    }();
    ll n; std::cin>>n;
    std::cout<<(std::upper_bound(all(ans),n)-ans.begin())<<'\n';
    return 0;
}