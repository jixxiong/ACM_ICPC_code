#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

using wEdge=pair<int,long long>;
struct wGraph:public vector<vector<wEdge>>{
	int n;
	wGraph(int n):vector<vector<wEdge>>(n+1),n(n){}
	void add(int u,int v,long long w){
		operator[](u).emplace_back(wEdge{v,w});
	}
};

// Prim 算法 O(n^2)
struct MST{
	static constexpr long long INF=0x3f3f3f3f3f3f3f3f;
	vector<char>vis; vector<long long>dis;
	vector<int>pre; long long cost;
	MST(wGraph& G):vis(G.n+1),dis(G.n+1,INF),pre(G.n+1),cost(0){
		dis[1]=0;
		for(int i=1;i<G.n;++i){
			int u=0;
			for(int j=1;j<=G.n;++j)
				if(!vis[j]&&(u==0||dis[j]<dis[u]))
					u=j;
			vis[u]=true;
			for(auto [v,w]:G[u])
				if(!vis[v])
					dis[v]=min(dis[v],w),pre[v]=u;
		}
		for(int i=1;i<=G.n;++i){
			if(dis[i]>=INF){
				cost=INF;
				return ;
			}
			cost+=dis[i];
		}
	}
};

signed main(){

	return 0;
}