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
    std::string s; std::cin>>s;
    std::set<char>st(s.begin(),s.end());
    bool a=false,A=false;
    for(char ch:s){
        if(ch>='a'&&ch<='z') a=true;
        if(ch>='A'&&ch<='Z') A=true;
    }
    std::cout<<(a&&A&&((int)st.size()==(int)s.length())?"Yes":"No");
    return 0;
}