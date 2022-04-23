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
    int T; std::cin>>T;
    while(T--){
        std::string s; std::cin>>s;
        bool fail=s[0]=='B'||s.back()=='A';
        int n=s.length();
        int sa=0,sb=0;
        for(int i=0;i<n;++i){
            if(s[i]=='A')sa++;
            else {
                sb++;
                if(sa<sb)fail=true;
            }
        }
        std::cout<<(fail?"NO":"YES")<<'\n';
    }
    return 0;
}