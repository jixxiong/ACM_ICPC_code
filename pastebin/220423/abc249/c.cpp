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
    int n,m; std::cin>>n>>m;
    std::vector<std::string>A(n);
    for(int i=0;i<n;++i) std::cin>>A[i];
    int ans=0;
    for(int S=0;S<(1<<n);++S){
        std::vector<int>cnt(26);
        for(int i=0;i<n;++i){
            if((S>>i)&1){
                std::vector<char>vis(26);
                std::string& s=A[i];
                for(auto ch:s) vis[ch-'a']=true;
                for(int j=0;j<26;++j) if(vis[j]) cnt[j]++;
            }
        }
        int ret=0;
        for(int i=0;i<26;++i){
            if(cnt[i]==m){
                ret++;
                // fk((char)(i+'a'));
            }
        }
        ans=std::max(ret,ans);
    }
    std::cout<<ans<<'\n';
    return 0;
}