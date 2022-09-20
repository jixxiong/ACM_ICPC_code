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


// 倍增法LCA O(log)查询 O(nlogn)初始化
struct LCA{
	int n;
	vector<vector<int>>st; vector<int>d;
	LCA(Graph<int>& G,int root):n(G.n),st(n+1,vector<int>(__lg(n+1)+1)),d(n+1){
		auto dfs=[&](auto&&self,int u,int f)->void{
			for(auto [v,_]:G[u]){
				if(v==f)
					continue;
				d[v]=d[u]+1;
				st[v][0]=u;
				for(int k=1;k<=__lg(d[v]);++k)
					st[v][k]=st[st[v][k-1]][k-1];
				self(self,v,u);
			}
		};
		d[root]=1;
		dfs(dfs,root,root);
	}
	int lca(int x,int y){
		if(d[x]>d[y])
			swap(x,y);
		for(int i=__lg(n);i>=0;--i)
			if(d[x]<=d[st[y][i]])
				y=st[y][i];
		if(x==y)
			return x;
		for(int i=__lg(n);i>=0;--i)
			if(st[x][i]!=st[y][i])
				x=st[x][i],y=st[y][i];
		return st[x][0];
	}
};

int main() {
	int n, m, rt;
	scanf("%d%d%d", &n, &m, &rt);
	Graph G(n);
	for (int i=1;i<n;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		G.add(u,v);
		G.add(v,u);
	}
	LCA A(G,rt);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", A.lca(x, y));
	}
	return 0;
}