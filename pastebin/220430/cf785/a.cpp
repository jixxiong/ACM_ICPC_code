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
        std::string s; std::cin>>s;
        int s1=0,s2=0;
        for(auto ch:s) s1+=ch-'a'+1;
        if(s.length()&1){
            s2=std::min(s[0],s.back())-'a'+1;
            s1-=std::min(s[0],s.back())-'a'+1;
        }
        if(s1>s2){
            std::cout<<"Alice "<<std::abs(s1-s2)<<'\n';
        }else{
            std::cout<<"Bob "<<std::abs(s1-s2)<<'\n';
        }
    }
    return 0;
}