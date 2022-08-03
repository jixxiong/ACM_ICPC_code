#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m;
    int k,p;
    int st,ed;
    typedef pair<int,int> pr;
    vector<pr> eg[N],gg[N];
    int dep[N];
    int pre[N];
    inline void dfs(int now,int fa)
    {
        dep[now]=dep[fa]+1;
        for(auto tmp:eg[now])
        {
            int t=tmp.first,v=tmp.second;
            if(t==fa) continue;
            pre[t]=pre[now]+v;
            dfs(t,now);
        }
    }
    int sta[N],top;
    inline void dfs1(int now,int fa)
    {
        sta[++top]=now;
        if(top>k)
        {
            int t=sta[top-k];
            gg[now].emplace_back(pr(t,p));
            gg[t].emplace_back(pr(now,p));
        }
        for(auto tmp:eg[now])
        {
            int t=tmp.first,v=tmp.second;
            if(t==fa) continue;
            pre[t]=pre[now]+v;
            dfs1(t,now);
        }
        --top;
    }
    int dis[N];
    bool vis[N];
    priority_queue<pr,vector<pr>,greater<pr> > qq;
    inline void spfa()
    {
        dis[st]=0;
        qq.push(pr(0,st));
        while(!qq.empty())
        {
            int now=qq.top().second;
            qq.pop();
            if(vis[now]) continue;
            vis[now]=1;
            for(auto tmp:gg[now])
            {
                int t=tmp.first,v=tmp.second;
                if(dis[t]>dis[now]+v)
                {
                    dis[t]=dis[now]+v;
                    qq.push(pr(dis[t],t));
                }
            }
        }
    }
    inline void init()
    {
        for(int i=1;i<=n;++i)
        {
            eg[i].clear();
            gg[i].clear();
            vis[i]=0;
            dis[i]=1e18;
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            init();
            for(int i=1;i<=n;++i) eg[i].clear();
            for(int i=1;i<n;++i)
            {
                int x,y,z;cin>>x>>y>>z;
                eg[x].emplace_back(pr(y,z));
                eg[y].emplace_back(pr(x,z));
                gg[x].emplace_back(pr(y,z));
                gg[y].emplace_back(pr(x,z));
            }
            cin>>k>>p;
            cin>>st>>ed;
            dfs(1,0);
            dfs1(1,0);
            spfa();
            cout<<dis[ed]<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
3
6
6 1 2
3 5 2
2 4 6
5 2 2
5 6 20
3 8
6 5
6
6 1 2
3 5 2
2 4 6
5 2 2
5 6 20
3 8
6 5
6
6 1 2
3 5 2
2 4 6
5 2 2
5 6 20
3 8
4 3

*/