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
    while(true){
        int n; std::cin>>n;
        if(!n) break;
        std::vector<int>h(n+2);
        for(int i=1;i<=n;++i) std::cin>>h[i];
        std::vector<int>stk{0};
        ll ret=0;
        for(int j=1;j<=n+1;++j){
            while(!stk.empty()&&h[j]<h[stk.back()]){
                ret=std::max(ret,(ll)h[stk.back()]*(j-1-*next(stk.rbegin())));
                stk.pop_back();
            }
            stk.push_back(j);
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}