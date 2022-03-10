#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

using wEdge=pair<int,long long>;
struct wGraph:public vector<vector<wEdge>>{
	int n;
	wGraph(int n):vector<vector<wEdge>>(n+1),n(n){}
	void add(int u,int v,long long w){
		operator[](u).emplace_back(wEdge(v,w));
	}
};

// SPFA算法 O(k*m)
struct SSSP{
	static constexpr long long INF=0x3f3f3f3f3f3f3f3f;
	vector<long long>dis; vector<char> vis;
	vector<int>cnt; vector<int>pre;
	bool neg;
	SSSP(wGraph&G,int s):dis(G.n+1,INF),vis(G.n+1),cnt(G.n+1),pre(G.n+1),neg(0){
		queue<int>q;
		dis[s]=0;
		for(int i=1;i<=G.n;++i){
			q.push(i);
			cnt[i]=vis[i]=1;
		}
		while(!q.empty()){
			int u=q.front(); q.pop();
			vis[u]=false;
			for(auto [v,w]:G[u]){
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					pre[v]=u;
					cnt[v]=cnt[u]+1;
					if(cnt[v]>G.n){
						neg=true;
						return ;
					}
					if(!vis[v]){
						q.push(v);
						vis[v]=true;
					}
				}
			}
		}
	}
};

signed main(){
	int n,m,s;
	scanf("%lld%lld%lld",&n,&m,&s);
	wGraph G(n);
	for(int i=1;i<=m;++i){
		int u,v,d;
		scanf("%lld%lld%lld",&u,&v,&d);
		G.add(u,v,d);
	}
	SPFA sssp(G,s);
	if(sssp.neg)
		puts("-1");
	else{
		for(int i=1;i<=n;++i){
			if(sssp.dis[i]>SPFA::INF/2)
				puts("NoPath");
			else
				printf("%lld\n",sssp.dis[i]);	
		}
	}
	return 0;
}

