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
        int cnt=0;
        std::vector<int>A(n);
        for(int i=0;i<n;++i){
            std::cin>>A[i];
            if(A[i]<0)cnt++;
            A[i]=std::abs(A[i]);
        }
        bool ok=true;
        for(int i=0;i<cnt;++i){
            A[i]=-A[i];
            if(i&&A[i]<A[i-1])ok=false;
        }
        for(int i=cnt;i<n;++i){
            if(i&&A[i]<A[i-1])ok=false;
        }
        std::cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}