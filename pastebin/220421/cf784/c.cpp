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
        bool c[4]={};
        for(int i=1;i<=n;++i){
            int x; std::cin>>x;
            c[(i&1)<<1|(x&1)]=true;
        }
        std::cout<<((c[0]^c[1])&(c[2]^c[3])?"YES":"NO")<<'\n';
    }
    return 0;
}