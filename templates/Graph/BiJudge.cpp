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

// 染色法判二分图 O(n+m)
struct BiJudge{
	vector<char>col;
	bool fail;
	BiJudge(Graph&G):col(G.n+1),fail(false){
		auto dfs=[&](auto&&self,int u,int c)->void{
			col[u]=c;
			for(auto [va,idx]:G[u]){
				if(col[v]==0) 
					self(self,v,-c);
				else if(col[v]==c) 
					return fail=true,void();
			}
		};
		for(int i=1;i<=G.n;++i){
			if(col[i]==0){
				dfs(dfs,i,1);
				if(fail)
					return ;
			}
		}
	}
};

int main(){

	return 0;
}


/*

https://ac.nowcoder.com/acm/problem/19790

链接：https://ac.nowcoder.com/acm/problem/19790
来源：牛客网

修修在黑板上画了一些无向连通图，他发现他可以将这些图的结点用两种颜色染色，满足相邻点不同色。
澜澜不服气，在黑板上画了一个三个点的完全图。修修跟澜澜说，这个图我能找到一个简单奇环。
澜澜又在黑板上画了一个n个点m条边的无向连通图。很可惜这不是一道数数题，修修做不出来了。
澜澜非常得意，作为一位毒瘤出题人，有了好题当然要跟大家分享，于是他把这道题出给你做了。

如果你能把图二染色，第一行输出0，第二行输出n个整数x_1\sim x_nx 
表示每个点的颜色 (0≤ xi≤ 1)。如果有多种合法方案，你可以输出任意一种。
如果你能找到一个简单奇环，第一行输出环长k，第二行输出k个整数y_1\sim y_ky 
表示环上结点编号 (1≤ yi≤ n)，你需要保证yi和yi+1之间有边，y1和yn之间有边。如果有多种合法方案，你可以输出任意一种。
如果两种情况都是可行的，你只需要输出任意一种。
如果两种情况都是不可行的，请输出一行一个整数-1。

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

struct Graph:public vector<vector<int>>{
	int n;
	Graph(int n):vector<vector<int>>(n+1),n(n){}
	void add(int u,int v){
		operator[](u).emplace_back(v);
	}
};

struct Solution{
	vector<int>col;
	vector<int>pre;
	bool fail;
	Solution(Graph& G):col(G.n+1),pre(G.n+1),fail(false){
		auto dfs=[&](auto&&self,int u,int c)->void{
			col[u]=-c;
			for(int v:G[u]){
				if(fail)
					return ;
				if(col[v]==-c){
					vector<int>stk{v};
					for(int x=u;x!=v;x=pre[x])
						stk.emplace_back(x);
					fail=true;
					printf("%lld\n",(int)stk.size());
					for(auto x:stk){
						printf("%lld ",x);
					}
					return ;
				}
				if(!col[v]){
					pre[v]=u;
					self(self,v,-c);
					continue;
				}
			}
		};
		if(G.n==1){
			puts("-1");
			return ;
		}
		for(int i=1;i<=G.n;++i)
			if(!fail&&!col[i])
				dfs(dfs,i,1);
		if(!fail){
			puts("0");
			for(int i=1;i<=G.n;++i)
				printf(col[i]==1?"0 ":"1 ");
			puts("");
		}
	}
};

signed main(){
	int n,m;
	scanf("%lld%lld",&n,&m);
	Graph G(n);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%lld%lld",&u,&v);
		G.add(u,v);
		G.add(v,u);
	}
	Solution solution(G);
	return 0;
}

*/