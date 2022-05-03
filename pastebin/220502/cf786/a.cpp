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
        int x,y; std::cin>>x>>y;
        if(y%x!=0){
            std::cout<<"0 0\n";
            continue;
        }
        y/=x;
        if(y==1){
            std::cout<<"1 1\n";
            continue;
        }
        for(int i=2;i<=100;++i){
            for(int j=i,c=1;j<=100;j*=i,c++){
                if(y==j){
                    std::cout<<c<<" "<<i<<'\n';
                    goto nxt_round;
                }
            }
        }
        nxt_round: continue;
    }
    return 0;
}