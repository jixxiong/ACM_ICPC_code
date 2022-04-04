#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e4+10,M=3e7+2e6+10,inf=2e9,up=32000000;
    int n,m,k;
    int a[N],v[N];
    typedef pair<int,int> p;
    vector<p> eg[N];
    bool vis[M];

    signed d[M];

    signed prime[5000010],num;
    inline void oula(int n)
    {
        for(int i=2;i<=n;++i)
        {
            if(!vis[i]) prime[++num]=i,d[i]=i;
            for(int j=1;j<=num&&i*prime[j]<=n;++j)
            {
                vis[i*prime[j]]=1;
                d[i*prime[j]]=prime[j];
                if(i%prime[j]==0) continue;
            }
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m>>k;
        oula(up);
        for(int i=1;i<=m;++i) cin>>a[i];
        for(int i=1;i<=k;++i)
        {
            int x,y,z;cin>>x>>y>>z;
            eg[x].push_back(p(y,z));
        }
        int tmp=2;
        for(int i=1;i<=n;++i)
        {
            int g=a[eg[i][0].first];
            for(p t:eg[i])
            {
                g=__gcd(g,a[t.first]);
            }
           // cout<<g<<' '<<d[g]<<"!!"<<endl;
            if(g<=32000000) tmp=d[g];
            else tmp=g;
            for(p t:eg[i])
            {
                int k=t.second;
                while(k--)
                {
                    a[t.first]/=tmp;
                }
            }
            v[i]=tmp;
        }
        for(int i=1;i<=n;++i) cout<<v[i]<<" \n"[i==n];
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
1
8
515 66 16313 646 946 15 623 6

*/