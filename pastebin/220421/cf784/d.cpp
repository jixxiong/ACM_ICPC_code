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
        int n; std::cin>>n;
        std::string s; std::cin>>s;
        bool fail=false;
        for(int l=0,r;l<n;l=r){
            while(l<n&&s[l]=='W')l++;
            if(l==n) break;
            r=l+1;
            bool b=false,w=false;
            s[l]=='B'?b=true:w=true;
            while(r<n&&s[r]!='W')s[r]=='B'?b=true:w=true,r++;
            if(!(b&&w)){
                fail=true;
                break;
            }
        }
        std::cout<<(fail?"NO":"YES")<<'\n';
    }
    return 0;
}