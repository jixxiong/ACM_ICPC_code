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
    std::vector<int>A(n+2);A[0]=A[n+1]=0x3f3f3f3f;
    for(int i=1;i<=n;++i) std::cin>>A[i];
    int ret=0x3f3f3f3f;
    for(int i=2;i<=n;++i){
        if(A[i]>A[i-1]*2||A[i-1]>A[i]*2) ret=std::min(ret,(std::max(A[i],A[i-1])+1)/2);
        else ret=std::min(ret,(A[i]+A[i-1]+2)/3);
    }
    for(int i=3;i<=n;++i){
        int t=std::min(A[i-2],A[i]);
        ret=std::min(ret,t+(1+std::max(A[i-2],A[i])-t)/2);
    }
    std::sort(all(A));
    ret=std::min(ret,(A[0]+1)/2+(A[1]+1)/2);
    std::cout<<ret<<'\n';
    return 0;
}