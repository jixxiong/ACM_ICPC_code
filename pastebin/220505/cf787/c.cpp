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
        int n=s.length();
        s+="0";
        int ans=0;
        for(int i=0;i<=n;++i){
            if(s[i]=='0'){
                int j=i-1;
                while(j>=0&&s[j]=='?') j--;
                if(j>=0&&s[j]=='1')j--;
                ans=i-j;
                if(i==n)ans--;
                break;
            }
        }
        std::cout<<ans<<'\n';
    }
    return 0;
}