#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

struct Graph:public vector<vector<int>>{ // 存A集合指向B集合的边
	int n1,n2; // n1->A集合大小，n2->B集合大小
	Graph(int n1,int n2):vector<vector<int>>(n1+1),n1(n1),n2(n2){}
	void add(int u,int v){
		operator[](u).emplace_back(v);
	}
};

// 匈牙利算法 => 最大二分匹配 O(n*m)
struct MaximalMatching{
	vector<char>vis; // 辅助vis数组，代表B集合的元素是否已经匹配
	vector<int>match; // 答案数组，代表B集合的元素匹配对象是谁
	int cnt; // 最大匹配数
	MaximalMatching(Graph&G):vis(G.n2+1),match(G.n2+1),cnt(0){
		auto dfs=[&](auto&&self,int a)->bool{
			for(int b:G[a]){
				if(vis[b])
					continue;
				vis[b]=true;
				if(match[b]==0||self(self,match[b])){
					match[b]=a;
					return 1;
				}
			}
			return 0;
		};
		for(int i=1;i<=G.n1;++i){
			fill(all(vis),0);
			if(dfs(dfs,i))
				++cnt;
		}
	}
};

signed main(){
	
	return 0;
}


