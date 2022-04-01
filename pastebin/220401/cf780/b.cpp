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
        std::vector<int>v(n);
        for(auto& x:v) std::cin>>x;
        sort(all(v));
        if(n==1) {
            std::cout<<(v[0]==1?"YES":"NO")<<'\n';
            continue;
        }
        std::cout<<(v.back()<=*std::next(v.rbegin())+1?"YES":"NO")<<'\n';
    }
    return 0; 
}