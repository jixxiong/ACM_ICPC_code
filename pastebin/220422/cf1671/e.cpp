#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void dg(){ std::cerr<<'\n'; } template<class fst,class...lst>
void dg(fst F, lst... L) { std::cerr<<F<<' '; dg(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ull=unsigned long long;

int main(){
    int n; std::cin>>n;
    n=(1<<n)-1;
    std::string s; std::cin>>s; s=' '+s;
    std::vector<int>id(n+1); int c=1;
    const int mo=998244353;
    std::vector<std::string>hs(n+1);
    std::function<void(int)>f=[&](int u){
        id[u]=c++;
        hs[u]=std::string("")+s[u];
        if((u<<1)>n)return ;
        f(u<<1);f(u<<1|1);
        hs[u]+=std::min(hs[u<<1],hs[u<<1|1])+std::max(hs[u<<1],hs[u<<1|1]);
    };
    f(1);
    std::function<int(int)>dfs=[&](int u){
        int v1=u<<1,v2=u<<1|1;
        if(v1>n) return 1ll;
        int m1=dfs(v1);
        int m2=dfs(v2);
        return (ll)m1*m2%mo*(hs[v1]==hs[v2]?1:2)%mo;
    };
    std::cout<<dfs(1)<<'\n';
    return 0;
}