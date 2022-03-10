#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; }
template<typename T,typename... Args>
void fo(T t,Args...args){ cerr<<t<<" "; fo(args...); }
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
	flow_edge(int v,int w):v(v),w(w){ }
};

// dinic O(n^2m) => maxflow
template<typename Fint>
Fint dinic(Graph<flow_edge<Fint>>&G,int s,int t){
	const Fint INF=numeric_limits<Fint>::max();
	int n=G.n; Fint ret=0;
	vector<int>cur,ht(n+1);
	auto bfs=[&](){
		fill(all(ht),0); ht[s]=1;
		queue<int>q; q.push(s);
		while(!q.empty()){
			int u=q.front(); q.pop();
			for(auto [e,idx]:G[u]){
				if(e.w&&!ht[e.v]){
					ht[e.v]=ht[u]+1;
					q.push(e.v);
					if(e.v==t)
						return 1;
				}
			}
		}
		return ht[t];
	};
	function<Fint(int,Fint)>dfs=[&](int u,Fint flow){
		if(u==t)
			return flow;
		Fint x=0;
		for(auto [e,idx]:G[u]){
			if(e.w&&ht[e.v]==ht[u]+1){
				Fint f=dfs(e.v,min(flow,e.w));
				G.to[idx].w-=f; flow-=f;
				G.to[idx^1].w+=f; x+=f; 
				if(flow<=0)
					break;
			}
		}
		return x;
	};
	while(bfs()){
		cur=G.head;
		ret+=dfs(s,INF);
	}
	return ret;
}



int32_t main(){
	
	return 0;
}