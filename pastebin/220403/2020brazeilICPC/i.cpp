#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,inf=2e9,mod=1e9+7;
    int n;
    int a[N];
    vector<int> eg[N];
    int dp[N][2];
    inline int fast(int x,int k)
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=ret*x%mod;
            x=x*x%mod;
            k>>=1;
        }
        return ret;
    }
    inline void dfs(int now,int fa)
    {
        bool flag=0;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            dfs(t,now);
            flag=1;
        }
        if(flag==0)
        {
            dp[now][1]=1;
            dp[now][0]=1;
            return;
        }
        //dp[now][1]
        int tmp1=1,tmp2=0;
        for(int t:eg[now])
        {
            if(t==fa) continue;
            tmp1=tmp1*dp[t][1]%mod;
        }
        for(int t:eg[now])
        {
            if(t==fa) continue;

            // tmp4=tmp4*dp[now][1]%mod;
            // int tmp5=tmp1*fast(tmp4,mod-2)%mod;
            // tmp3=(tmp3+tmp2*dp[t][0]%mod*tmp5%mod)%mod;

            tmp2=(tmp2+tmp1*fast(dp[t][1],mod-2)%mod*dp[t][0]%mod)%mod;
        }
        dp[now][1]=(tmp1+tmp2)%mod;
        //dp[now][0];
        dp[now][0]=tmp2;

    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=2;i<=n;++i)
        {
            int fa;cin>>fa;
            eg[fa].push_back(i);
        }
        dfs(1,0);
        cout<<dp[1][1]<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
6
1 1 1 1 1

*/