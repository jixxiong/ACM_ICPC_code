#include<bits/stdc++.h>
using namespace std;


struct Graph:public vector<vector<int>>{
	int n;
	Graph(int n):vector<vector<int>>(n+1),n(n){}
	void add(int u,int v){
		operator[](u).emplace_back(v);
	}
};


// 点割集 tarjan算法 O(n+m)
struct CutVertex{
	vector<int>dfn,low,ans;
	vector<char>cut;
	int num,cnt;
	CutVertex(Graph& G):dfn(G.n+1),low(G.n+1),ans(),cut(G.n+1),num(0),cnt(0){
		auto tarjan=[&](auto&&self,int u,int fa)->void{
			dfn[u]=low[u]=++cnt;
			int s=0;
			for(int v:G[u]){
				if(!dfn[v]){
					self(self,v,fa);
					low[u]=min(low[u],low[v]);
					if(u!=fa&&low[v]>=dfn[u])
						cut[u]=true;
					if(u==fa)
						s++;
				}
				low[u]=min(low[u],dfn[v]);
			}
			if(u==fa&&s>=2)
				cut[fa]=true;
		};
		for(int i=1;i<=G.n;++i)
			if(!dfn[i])
				tarjan(tarjan,i,i);
		for(int i=1;i<=G.n;++i)
			if(cut[i])
				ans.emplace_back(i);
	}
};


int main(){
	return 0;
}