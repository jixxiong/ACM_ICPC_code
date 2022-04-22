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
        std::vector<int>A(n),B(n),id(n);
        for(int i=0;i<n;++i) std::cin>>A[i];
        for(int i=0;i<n;++i) std::cin>>B[i];
        std::iota(all(id),0);
        std::sort(all(id),[&](int a,int b){
            return A[a]<A[b];
        });
        for(int i=0;i<n;++i){
            if(A[id[i]]<=k){
                k+=B[id[i]];
            }else{
                break;
            }
        }
        std::cout<<k<<'\n';
    }
    return 0;
}