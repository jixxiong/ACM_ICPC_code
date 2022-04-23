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
        int n; std::cin>>n;
        std::vector<int>A(n);
        for(int i=0;i<n;++i) std::cin>>A[i];
        std::vector<int>B;
        for(int i=1;i<n;++i){
            if(A[i-1]==A[i]) B.push_back(i-1);
        }
        std::cout<<((int)B.size()<=1?0:(std::max(1,B.back()-B[0]-1)))<<'\n';
    }
    return 0;
}