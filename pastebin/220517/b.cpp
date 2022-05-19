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
    std::vector<int>cnt(n+2);
    std::vector<ll>A(n+1);
    for(int i=1;i<=q;++i){
        int x,p; std::cin>>x>>p;
        A[x]+=p;
        cnt[x]++;
        cnt[std::min(n+1,x+p)]--;
    }
    for(int i=1;i<=n;++i){
        cnt[i]+=cnt[i-1];
        A[i]+=A[i-1]-cnt[i-1];
        std::cout<<(A[i]+n-i+1)<<" \n"[i==n];
    }
    return 0;
}