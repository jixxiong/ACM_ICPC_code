#include<bits/stdc++.h>

int N=500;

int mp[N+1][N+1]; 
// 空间复杂度 O(n^2), 时间复杂度 O(n^2) 点数少可以用，适合稠密的图，不适合稀疏图（点数多而边数少的图）

struct Edge{
	int v;
	int d;
};

// 邻接表
std::vector<Edge> adj[10];

int main(){
	adj[1].push_back(Edge{2,10});
	adj[1].push_back(Edge{3,30});
	// u -> v, 边权是 d
	int u,v,d; std::cin>>u>>v>>d;
	adj[u].push_back(Edge{v,d});
	// 如果是无向图的话,还有一条 v -> u 的边
	adj[v].push_back(Edge{u,d});
	return 0;
}