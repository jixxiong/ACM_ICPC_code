/**
 * 
 * 只用从源点开始dfs沿着残量大于0的边走一路标记源点集合即可
 * 
 * 
 */

vector<char>vis(n+1);

void dfs(int u){
	vis[u]=true;
	for(auto [e,idx]:G[u]){
		if(!vis[e.v]&&e.w){
			dfs(e.v);
		}
	}
}