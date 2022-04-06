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
        std::vector<std::vector<int>>A(n+1,std::vector<int>(m+1));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                std::cin>>A[i][j];
            }
        }
        std::vector<std::vector<int>>B(m+1);
        for(int i=1;i<=m;++i){
            for(int l=1,r;l<=n;l=r){
                r=l+1;
                while(r<=n&&A[r][i]>=A[r-1][i])
                    r++;
                B[i].pb(l);
            }
        }
        int ret=0;
        for(int i=1;i<=n;++i){
            std::vector<int>h(m+2);
            for(int j=1;j<=m;++j){
                h[j]=i-*(std::upper_bound(B[j].begin(),B[j].end(),i)-1)+1;
            }
            std::vector<int>stk{0};
            for(int j=1;j<=m+1;++j){
                while(!stk.empty()&&h[j]<h[stk.back()]){
                    ret=std::max(ret,h[stk.back()]*(j-1-*next(stk.rbegin())));
                    stk.pop_back();
                }
                stk.push_back(j);
            }
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}