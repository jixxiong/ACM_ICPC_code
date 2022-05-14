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
        std::sort(1+all(A));
        int c=0;
        for(int l=1,r;l<=n;l=r+1){
            r=l;
            while(r<=n&&A[r]>(r-l+1))r++;
            if(r>n) break;
            c++;
        }
        std::cout<<c<<'\n';
    }
    return 0;
}