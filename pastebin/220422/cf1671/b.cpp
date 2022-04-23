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
        bool ok=false;
        for(int sp=A[0]-1;sp<=A[0]+1;++sp){
            bool fail=false;
            for(int j=0;j<n;++j){
                if(std::abs(A[j]-(sp+j))>1) {
                    fail=true;
                    break;
                }
            }
            if(!fail){
                ok=true;
                break;
            }
        }
        std::cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}