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
        int n,m; std::cin>>n>>m;
        std::vector<std::vector<int>>A(n,std::vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                std::cin>>A[i][j];
                if((i+j)&1){
                    if(A[i][j]&1)A[i][j]++;
                }else{
                    if(!(A[i][j]&1))A[i][j]++;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                std::cout<<A[i][j]<<" \n"[j==m-1];
            }
        }
    }
    return 0;
}