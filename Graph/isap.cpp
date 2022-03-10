#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define all(x) (x).begin(),(x).end()

template<typename Info=int>
struct Graph{
	vector<int>head,nxt; vector<Info>to; int tot,n;
	struct EdgeSet{
		int u; Graph&G;
		EdgeSet(int u,Graph&G):u(u),G(G){ }
		struct Iter{
			int idx; Graph&G;
			Iter(int idx,Graph&G):idx(idx),G(G){ }
			pair<Info&,int> operator*(){ 
				return pair<Info&,int>(G.to[idx],idx); }
			void operator++(){ idx=G.nxt[idx]; }
			bool operator!=(Iter&o){ return idx!=o.idx; }
		};
		Iter begin(){ return Iter(G.head[u],G); }
		Iter end(){ return Iter(-1,G); }
	};
	explicit Graph(int n):head(n+1,-1),tot(0),n(n){ }
	EdgeSet operator[](int x){ return EdgeSet(x,*this); }
	void add(int u,const Info& v){ nxt.emplace_back(head[u]); 
		to.emplace_back(v); head[u]=tot++; }
	Graph& operator=(const Graph&G){
		head=G.head,nxt=G.nxt,to=G.to;
		tot=G.tot,n=G.n; return *this; }
};

template<typename Fint>
struct flow_edge{
	int v; Fint w;
	flow_edge(int v,Fint w):v(v),w(w){ }
};

// isap algorithm O(n^2m) => maxFlow
template<typename Fint>
Fint isap(Graph<flow_edge<Fint>>&G,int s,int t){
	const Fint INF=numeric_limits<Fint>::max();
	int n=G.n;
	vector<int>cur,ht(n+1),gap(n+3);
	auto bfs=[&](){
		queue<int>q; q.push(t);
		gap[ht[t]=1]=1;
		while(!q.empty()){
			int u=q.front(); q.pop();
			for(auto [e,idx]:G[u]){
				if(G.to[idx^1].w&&!ht[e.v]){
					gap[ht[e.v]=ht[u]+1]++;
					q.push(e.v);
				}
			}
		}
	};
	function<Fint(int,Fint)> dfs=[&](int u,Fint f){
		if(u==t) return f;
		Fint x=0;
		for(int& idx=cur[u];~idx;idx=G.nxt[idx]){
			auto [v,w]=G.to[idx];
			if(w&&ht[u]-1==ht[v]){
				Fint g=dfs(v,min(w,f-x));
				if(g){
					G.to[idx].w-=g;
					G.to[idx^1].w+=g;
					x+=g;
				}
			}
			if(x==f) return x;
		}
		if(--gap[ht[u]]) ++gap[++ht[u]];
		else ht[s]=n+1;
		return x;
	};
	bfs();
	Fint f=0;
	while(ht[s]<=n){
		cur=G.head;
		f+=dfs(s,INF);
	}
	return f;
}

int32_t main(){
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	Graph<flow_edge<int>>G(n);
	for(int i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G.add(u,{v,w});
		G.add(v,{u,0});
	}
	printf("%lld\n",isap(G,s,t));
	return 0;
}