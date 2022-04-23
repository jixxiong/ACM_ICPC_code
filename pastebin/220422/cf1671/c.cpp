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
        int n,x; std::cin>>n>>x;
        std::vector<ll>A(n);
        for(int i=0;i<n;++i){
            std::cin>>A[i];
        }
        std::sort(all(A));
        for(int i=1;i<n;++i) A[i]+=A[i-1];
        std::vector<ll>B(n);
        ll ret=0;
        for(int i=n-1;i>=0;--i){
            B[i]=std::max(0ll,(x-A[i])/(i+1)+1);
            if(x<A[i]) B[i]=0;
            ret+=B[i];
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}