#include<bits/stdc++.h>
using namespace std;

template<typename Info=int>
struct Graph{
	vector<int>head,nxt; vector<Info>to; int tot,n;
	struct EdgeSet{
		int u; Graph&G;
		EdgeSet(int u,Graph&G):u(u),G(G){ }
		struct Iter{
			int idx; Graph&G;
			Iter(int idx,Graph&G):idx(idx),G(G){ }
			Info& operator*(){ return G.to[idx]; }
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


// Dijkstral 算法 O(mlogm)
struct SSSP{
	static constexpr long long INF=0x3f3f3f3f3f3f3f3f;
	vector<long long>d;
	template<typename Info>
	SSSP(Graph<Info>& G,int s):d(G.n+1,INF){
		using Node=pair<long long,int>;
		priority_queue<Node>q;
		q.push(Node(0,s));
		d[s]=0;
		while(!q.empty()){
			Node cur=q.top();q.pop();
			int u=cur.second;
			if(d[u]!=-cur.first)
				continue;
			for(auto [v,w]:G[u]){
				if(d[u]+w<d[v]){
					d[v]=d[u]+w;
					q.push({-d[v],v});
				}
			}
		}
	}
};

int main(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	Graph<array<int,2>>G(n);
	for(int i=1;i<=m;++i){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		G.add(u,{v,d});
	}
	SSSP A(G,s);
	for(int i=1;i<=n;++i)
		printf("%lld ",A.d[i]==SSSP::INF?-1:A.d[i]);
	return 0;
}