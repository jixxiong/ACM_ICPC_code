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
        int n=s.length();
        bool fail=false;
        for(int l=0,r;l<n;l=r){
            r=l+1;
            while(r<n&&s[r]==s[l])r++;
            if((r-l)<2){
                fail=true;
                break;
            }
        }
        std::cout<<(fail?"NO":"YES")<<'\n';
    }
    return 0;
}