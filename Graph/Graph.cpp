#include<bits/stdc++.h>
using namespace std;

using wEdge=pair<int,long long>;
struct wGraph:public vector<vector<wEdge>>{
	int n;
	wGraph(int n):vector<vector<wEdge>>(n+1),n(n){}
	void add(int u,int v,long long w){
		operator[](u).emplace_back({v,w});
	}
};


struct Graph:public vector<vector<int>>{
	int n;
	Graph(int n):vector<vector<int>>(n+1),n(n){}
	void add(int u,int v){
		operator[](u).emplace_back(v);
	}
};

 
// good one go go go
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
	void clr(int n=0){ head=vector<int>(n,-1); tot=0;
		vector<int>().swap(nxt); vector<Info>().swap(to); }
	void unique(){
		vector<vector<Info>>G(n+1);
		for(int i=0;i<=n;++i)
			for(auto v:operator[](i))
				G[i].emplace_back(v);
		clr(n);
		for(int i=0;i<=n;++i){
			sort(all(G[i]));
			G[i].erase(unique(all(G[i])),G[i].end());
			for(auto v:G[i]) add(i,v);
		}
	}
};

template<typename Info=int>
struct Graph {
	vector<int> head, nxt;
	vector<Info> to;
	int tot, n;

	struct EdgeSet {
		int u;
		Graph &G;

		EdgeSet(int u, Graph &G) : u(u), G(G) {}

		struct Iter {
			int idx;
			Graph &G;

			Iter(int idx, Graph &G) : idx(idx), G(G) {}

			pair<Info &, int> operator*() {
				return pair<Info &, int>(G.to[idx], idx);
			}

			void operator++() { idx = G.nxt[idx]; }

			bool operator!=(Iter &o) { return idx != o.idx; }
		};

		Iter begin() { return Iter(G.head[u], G); }

		Iter end() { return Iter(-1, G); }
	};

	explicit Graph(int n) : head(n + 1, -1), tot(0), n(n) {}

	EdgeSet operator[](int x) { return EdgeSet(x, *this); }

	void add(int u, const Info &v) {
		nxt.emplace_back(head[u]);
		to.emplace_back(v);
		head[u] = tot++;
	}
};