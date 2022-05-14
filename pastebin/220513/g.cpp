#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5000+10,inf=1e12;
int n;
double v1,v2;
struct node
{
	int x,y;
}a[N],st,ed;
double dis[N];
bool vis[N];
int num;
inline double sqr(double x){return x*x;}
inline double getdis(int x,int y)
{
	double len=sqrt(sqr(a[x].x-a[y].x)+sqr(a[x].y-a[y].y));
	if(x>n-1) return len/v1;
	if(v2*3.0>len) return len/v2;
	else
	{
		len-=v2*3.0;
		return len/v1+3.0;
	}
}
inline void prim()
{
	for(int i=1;i<=n;++i)
	{
		dis[i]=inf;
	}
	dis[n]=0;
	int num=1,now=n;
	while(num<n)
	{
		vis[now]=1;
		double minn=inf,tmp=0;
		for(int i=1;i<=n;++i) if(!vis[i])
		{
			double val=getdis(now,i);
			dis[i]=dis[now]+val;
			if(dis[i]<minn) minn=dis[i],tmp=i;
		}
		cout<<now<<' '<<tmp<<' '<<minn<<"!!"<<endl;
		now=tmp;
		++num;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].x>>a[i].y;
	}
	cin>>st.x>>st.y>>ed.x>>ed.y;
	a[++n]=ed;
	a[++n]=st;
	cin>>v1>>v2;
	prim();
	cout<<fixed<<setprecision(10)<<dis[n-1]<<'\n';
	return 0;
}
/*
5
1 2 4 50 5


*/