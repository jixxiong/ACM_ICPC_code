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
        std::vector<int>A(n),B(n);
        std::vector<std::vector<int>>cnt(n+1);
        for(int i=0;i<n;++i) {
            std::cin>>A[i];
            cnt[A[i]].push_back(i);
        }
        for(int i=0;i<n;++i) std::cin>>B[i];
        if(n==1){
            std::cout<<"AC\n";
            continue;
        }
        std::vector<int>C(n+1);
        std::iota(all(C),0);
        std::sort(all(C),[&](int x,int y){
            return cnt[x].size()<cnt[y].size();
        });
        int mn=0;
        for(int i=0;i<=n;++i){
            if(cnt[C[i]].empty()) continue;
            mn=cnt[C[i]].size(); break;
        }
        int mx=std::max_element(all(cnt),[&](auto&& f,auto&& g){
            return f.size()<g.size();
        })->size();
        if(mx==mn){
            std::vector<std::vector<int>>G(n+1);
            for(int i=0;i<n;++i){
                G[B[i]].push_back(A[i]);
            }
            for(int i=1;i<=n;++i){
                std::sort(all(G[i]));
                G[i].erase(std::unique(all(G[i])),G[i].end());
            }
            std::vector<char>vis(n+1),stk(n+1);
            int huan=0;
            for(int i=1;i<=n;++i){
                if(vis[i])continue;
                std::function<void(int)> dfs=[&](int u){
                    if(stk[u]) huan++;
                    stk[u]=true;
                    if(vis[u]) return;
                    vis[u]=true;
                    for(auto v:G[u]) dfs(v);
                    stk[u]=false;
                };
                dfs(i);
            }
            std::cout<<(huan>1?"WA":"AC")<<'\n';
        }else{
            std::vector<std::vector<int>>G(n+1);
            for(int i=0;i<n;++i){
                if((int)cnt[B[i]].size()!=mx)G[B[i]].push_back(A[i]);
            }
            for(int i=1;i<=n;++i){
                std::sort(all(G[i]));
                G[i].erase(std::unique(all(G[i])),G[i].end());
            }
            std::vector<char>vis(n+1),stk(n+1);
            int huan=0;
            for(int i=1;i<=n;++i){
                if(vis[i])continue;
                std::function<void(int)> dfs=[&](int u){
                    if(stk[u]) huan++;
                    stk[u]=true;
                    if(vis[u]) return;
                    vis[u]=true;
                    for(auto v:G[u]) dfs(v);
                    stk[u]=false;
                };
                dfs(i);
            }
            std::cout<<(huan?"WA":"AC")<<'\n';
        }
    }
    return 0;
}