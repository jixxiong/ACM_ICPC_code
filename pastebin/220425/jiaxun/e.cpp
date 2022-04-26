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
    int n,m,k; std::cin>>n>>m>>k;
    std::vector<std::vector<int>>G(n);
    std::vector<std::pair<int,int>>fuk;
    for(int i=0;i<m;++i){
        int u,v; std::cin>>u>>v; --u,--v; 
        fuk.push_back(std::pair<int,int>(u,v));
        fuk.push_back(std::pair<int,int>(v,u));
        G[u].push_back(v); G[v].push_back(u);
    }
    std::vector<ll>f(1<<n);
    for(int i=0;i<n;++i){
        f[1<<i]=1;
    }
    for(int s=0;s<(1<<n);++s){
        for(int t=s;t;t=(t-1)&s){
            int p=s^t;
            int cnt=0;
            for(auto [x,y]:fuk){
                if((t&(1<<x))&&(p&(1<<y))) cnt++;
            }
            f[s]=std::max(f[s],f[t]*f[p]*cnt);
        }
    }
    ll ret=0;
    for(int s=0;s<(1<<n);++s){
        if(__builtin_popcount(s)==k){
            std::vector<char>vis(n);
            for(int i=0;i<n;++i){
                if(!((s>>i)&1)){
                    vis[i]=true;
                }
            }
            std::vector<int>c;
            for(int i=0;i<n;++i){
                if(((s>>i)&1)){
                    int cnt=0;
                    for(auto v:G[i]){
                        if(vis[v]) cnt++;
                    }
                    c.push_back(cnt);
                }
            }
            ll mul=!c.empty();
            for(auto x:c) mul*=x;
            ret+=f[((1<<n)-1)^s]*mul;
        }
    }
    std::cout<<ret<<'\n';
    return 0;
}