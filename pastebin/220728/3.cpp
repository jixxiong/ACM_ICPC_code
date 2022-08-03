//@Author: ZI_MA
#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define PP pair<int, int>
#define all(x) x.begin()+1,x.end()
#define endl '\n'
#define ll long long
#define int long long
const int INF=1e16;
const int N=1e9+1;
struct node{
    int u,x,y;
    bool operator < (const node &t) const {
        if(x==t.x) return y>t.y;
        return x>t.x;
    }
};
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<array<int,3>>> g(n+1);
    int mx=e;
    for(int i=1,u,v,e,p;i<=m;i++) {
        cin>>u>>v>>e>>p;
        g[u].push_back({v,e,-p});
        mx=std::max(mx,e);
    }
    for(int i=1;i<=n;++i){
        for(auto&e:g[i]){
            e.x+=mx+1;
        }
    }
    priority_queue<node> q;
    q.push({1,0,0});
    vector<int> dis1(n+1,INF),dis2(n+1,1);
    dis1[1]=0;dis2[1]=0;
    vector<bool> vis(n+1);
    while(!q.empty()) {
        node tmp=q.top(); q.pop();
        int u=tmp.u,x=tmp.x,y=tmp.y;
        if(vis[u]) continue;
        vis[u]=true;
        for(auto t:g[u]) {
            int v=t[0],e=t[1],p=t[2];
            if(dis1[v]>x+e) {
                dis1[v]=x+e;
                dis2[v]=y+p;
                q.push({v,dis1[v],dis2[v]});
            } else if(dis1[v]==x+e) {
                if(dis2[v]>y+p) {
                    dis2[v]=y+p;
                    q.push({v,dis1[v],dis2[v]});
                }
            }
        }
    }
    cout<<dis1[n]<<' '<<-dis2[n]<<endl;
}
signed main() {
    IOS;
    int __;
    cin>>__;
    while(__--) solve();
    return 0;
}