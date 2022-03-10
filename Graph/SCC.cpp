#include<bits/stdc++.h>
using namespace std;


#define all(x) x.begin(),x.end()

struct Graph:public vector<vector<int>>{
	int n; vector<int>w;
	Graph(int n):vector<vector<int>>(n+1),n(n),w(n+1){}
	void add(int u,int v){
		operator[](u).emplace_back(v);
	}
};

// 求有向图的强连通分量
// tarjan算法 O(n+m)
struct SCC{
	vector<int>dfn,low,stk,col; // dfn->时间戳,col->所属强连通分量的标号,low->临时组号,stk->辅助栈
	vector<char>ins; // ins->记录是否在栈中
	int num,cnt; // num->强连通分量的数量,cnt->临时编号
	Graph scc;
	SCC(Graph&G):dfn(G.n+1),low(G.n+1),col(G.n+1),ins(G.n+1),num(0),cnt(0),scc(0){
		auto tarjan=[&](auto&&self,int u)->void{
			stk.emplace_back(u);
			dfn[u]=low[u]=++cnt;
			ins[u]=true;
			for(auto v:G[u]){
				if(!dfn[v]){
					self(self,v);
					low[u]=min(low[u],low[v]);
				}else if(ins[v])
					low[u]=min(low[u],dfn[v]);
			}
			if(dfn[u]==low[u]){
				++num;
				for(int lst=0;lst!=u;stk.pop_back()){
					lst=stk.back();
					col[lst]=num;
					ins[lst]=false;
				}
			}
		};
		for(int i=1;i<=G.n;++i)
			if(!dfn[i])
				tarjan(tarjan,i);
		scc=Graph(num);
		for(int u=1;u<=G.n;++u)
			for(int v:G[u])
				if(col[u]!=col[v])
					scc.add(col[u],col[v]);
		for(int i=1;i<=G.n;++i)
			scc.w[col[i]]+=G.w[i];
		for(int u=1;u<=num;++u){
			sort(all(scc[u]));
			scc[u].erase(unique(all(scc[u])),scc[u].end());
		}
	}
};


int main(){
	return 0;
}