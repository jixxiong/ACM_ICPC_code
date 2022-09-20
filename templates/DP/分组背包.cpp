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
    int n,m; std::cin>>n>>m;
    std::vector<int>f(m+1);
    std::map<int,std::vector<std::pair<int,int>>>A;
    for(int i=1;i<=n;++i){
        int a,v,w; std::cin>>a>>v>>w;
        A[a].push_back(std::pair<int,int>(v,w));
    }
    for(auto [_,vec]:A){
        for(int j=m;j>=0;--j){
            for(auto [v,w]:vec){
                if(j>=v){
                    f[j]=std::max(f[j],f[j-v]+w);
                }
            }
        }
    }
    std::cout<<f[m]<<'\n';
    return 0;
}