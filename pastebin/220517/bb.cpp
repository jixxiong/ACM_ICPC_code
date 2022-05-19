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
    int n,q; std::cin>>n>>q;
    std::vector<ll>A(n+1);
    for(int i=1;i<=q;++i){
        int x,p; std::cin>>x>>p;
        for(;x<=n&&p>0;p--,x++) A[x]+=p;
    }
    for(int i=1;i<=n;++i) std::cout<<(A[i]+n-i+1)<<" \n"[i==n];
    return 0;
}