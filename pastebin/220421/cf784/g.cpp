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
        int n,m; std::cin>>n>>m;
        std::vector<std::string>A(n);
        for(int i=0;i<n;++i){
            std::cin>>A[i];
        }
        for(int i=0;i<m;++i){
            while(true){
                bool fail=true;
                for(int j=n-2;j>=0;--j){
                    if(A[j][i]=='*'&&A[j+1][i]=='.'){
                        fail=false;
                        int k=j+1;
                        while(k<n&&A[k][i]=='.')k++;
                        std::swap(A[j][i],A[k-1][i]);
                        break;
                    }
                }
                if(fail) break;
            }
        }
        for(auto x:A) std::cout<<x<<'\n';
        std::cout<<'\n';
    }
    return 0;
}