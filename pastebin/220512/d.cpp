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
        std::vector<std::vector<int>>A(n+1,std::vector<int>(m+1));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                std::cin>>A[i][j];
            }
        }
        std::vector<std::pair<int,int>> const mv{{1,1},{1,-1},{-1,1},{-1,-1}};
        int ret=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                int sum=A[i][j];
                for(auto [dx,dy]:mv){
                    int x=i+dx,y=j+dy;
                    while(x>=1&&x<=n&&y>=1&&y<=m){
                        sum+=A[x][y];
                        x+=dx,y+=dy;
                    }
                    ret=std::max(sum,ret);
                }
            }
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}