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
        std::set<char>st(s.begin(),s.end());
        int sz=st.size();
        auto pattern=s.substr(0,sz);
        bool fail=false;
        if((int)std::set<char>(all(pattern)).size()!=sz)fail=true;
        for(int i=0;i<(int)s.length();i+=sz){
            if(i+sz>=(int)s.length()){
                int l=(int)s.length()-i;
                if(pattern.substr(0,l)!=s.substr(i)) fail=true;
            } else if(pattern!=s.substr(i,sz)) 
                fail=true;
        }
        std::cout<<(fail?"NO":"YES")<<'\n';
    }
    return 0;
}