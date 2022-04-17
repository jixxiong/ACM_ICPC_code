#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define double long double
#define eps (1e-8)
const double inf=1e9;
const int N=3e5+10;
int n;
double a[N],b[N];
vector<int> eg[N];
double dp[N],f[N][2];
bool vis[N];
inline void dfs(int now,int fa)
{
	dp[now]=a[now];
	double tmp1=-inf,tmp2=-inf;
	for(int t:eg[now])
	{
		if(t==fa) continue;
		dfs(t,now);
		vis[now]=1;
		if(dp[t]>tmp1-eps) tmp2=tmp1,tmp1=dp[t];
		else tmp2=max(tmp2,dp[t]);
	}
	f[now][0]=tmp1,f[now][1]=tmp2;
	if(tmp1>0) dp[now]+=tmp1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>b[i];
	for(int i=1;i<n;++i)
	{
		int x,y;cin>>x>>y;
		eg[x].emplace_back(y);
		eg[y].emplace_back(x);
	}
	double ans=-1e15;
	double l=-1e5,r=1e5;
	while(r-l>eps)
	{
		double mid=(l+r)/2.0;
		for(int i=1;i<=n;++i) a[i]=b[i]-mid;
		dfs(1,0);
		bool flag=0;
		for(int i=1;i<=n;++i) if(vis[i])
		{
			if(a[i]+f[i][0]+max((double)0.0,f[i][1])>eps) flag=1;
		}
		if(flag) l=mid;
		else r=mid;
	}
	ans=max(ans,l*l/4.0);
	for(int i=1;i<=n;++i) b[i]=-b[i];
	l=-1e5,r=1e5;
	while(r-l>eps)
	{
		double mid=(l+r)/2.0;
		for(int i=1;i<=n;++i) a[i]=b[i]-mid;
		dfs(1,0);
		bool flag=0;
		for(int i=1;i<=n;++i) if(vis[i])
		{
			if(a[i]+f[i][0]+max((double)0.0,f[i][1])>eps) flag=1;
		}
		if(flag) l=mid;
		else r=mid;
	}
	ans=max(ans,l*l/4.0);
	cout<<fixed<<setprecision(6)<<ans<<'\n';
	return 0;
}
/*
5
-5 1 2 -1 -3
1 2
2 3
4 5
1 4

*/