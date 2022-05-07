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
        int n,k; std::cin>>n>>k;
        std::string s; std::cin>>s;
        char mx='a';
        for(int i=0;i<n;++i){
            if(s[i]-'a'>k){
                char a=s[i]-(k-(mx-'a'));
                char b=s[i];
                for(int j=i;j<n;++j) if(s[j]>a&&s[j]<=b) s[j]=a;
                break;
            }
            mx=std::max(s[i],mx);
            s[i]='a';
        }
        for(int i=0;i<n;++i) if(s[i]<=mx) s[i]='a';
        std::cout<<s<<'\n';
    }
    return 0;
}