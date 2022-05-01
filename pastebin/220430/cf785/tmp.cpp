#include<bits/stdc++.h>
#define MAXN 50005
#define mod 1000000007
#define ll long long
using namespace std;
ll fp[MAXN]={0};
ll gp[MAXN]={0};
ll dp[MAXN][301]={0};
 
int main()
{
    ll n,m;
    scanf("%lld",&n);
    m=sqrt(n)+1;
    fp[0]=gp[0]=1;
    for(ll i=1;i<m;i++)
        for(int j=0;i+j<=n;j++)
            fp[j+i]=(fp[j+i]+fp[j])%mod;
    dp[m][1]=1;
    for(ll i=m;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            dp[i][j]=(dp[i][j]+dp[i-j][j]+dp[i-m][j-1])%mod;
            gp[i]=(gp[i]+dp[i][j])%mod;
        }
    }
    ll ans=0;
    for(ll i=0;i<=n;i++)
        ans=(ans+gp[i]*fp[n-i])%mod;
    printf("%lld\n",ans);
    return 0;
}