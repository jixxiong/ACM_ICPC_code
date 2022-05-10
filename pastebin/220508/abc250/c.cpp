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
    std::vector<int>A(n+1);
    std::vector<int>B(n+1);
    std::iota(all(A),0);
    std::iota(all(B),0);
    while(q--){
        int x; std::cin>>x;
        int p=B[x];
        if(p==n){
            std::swap(A[n],A[n-1]);
            std::swap(B[A[n]],B[A[n-1]]);
        }else{
            std::swap(A[p],A[p+1]);
            std::swap(B[A[p]],B[A[p+1]]);
        }
    }
    for(int i=1;i<=n;++i) std::cout<<A[i]<<" \n"[i==n];
    return 0;
}