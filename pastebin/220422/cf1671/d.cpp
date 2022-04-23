#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
#define int long long

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,x; std::cin>>n>>x;
        std::vector<int>A(n);
        int max=0,min=0x3f3f3f3f;
        int ret=0;
        for(int i=0;i<n;++i) {
            std::cin>>A[i];
            if(A[i]>max){
                max=A[i];
            }
            if(A[i]<min){
                min=A[i];
            }
            if(i>0) ret+=std::abs(A[i]-A[i-1]);
        }
        if(min>x){
            int add=std::min({A[0]-1,A[n-1]-1});
            int fuk=0x3f3f3f3f;
            for(int i=0;i<n;++i){
                if(A[i]==min){
                    if(i>0){
                        fuk=std::min(fuk,A[i-1]+A[i]-2-std::abs(A[i-1]-A[i]));
                    }
                    if(i<n-1){
                        fuk=std::min(fuk,A[i]+A[i+1]-2-std::abs(A[i+1]-A[i]));
                    }
                }
            }
            std::cout<<ret+std::min(add,fuk)<<'\n';
            continue;
        }
        if(min>1){
            ret+=std::min(2*min-2,std::min(A[0],A[n-1])-1);
        }
        if(max<x){
            ret+=std::min(2*(x-max),x-std::max(A[0],A[n-1]));
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}