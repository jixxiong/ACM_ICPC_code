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
        int a,b; std::cin>>a>>b;
        if(a==0) {
            std::cout<<"1"<<'\n';
            continue;
        }
        std::cout<<1+std::max((a+2*b)/2*2,((a-1)/2+b)*2+1)<<'\n';
    }
    return 0; 
}