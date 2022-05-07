#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct node{
    int l,r,id;
};

int32_t main(){
    int n,rt; std::cin>>n>>rt;
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    std::vector<int>B=A;
    std::sort(all(B));
    B.erase(std::unique(all(B)),B.end());
    for(int i=1;i<=n;++i) A[i]=std::lower_bound(all(B),A[i])-B.begin();
    std::vector<std::vector<int>>G(n+1);
    for(int i=1;i<n;++i){
        int u,v; std::cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    std::vector<int>L(n+1),R(n+1),hs(n+1);
    int tic=0;
    std::function<void(int,int)>dfs1=[&](int u,int f){
        L[u]=++tic;
        hs[tic]=u;
        for(auto v:G[u]){
            if(v==f) continue;
            dfs1(v,u);
        }
        R[u]=tic;
    };
    dfs1(rt,-1);
    std::vector<node>Q(n+1);
    for(int i=1;i<=n;++i){
        Q[i]=node{L[i],R[i],i};
    }
    int const block=500;
    std::sort(Q.begin()+1,Q.end(),[](node const&o1,node const&o2){
        return o1.l/block==o2.l/block?o1.r<o2.r:o1.l<o2.l;
    });
    std::vector<int>cnt(n+1);
    int g=0;
    auto del=[&](int x){
        if(--cnt[x]==0) g--;
    };
    auto add=[&](int x){
        if(cnt[x]++==0) g++;
    };
    std::vector<int>sz(n+1);
    for(int l=1,r=0,i=1;i<=n;++i){
        while(l>Q[i].l)add(A[hs[--l]]);
        while(l<Q[i].l)del(A[hs[l++]]);
        while(r<Q[i].r)add(A[hs[++r]]);
        while(r>Q[i].r)del(A[hs[r--]]);
        sz[Q[i].id]=g;
    }
    std::vector<ll>dp(n+1);
    ll ans=0;
    std::function<void(int,int)> dfs2=[&](int u, int fa) {
        dp[u] = sz[u];
        for (auto v: G[u])
            if (v != fa) {
                dfs2(v, u);
                ans = std::max(ans, dp[u] + dp[v]);  //注意先更新ans
                dp[u] = std::max(dp[u], dp[v] + sz[u]);
            }
        ans = std::max(ans, dp[u]);
    };
    dfs2(rt,-1);
    std::cout<<ans<<'\n';
    return 0;
}