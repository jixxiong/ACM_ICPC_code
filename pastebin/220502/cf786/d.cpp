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
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n);
        for(int i=0;i<n;++i) std::cin>>A[i];
        for(int i=n-1;i>0;i-=2){
            if(A[i]<A[i-1])std::swap(A[i],A[i-1]);
        }
        bool fail=false;
        for(int i=1;i<n;++i){
            if(A[i]<A[i-1])fail=true;
        }
        std::cout<<(fail?"NO":"YES")<<'\n';
    }
    return 0;
}