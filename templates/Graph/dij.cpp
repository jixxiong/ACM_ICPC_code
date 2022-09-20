#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

template<typename info=int>
struct Graph{
    int n,c; // n => number of nodes, c => number of edges
    std::vector<int>h; // h[i] => the index of the first edge starting from i
    std::vector<int>f; // f[i] => the index of the edge next to edge i
    std::vector<info>e; // e[i] => the information of the i-th edge
    Graph(int n):n(n),c(0),h(n+1,-1){}
    void add(int u,const info&i){ // adding a new edge, u => starting point, i => infomation of the edge
        f.pb(h[u]); h[u]=c++; e.pb(i);
    }
};


template<typename Fint=ll,typename info=std::pair<int,ll>>
struct dijk:std::vector<Fint>{
    // dis[i]=> the minium distance from starting point s to i
    // G => the graph, s => starting point
    dijk(Graph<info>&G,int s):std::vector<Fint>(G.n+1,std::numeric_limits<Fint>::max()){
        auto& dis=*this;
        using node=std::pair<Fint,int>;
        std::priority_queue<node> q;
        q.push(node(0,s));
        dis[s]=0;
        while(!q.empty()){
            auto [fi,u]=q.top(); q.pop();
            if(dis[u]!=-fi) continue;
            for(int idx=G.h[u];~idx;idx=G.f[idx]){
                auto [v,w]=G.e[idx];
                if(dis[u]+w<dis[v]) q.push(node(-(dis[v]=dis[u]+w),v));
            }
        }
    }
};

int main(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	Graph<std::pair<int,ll>>G(n);
	for(int i=1;i<=m;++i){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		G.add(u,{v,d});
	}
	dijk A(G,s);
	for(int i=1;i<=n;++i)
		printf("%lld ",A[i]==std::numeric_limits<ll>::max()?-1:A[i]);
	return 0;
}