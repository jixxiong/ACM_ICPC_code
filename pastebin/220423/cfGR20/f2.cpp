#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int get(const std::vector<int>&A,const std::vector<int>&B){
    int n=A.size();
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
    return huan;
}

std::vector<int>get(std::vector<int>&A){
    int n=A.size();
    std::vector<std::vector<int>>cnt(n+1);
    for(int i=0;i<n;++i){
        cnt[A[i]].push_back(i);
    }
    std::vector<int>B(n+1);
    std::iota(all(B),0);
    std::sort(all(B),[&](int x,int y){
        return cnt[x].size()<cnt[y].size();
    });
    int b=[&](){
        int i=0; for(;i<=n;++i)if(!cnt[B[i]].empty()) break;
        return i;
    }();
    std::vector<int>rest(all(cnt[B[b]]));
    std::vector<int>C(n);
    for(int i=b;i<n;++i){
        int mx=(int)std::min(cnt[B[i]].size(),cnt[B[i+1]].size());
        for(int j=0;j<mx;++j){
            C[cnt[B[i+1]][j]]=A[cnt[B[i]][j]];
        }
        for(int j=mx;j<(int)cnt[B[i+1]].size();++j){
            rest.push_back(cnt[B[i+1]][j]);
        }
    }
    for(int i=0;i<(int)rest.size();++i){
        C[rest[i]]=A[cnt[B[n]][i]];
    }
    return C;
}

int main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n),B(n);
        for(int i=0;i<n;++i) std::cin>>A[i];
        for(int i=0;i<n;++i) std::cin>>B[i];
        std::cout<<(get(A,B)==get(A,get(A))?"AC":"WA")<<'\n';
    }
    return 0;
}