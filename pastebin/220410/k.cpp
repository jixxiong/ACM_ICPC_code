#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,mod=1e9+7,inf=INT_MAX;
	int n,maxn;
	int p[N];
	int st[N],top;
	int id[N];
	int pre[N],nxt[N];
	bool vis[N];
	typedef pair<int,int> pr;
	vector<pr> ans[N];
	inline void swap(int &x,int &y)
	{
		x^=y^=x^=y;
	}
	inline void solve(int num,int dep,int qd)
	{
		if(num<=1) return;
		maxn=max(maxn,dep);
		int now=qd,tmp=nxt[qd],td=tmp,len=0;
		vector<int> qwq;
		while("qaq")
		{
			ans[dep].push_back(pr(id[now],id[tmp]));

			int o=nxt[nxt[now]],op=nxt[nxt[tmp]];
			swap(id[now],id[tmp]);
			qwq.push_back(now);
			// nxt[pre[now]]=nxt[now];
			// pre[nxt[now]]=pre[now];
			now=o;
			tmp=op;
			len+=2;
			if(len>=num-1) break;
		}
		for(int now:qwq)
		{
			nxt[pre[now]]=nxt[now];
			pre[nxt[now]]=pre[now];
		}
		//int td=(now==qd?tmp:now);
		solve(num-num/2,dep+1,td);
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>p[i];
			id[p[i]]=i;
		}
		for(int i=1;i<=n;++i) if(!vis[i])
		{
			top=0;
			st[++top]=i;
			vis[i]=1;
			int now=p[i];
			while(now!=i)
			{
				vis[now]=1;
				st[++top]=now;
				now=p[now];
			}
			st[0]=st[top];
			st[top+1]=st[1];
			for(int k=1;k<=top;++k)
			{
				pre[st[k]]=st[k-1];
				nxt[st[k]]=st[k+1];
				//cout<<st[k]<<' '<<pre[st[k]]<<' '<<nxt[st[k]]<<"!!!"<<endl;
			}
			solve(top,1,st[1]);
		}
		cout<<maxn<<'\n';
		for(int i=1;i<=maxn;++i)
		{
			cout<<ans[i].size()<<' ';
			for(pr t:ans[i])
			{
				if(t.first>t.second)swap(t.first,t.second);
				cout<<t.first<<' '<<t.second<<' ';
			}
			cout<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
8
2 3 4 5 6 7 8 1

*/
