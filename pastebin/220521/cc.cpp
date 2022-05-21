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
        int x,y; std::cin>>x>>y;
        int a,b,c; std::cin>>a>>b>>c;
        std::map<int,int>mp;
        std::queue<int>q; q.push(x);
        mp[x]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            if(u>100*y) continue;
            // pr(u,mp[u]);
            int v=u+1;
            if(!mp.count(v)||mp[v]>mp[u]+a) q.push(v), mp[v]=mp[u]+a;
            v=2*u;
            if(!mp.count(v)||mp[v]>mp[u]+b) q.push(v), mp[v]=mp[u]+b;
            v=u/2;
            if(!mp.count(v)||mp[v]>mp[u]+c) q.push(v), mp[v]=mp[u]+c;
        }
        std::cout<<mp[y]<<'\n';
    }
    return 0;
}