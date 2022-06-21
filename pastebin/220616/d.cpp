#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define er(args...) void()
#else
    #define vwn(x) #x"=",x,"\n"
    void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
    #define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>pre(n+1);
        std::vector<std::vector<int>>G(n+1);
        for(int i=2;i<=n;++i){
            std::cin>>pre[i];
            G[pre[i]].pb(i);
        }
        std::vector<ll>L(n+1),R(n+1);
        for(int i=1;i<=n;++i) std::cin>>L[i]>>R[i];
        int ans=0;
        std::function<ll(int)>dfs=[&](int u){
            ll s=0;
            for(auto v:G[u]){
                s+=dfs(v);
            }
            if(s<L[u]) ans++,s=R[u];
            return std::min(s,R[u]);
        };
        dfs(1);
        std::cout<<ans<<'\n';
    }
    return 0;
}