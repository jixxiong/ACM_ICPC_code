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
    std::map<std::string,int>mp;
    std::vector<std::vector<int>>fk;
    for(char a='a',cnt=0;a<='k';++a){
        for(char b='a';b<='k';++b){
            mp[std::string("")+a+b]=cnt++;
        }
    }
    fk.resize(mp.size());
    for(auto [__,id]:mp){
        auto s=__;
        for(char c='a';c<='k';++c){
            if(c==s[0]) continue;
            auto tmp=s[0];
            s[0]=c;
            fk[id].pb(mp[s]);
            s[0]=tmp;
        }
        for(char d='a';d<='k';++d){
            if(d==s[1]) continue;
            auto tmp=s[1];
            s[1]=d;
            fk[id].pb(mp[s]);
            s[1]=tmp;
        }
    }
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<std::string>A(n);
        for(auto& x:A) std::cin>>x;
        std::vector<int>cnt(mp.size());
        ll ret=0;
        for(int i=0;i<n;++i){
            auto id=mp[A[i]];
            for(auto p:fk[id]) ret+=cnt[p];
            cnt[id]++;
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}