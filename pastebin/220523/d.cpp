#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
ll const INF=9000000000000000000ll;

int main(){
    ll n,x; std::cin>>n>>x;
    std::set<ll>st;
    auto ctr=[](ll x){
        std::array<int,10>cnt{};
        int bs=0;
        if(x==0) bs=cnt[0]=1;
        while(x) cnt[x%10]++,x/=10,bs++;
        return std::pair<int,std::array<int,10>>{bs,cnt};
    };
    std::queue<std::pair<ll,int>>q; q.push({x,0}); st.insert(x);
    while(!q.empty()){
        auto [u,s]=q.front(); q.pop();
        auto [bs,cnt]=ctr(u);
        if(bs==n){
            std::cout<<s<<'\n';
            return 0;
        }
        if(bs>n||u==0)
            continue;
        for(int i=0;i<=9;++i){
            if(cnt[i]&&i<=INF/u&&!st.count(i*u)){
                st.insert(i*u);
                q.push({i*u,s+1});
            }
        }
    }
    std::cout<<"-1\n";
    return 0;
}