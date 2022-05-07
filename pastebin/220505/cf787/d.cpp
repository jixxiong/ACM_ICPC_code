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
        std::vector<std::vector<int>>G(n+1);
        std::vector<int>fa(n+1);
        int rt=-1;
        for(int i=1;i<=n;++i){
            int f; std::cin>>f;
            if(f==i){
                rt=i;
                continue;
            }
            fa[i]=f;
            G[f].pb(i);
        }
        assert(~rt);
        fa[rt]=-1;
        int ans=0;
        std::vector<char>vis(n+1);
        std::vector<std::vector<int>>pt;
        for(int i=1;i<=n;++i){
            if(G[i].size()==0){
                ans++;
                auto p=i;
                pt.resize((int)pt.size()+1);
                do{
                    if(vis[p]) break;
                    vis[p]=true;
                    pt.back().pb(p);
                    p=fa[p];
                }while(~p);
                std::reverse(all(pt.back()));
            }
        }
        std::cout<<ans<<'\n';
        for(auto v:pt){
            std::cout<<v.size()<<'\n';
            for(auto x:v) std::cout<<x<<' ';
            std::cout<<'\n';
        }
        std::cout<<'\n';
    }
    return 0;
}