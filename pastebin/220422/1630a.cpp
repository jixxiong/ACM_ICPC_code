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
        int n,k; std::cin>>n>>k;
        if(k==n-1){
            if(n==4)std::cout<<"-1\n";
            else{
                std::vector<int>A(n);
                std::iota(all(A),0);
                std::cout<<n-1<<' '<<n-2<<'\n';
                auto k=std::__lg(n-1);
                std::cout<<0<<' '<<((1<<k))<<'\n';
                std::cout<<1<<' '<<((1<<k)-1)<<'\n';
                for(int i=0;i<n/2;++i) if(A[i]!=0&&A[i]!=1&&A[i]!=((1<<k)-1)) std::cout<<A[i]<<' '<<A[n-i-1]<<'\n';
            }
            continue;
        }
        std::vector<int>A(n);
        std::iota(all(A),0);
        std::swap(A[n-1],A[(n-1)^k]);
        for(int i=0;i<n/2;++i) std::cout<<A[i]<<' '<<A[n-i-1]<<'\n';
    }
    return 0;
}