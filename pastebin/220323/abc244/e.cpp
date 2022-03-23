#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); }
#endif
void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int n,m,k,s,t,x;
    cin>>n>>m>>k>>s>>t>>x;
    vector<vector<int>>G(n+1);
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    function<ll(int,)
    return 0; 
}