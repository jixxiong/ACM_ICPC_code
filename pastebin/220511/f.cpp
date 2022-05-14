#include <bits/stdc++.h>

// #ifndef LOCAL_DEBUG
// __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
// #endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

bool isprime(int x){
    for(int i=2;i<=x/i;++i) if(x%i==0) return false;
    return true;
}

std::mt19937 rng(114514);

int main(){
    ll MAX_INT=1000000000000000000ll;
    std::vector<int>pm;
    for(int i=2;pm.size()<100;++i){
        if(isprime(i)) pm.pb(i);
    }
    std::vector<std::pair<int,ll>>mp;
    for(int x:pm){
        ll y=x;
        while(y<=MAX_INT/x) y*=x;
        mp.pb(std::pair<int,ll>(x,y));
    }
    int T; std::cin>>T;
    while(T--){
        ll res=1;
        auto fuk=[&](int id){
            auto [x,y]=mp[id];
            std::cout<<"? "<<y<<std::endl;
            int g; std::cin>>g;
            int c=0;
            while(g%x==0) g/=x,c++;
            res*=c+1;
        };
        for(int i=0;i<5;++i){
            fuk(i);
        }
        for(int i=5;i<22;++i){
            fuk(rng()%mp.size());
        }
        std::cout<<"! "<<res<<'\n';
    }
    return 0;
}