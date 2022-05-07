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
        std::vector<int>A(n+1);
        for(int i=1;i<=n;++i) std::cin>>A[i];
        bool fail=false;
        int c=0;
        for(int i=n-1;i>=1;--i){
            if(A[i+1]==0){
                fail=true;
                break;
            }
            while(A[i]>=A[i+1]) A[i]/=2,c++;
        }
        std::cout<<(fail?-1:c)<<'\n';
    }
    return 0;
}