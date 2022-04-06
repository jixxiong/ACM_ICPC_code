#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=8e5+10;
const int mod=1231453023109121,g=3;
int n,m;
int a[N],b[N],p[N];
bool vis[N];
int st[N],top;
int c[N],tot;
vector<int> f[N];
inline int slow(int a,int b)
{
    return (int)((__int128_t)a*b%mod);
}
inline int fast(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1) ret=slow(ret,x);
		x=slow(x,x);
		k>>=1;
	}
	return ret;
}
int gi=fast(g,mod-2);
namespace NTT
{
	
	int limit,len;
	int pos[N],a[N],b[N];
	inline void ntt(int *a,int inv)
	{
		for(int i=0;i<limit;++i)
			if(i<pos[i]) swap(a[i],a[pos[i]]);
		for(int mid=1;mid<limit;mid<<=1)
		{
			int Wn=fast(inv?g:gi,(mod-1)/(mid<<1));
			//cout<<inv<<' '<<Wn<<"!!"<<endl;
			for(int r=mid<<1,j=0;j<limit;j+=r)
			{
				int w=1;
				for(int k=0;k<mid;++k,w=slow(w,Wn))
				{
					int x=a[j+k],y=slow(w,a[j+k+mid]);
					a[j+k]=x+y;
					if(a[j+k]>=mod) a[j+k]-=mod;
					a[j+k+mid]=x-y;
					if(a[j+k+mid]<0) a[j+k+mid]+=mod;
				}
			}
		}
		if(inv) return;
		inv=fast(limit,mod-2);
		//cout<<inv<<"!!"<<endl;
		for(int i=0;i<limit;++i) a[i]=slow(a[i],inv);
	}
	inline void mul(int *aa,int *bb,int n,int m)
	{
		limit=1,len=0;
		for(int i=0;i<n;++i) a[i]=aa[i];
		for(int i=0;i<m;++i) b[i]=bb[i];
		while(limit<n+m) limit<<=1,++len;
		for(int i=n;i<limit;++i) a[i]=0;
		for(int i=m;i<limit;++i) b[i]=0;
		for(int i=0;i<limit;++i)
			pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
		//cout<<"!!"<<endl;
		ntt(a,1);ntt(b,1);
		//cout<<"??"<<endl;
		for(int i=0;i<limit;++i) a[i]=slow(a[i],b[i]);
		//	cout<<"qaq"<<"!!"<<endl;
		ntt(a,0);
		for(int i=0;i<limit;++i) aa[i]=a[i];
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		int x;cin>>x;
		p[x]=i;
	}
	for(int i=1;i<=n;++i) if(!vis[i])
	{
		top=0;
		int x=i;
		st[top++]=x;
		vis[x]=1;
		while(!vis[p[x]])
		{
			x=p[x];
			st[top++]=x;
			vis[x]=1;
		}
		for(int j=0;j<top;++j) {b[j]=st[j];}
		for(int j=top;j<top+top;++j) st[j]=st[j-top];
		st[top+top]=0;
		reverse(b,b+top);
		NTT::mul(b,st,top,top*2);
		c[++tot]=top;
		f[top].resize(top);
		for(int j=top-1,k=0;k<top;++j,++k)
		{
			//<<b[j]<<"!!"<<endl;
			f[top][k]+=b[j];
		}
	}
	sort(c+1,c+tot+1);
	tot=unique(c+1,c+tot+1)-c-1;
	for(int i=1;i<=m;++i)
	{
		int x;cin>>x;
		int ans=0;
		for(int k=1;k<=tot;++k)
		{
			int len=c[k];
			int tmp=x%len;
			ans+=f[len][tmp];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 5
2 1 4 3
1
2
3
4
0

*/