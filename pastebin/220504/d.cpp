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
        int n; std::cin>>n;
        std::vector<int>A(n+1);
        for(int i=1;i<=n;++i){
            int x; std::cin>>x;
            A[x]=i;
        }
        if(n==1){
            std::cout<<"0\n";
            continue;
        }
        int ret=0;
        for(int i=1;i<=n;++i){
            std::vector<int>vis(n+2);
            int c=0;
            for(int j=i;j<=n;++j){
                int p=A[j];
                if(!vis[p-1]&&!vis[p+1]) c++;
                if(vis[p-1]&&vis[p+1]) c--;
                vis[p]=true;
                if(c<=2) ret++;
            }
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}