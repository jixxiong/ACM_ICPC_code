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
    int n; std::cin>>n;
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    std::vector<int>f(n+1,1);
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(A[i]>A[j]) f[i]=std::max(f[i],f[j]+1);
        }
    }
    std::cout<<std::accumulate(1+all(f),0,
        [](int x,int y){return std::max(x,y); })<<'\n';
    return 0;
}