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
        int n,m; std::cin>>n>>m;
        if((n&1)&&m!=1){
            std::cout<<"NO\n";
            continue;
        }
        std::cout<<"YES\n";
        int c1=-1,c2=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(i&1){
                    std::cout<<(c1+=2)<<" \n"[j==m];
                }else{
                    std::cout<<(c2+=2)<<" \n"[j==m];
                }
            }
        }
    }
    return 0;
}