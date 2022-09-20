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

template<typename Fint=int,typename Cint=Fint>
struct mcf_edge{
	int v; Fint w; Cint c;
	mcf_edge(int v,Fint w,Cint c):v(v),w(w),c(c){ }
};

template<typename Fint=int,typename Cint=Fint>
pair<Fint,Cint> mcf(Graph<mcf_edge<Fint,Cint>>&G,int s,int t){
	const Fint FINF=numeric_limits<Fint>::max();
	const Cint CINF=-1e18; // Cint doubld=>-1e18
	int n=G.n; Fint mf=0; Cint mc=0;
	vector<char>vis(n+1); 
	vector<Cint>dis(n+1);
	vector<int>cur; 
	auto spfa=[&](){
		fill(all(vis),0); fill(all(dis),CINF);
		queue<int>q; q.push(s); dis[s]=0;
		while(!q.empty()){
			int u=q.front(); q.pop(); vis[u]=false;
			for(auto [e,idx]:G[u]){
				auto [v,w,c]=e;
				if(w&&dis[v]<dis[u]+c){
					dis[v]=dis[u]+c;
					if(!vis[v]) q.push(v),vis[v]=true;
				}
			}
		}
		return dis[t]!=CINF;
	};
	function<Fint(int,Fint)>dfs=[&](int u,Fint flow){
		vis[u]=true;
		if(u==t) return flow;
		Fint past=0;
		for(int& idx=cur[u];~idx;idx=G.nxt[idx]){
			auto [v,w,c]=G.to[idx];
			if(!vis[v]&&w&&dis[v]==dis[u]+c){
				Fint x=dfs(v,min(flow,w));
				if(x>0){
					G.to[idx].w-=x; G.to[idx^1].w+=x;
					past+=x; flow-=x; mc+=x*c;
					if(flow==0) return past;
				}
			}
		}
		return past;
	};
	while(spfa()){
		cur=G.head;
		do{
			fill(all(vis),0);
			mf+=dfs(s,FINF);
		}while(vis[t]);
	}
	return {mf,mc};
}



























































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
};

template<typename Fint=int>
struct mcf_edge{
	int v; Fint w,c;
	mcf_edge(int v,Fint w,Fint c):v(v),w(w),c(c){ }
};

// dij+EK
template<typename Fint=int>
pair<Fint,Fint> mcf(Graph<mcf_edge<Fint>>&G,int s,int t){
	const Fint INF=(Fint)0x7f7f7f7f7f7f7f7f;
	int n=G.n;
	Fint mf=0,mc=0;
	vector<int>cur(n+1);
	vector<char>vis(n+1);
	vector<Fint>d(n+1),h(n+1);
	auto Dijkstra=[&]()->bool{
		priority_queue<pair<Fint,int>>pq;
		fill(all(d),INF);
		pq.push({d[s]=0,s});
		while(!pq.empty()){
			auto [fi,u]=pq.top(); pq.pop();
			if(-fi>d[u]) continue;
			for(auto [e,idx]:G[u]){
				auto [v,w,c]=e; c+=h[u]-h[v];
				if(w&&d[v]>d[u]+c)
					pq.push({-(d[v]=d[u]+c),v});
			}
		}
		return d[t]<INF;
	};
	function<Fint(int,Fint)>dfs=[&](int u,Fint flow){
		if(u==t) return flow;
		Fint rest=flow; vis[u]=1;
		for(int &idx=cur[u];~idx&&rest;idx=G.nxt[idx]){
			auto [v,w,c]=G.to[idx]; c+=h[u]-h[v];
			if(!vis[v]&&w&&d[u]+c==d[v]){
				Fint x=dfs(v,min(rest,w));
				rest-=x;
				G.to[idx].w-=x;
				G.to[idx^1].w+=x;
			}
		}
		vis[u]=0;
		return flow-rest;
	};
	while(Dijkstra()){
		copy(all(G.head),cur.begin());
		Fint c=dfs(s,INF);
		for(int i=1;i<=n;++i)
			if(d[i]<INF)
				h[i]+=d[i];
		mf+=c;
		mc+=c*h[t];
	}
	return {mf,mc};
}

// 对偶算法
template<typename Fint>
pair<Fint,Fint> mcf(Graph<mcf_edge<Fint>>&G,int s,int t){
	const Fint INF=(Fint)0x7f7f7f7f7f7f7f7f;
	int n=G.n;
	Fint maxf=0,minc=0;
	vector<Fint>h(n+1,INF);
	vector<pair<int,int>>p(n+1);
	vector<Fint>dis(n+1);
	auto spfa=[&](){
		queue<int>q;
		vector<char>vis(n+1);
		h[s]=0, vis[s]=1;
		q.push(s);
		while(!q.empty()){
			int u=q.front();q.pop();
			vis[u]=0;
			for(auto [e,idx]:G[u]){
				auto [v,w,c]=e;
				if(w&&h[v]>h[u]+c){
					h[v]=h[u]+c;
					if(!vis[v]){
						vis[v]=1;
						q.push(v);
					}
				}
			}
		}
	};
	auto dijkstra=[&](){
		priority_queue<pair<Fint,int>>q;
		fill(all(dis),INF);
		q.push({dis[s]=0,s});
		while(!q.empty()){
			auto [fi,u]=q.top(); q.pop();
			if(-fi!=dis[u])
				continue;
			for(auto [e,idx]:G[u]){
				auto [v,w,c]=e; c+=h[u]-h[v];
				if(w&&dis[v]>dis[u]+c){
					p[v]={u,idx};
					q.push({-(dis[v]=dis[u]+c),v});
				}
			}
		}
		return dis[t]<INF;
	};
	spfa();
	while(dijkstra()){
		Fint minf=INF;
		for(int i=1;i<=n;++i)
			h[i]+=dis[i];
		for(int i=t;i!=s;i=p[i].first)
			minf=min(minf,G.to[p[i].second].w);
		for(int i=t;i!=s;i=p[i].first){
			G.to[p[i].second].w-=minf;
			G.to[p[i].second^1].w+=minf;
		}
		maxf+=minf;
		minc+=minf*h[t];
	}
	return {maxf,minc};
}


int32_t main(){
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	Graph<mcf_edge<int>>G(n);
	for (int i=1;i<=m;++i) {
		int u,v;
		int c,w;
		scanf("%d%d%d%d",&u,&v,&w,&c);
		G.add(u,{v,w,c});
		G.add(v,{u,0,-c});
	}
	auto [f,c]=MCF(G,s,t);
	printf("%d %d\n",f,c);
	return 0;
}