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
    int n,a,b; std::cin>>n>>a>>b;
    std::vector<std::vector<char>>vis(n*a,std::vector<char>(n*b,'#'));
    for(int i=0;i<n*a;++i){
        for(int j=0;j<n*b;++j){
            if(!((((i/a)&1)+((j/b)&1))&1)) vis[i][j]='.';
            std::cout<<vis[i][j];
        }
        std::cout<<'\n';
    }
    return 0;
}