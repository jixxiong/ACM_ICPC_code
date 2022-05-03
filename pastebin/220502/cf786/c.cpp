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
        std::string s,t; std::cin>>s>>t;
        if(t=="a"){
            std::cout<<"1\n";
            continue;
        }
        if(t.find('a')!=t.npos){
            std::cout<<"-1\n";
            continue;
        }
        std::cout<<(1ll<<s.length())<<'\n';
    }
    return 0;
}