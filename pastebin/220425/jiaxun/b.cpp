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
    ll h,w; std::cin>>h>>w;
    std::vector<std::pair<ll,ll>>ans;
    auto fuc1=[&](ll h,ll w){
        ll w1=(h*4+4)/5,w2=(h*5)/4;
        ll w3=std::min(w2,w);
        if(w3<w1) return;
        ans.push_back(std::pair<int,int>(h,w3));
    };
    auto fuc2=[&](ll h,ll w){
        ll h1=(w*4+4)/5,h2=(w*5)/4;
        ll h3=std::min(h2,h);
        if(h3<h1) return;
        ans.push_back(std::pair<int,int>(h3,w));
    };
    for(ll i=1;i<=h;i<<=1){
        fuc1(i,w);
    }
    for(ll i=1;i<=w;i<<=1){
        fuc2(h,i);
    }
    std::sort(all(ans),[&](const std::pair<ll,ll>&o1,const std::pair<ll,ll>&o2){
        auto [h1,w1]=o1;
        auto [h2,w2]=o2;
        if(h1*w1!=h2*w2) return h1*w1>h2*w2;
        return h1>h2;
    });
    std::cout<<ans[0].first<<' '<<ans[0].second<<'\n';
    return 0;
}