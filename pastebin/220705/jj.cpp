#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int unsigned long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,inf=2e9;
    int n;
    int dp[N];
    inline int dfs(int n)
    {
        if(~dp[n]) return dp[n];
        if(n&1) return dp[n]=dfs(n/2)*dfs(n/2);
        return dp[n]=2*dfs(n/2)*dfs(n/2-1);
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        memset(dp,-1,sizeof(dp));
        dp[1]=dp[0]=1;
        while(qwq--)
        {
            for(int i=1;i<=1200;++i)
            {
                cout<<i<<' '<<dfs(i)<<'\n';
            }
            
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*

dp[n]=dp[n/2]*dp[n/2] (n is odd)

dp[n]=dp[n/2]*dp[n/2-1]*2 (n is oushu)

*/