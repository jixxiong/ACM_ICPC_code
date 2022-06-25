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
        std::array<int,3>A;
        std::cin>>A[0]>>A[1]>>A[2];
        std::sort(all(A));
        if((A[0]==A[1]&&!(A[2]&1))||
            (A[1]==A[2]&&!(A[0]&1))||
            A[2]==A[0]+A[1]) 
            std::cout<<"YES"<<"\n";
        else std::cout<<"NO"<<"\n";
    }
    return 0;
}