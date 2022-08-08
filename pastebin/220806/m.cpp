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
    const int N=2e6+10,mod=998244353,inv2=5e8+4,inf=2e9;
    inline void main()
    {
        int n,m;
        vector s(n+1,vector<char>(m+1));

        vector dp(n+1,vector(m+1,vector<int>(2)));
        cin>>n>>m;
        vector<int> dx{1,0};
        vector<int> dy{0,1};
        function<int(int,int,int)> dfs=[&](int x,int y,bool f) -> int
        {
            if(s[x][y]=='A') return 2;
            if(s[x][y]=='B') return 4;
            if(x==n&&y==m) return 1;
            if(~dp[x][y][f]) return dp[x][y][f];
            vector<int> sum(10,0);
            if(f)
            {
                for(int k=0;k<2;++k)
                {
                    int tx=x+dx[k],ty=y+dy[k];
                    if(tx<1||tx>n||ty<1||ty>m) continue;
                    int tmp=dfs(tx,ty,0);
                    if(tmp&1) ++sum[1];
                    if(tmp&2) ++sum[2];
                    if(tmp&4) ++sum[4];
                }
                if(sum[1]>0) dp[x][y][f]|=1;
                if(sum[2]>0) dp[x][y][f]|=2;
                if(sum[4]>0) dp[x][y][f]|=4;
                return dp[x][y][f];
            }
            else
            {
                int tot=0;
                for(int k=0;k<2;++k)
                {
                    int tx=x+dx[k],ty=y+dy[k];
                    if(tx<1||tx>n||ty<1||ty>m) continue;
                    ++tot;
                    int tmp=dfs(tx,ty,1);
                    if(tmp&1) ++sum[1];
                    if(tmp&2) ++sum[2];
                    if(tmp&4) ++sum[4];
                }
                if(sum[1]==tot) dp[x][y][f]|=1;
                if(sum[2]==tot) dp[x][y][f]|=2;
                if(sum[4]==tot) dp[x][y][f]|=4;
                return dp[x][y][f];
            }
        };
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                cin>>s[i][j];
                dp[i][j][0]=dp[i][j][1]=-1;
            }
        }
        dfs(1,1,1);
        int tmp=dp[1][1][1];
        if(tmp&2) cout<<"yes ";
        else cout<<"no ";
        if(tmp&4) cout<<"yes ";
        else cout<<"no ";
        if(tmp&1) cout<<"yes ";
        else cout<<"no "; 
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int qwq;cin>>qwq;
    while(qwq--)
    red::main();
    return 0;
}
/*
B
A-B

C -> B-C -> A-2B+C -> -A+3B-C -> 2A-4B+C -> -2A+5B-C -> 3A-6B+C -> -3A+7B-C

C -> A-B-C -> -A+2B+C -> 2A-3B-C -> -2A+4B+C -> 3A-5B-C -> -3A+6B+C
*/