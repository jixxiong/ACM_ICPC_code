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
        std::vector<std::string>A(n);
        int x=-1,y=-1;
        for(int i=0;i<n;++i){
            std::cin>>A[i];
            for(int j=0;j<m;++j){
                if((x==-1)&&A[i][j]=='R'){
                    x=i,y=j;
                }
            }
        }
        bool fail=false;
        for(int i=x+1;i<n;++i){
            for(int j=0;j<y;++j){
                if(A[i][j]=='R') fail=true;
            }
        }
        std::cout<<(!fail?"YES":"NO")<<'\n';
    }
    return 0;
}