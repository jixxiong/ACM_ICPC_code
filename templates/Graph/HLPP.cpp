#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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

// HLPP algorithm O(n^2sqrt(m)) => maxFlow
template<typename Fint>
Fint hlpp(Graph<flow_edge<Fint>>&G,int s,int t){
	int maxht(0),maxgap(0),cnt(0),n(G.n);
	vector<Fint>ex(n+1);
	vector<int>ht(n+1),cur(G.head),gap(n+1,-1);
	vector<int>exList(n+1,-1),exNxt(n+1,-1);
	vector<int>gapPrv(n+1,-1),gapNxt(n+1,-1);
	auto ass=[&](auto&arr,auto val){ fill(all(arr),val); };
	auto setHt=[&](int u,int h){
		if(~gapPrv[u]){
			if(gapPrv[u]==u){
				gapPrv[gapNxt[u]]=gapNxt[u];
				gap[ht[u]]=gapNxt[u];
			}else{
				gapNxt[gapPrv[u]]=gapNxt[u];
				if(~gapNxt[u])
					gapPrv[gapNxt[u]]=gapPrv[u];
			}
		}
		if((ht[u]=h)>=n) return ;
		maxgap=max(maxgap,ht[u]);
		if(ex[u]>0){
			maxht=max(maxht,ht[u]);
			exNxt[u]=exList[ht[u]];
			exList[ht[u]]=u;
		}
		if(~(gapNxt[u]=gap[ht[u]]))
			gapPrv[gapNxt[u]]=u;
		gap[ht[u]]=gapPrv[u]=u;
	};
	auto relabel=[&](){
		cnt=maxht=maxgap=0;
		ass(ht,n),ass(gapPrv,-1),ass(gapNxt,-1),
		ass(gap,-1),ass(exList,-1),ass(exNxt,-1);
		cur=G.head; ht[t]=0;
		queue<int>q; q.push(t);
		while(!q.empty()){
			int u=q.front(); q.pop();
			for(auto [e,idx]:G[u]){
				int v=e.v;
				if(ht[v]==n&&v!=s&&G.to[idx^1].w>0)
					setHt(v,ht[u]+1), q.push(v);
			}
		}
	};
	auto push=[&](int u,int idx,Fint flow){
		auto& [v,w]=G.to[idx];
		auto& [_,bw]=G.to[idx^1];
		if(!ex[v]&&v!=t){
			exNxt[v]=exList[ht[v]];
			exList[ht[v]]=v;
		}
		w-=flow, bw+=flow;
		ex[u]-=flow, ex[v]+=flow;
	};
	auto discharge=[&](int u){
		int nh=n;
		for(int idx=cur[u];~idx;idx=G.nxt[idx]){
			auto& [v,w]=G.to[idx];
			if(w>0){
				if(ht[u]==ht[v]+1){
					push(u,idx,min(ex[u],w));
					if(ex[u]==0){
						cur[u]=idx;
						return ;
					}
				} else nh=min(nh,ht[v]+1);
			}
		}
		if(~cur[u])
			for(auto [e,idx]:G[u]){
				if(idx==cur[u])
					break;
				if(e.w>0)
					nh=min(nh,ht[e.v]+1);
			}
		cur[u]=G.head[u];
		++cnt;
		if(~gapNxt[gap[ht[u]]])
			setHt(u,nh);
		else{
			int ph=ht[u];
			for(int i=ph;i<=maxgap;++i){
				for(int j=gap[i];~j;j=gapNxt[j])
					ht[j]=n;
				gap[i]=-1;
			}
			maxgap=ph-1;
		}
	};
	relabel();
	for(auto [e,idx]:G[s]){
		auto&[v,w]=e;
		if(w){
			push(s,idx,w);
			maxht=max(maxht,ht[v]);
		}
	}
	for(;maxht>=0;--maxht){
		while(~exList[maxht]){
			int u=exList[maxht];
			exList[maxht]=exNxt[u];
			discharge(u);
			if(cnt>(n<<2))
				relabel();
		}
	}
	return ex[t];
}

int32_t main() {
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	Graph<pair<int, int>> G(n);
	for (int i = 1, u, v, w; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		G.add(u, {v, w});
		G.add(v, {u, 0});
	}
	printf("%d\n", HLPP(G,s,t));
	return 0;
}