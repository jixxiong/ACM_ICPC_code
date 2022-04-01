// nowcoder 14612
// acam + dfn + fenwick

#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

template<const int sigma=26>
struct ACAM{
	using Node=std::array<int,sigma>;
	std::vector<Node>nxt;
	std::vector<int>fail;    // fail ָ指针
	std::vector<int>occ;     // 字符串信息
	std::vector<int>endpos;  // 字符串结束位置
	int tot;
	int trans(char ch){
		return ch-'a'; 
	}
	int new_node(){
		nxt.pb(Node{});
		occ.pb(0);
		return ++tot;
	}
	ACAM():nxt(1),occ(1),endpos(1),tot(0){}
	void insert(const char* s,int n){
		int p=0;
		for(int i=1;i<=n;++i){
			auto ch=trans(s[i]);
			if(!nxt[p][ch]) nxt[p][ch]=new_node();
			p=nxt[p][ch];
		}
		endpos.pb(p);
		occ[p]++;
	}
	void build(){
		std::queue<int>q; fail.resize(tot+1);
		for(int i=0;i<sigma;++i)
			if(nxt[0][i])
				q.push(nxt[0][i]);
		while(!q.empty()){
			int u=q.front(); q.pop();
			for(int i=0;i<sigma;++i)
				if(nxt[u][i])
					fail[nxt[u][i]]=nxt[fail[u]][i], q.push(nxt[u][i]);
				else
					nxt[u][i]=nxt[fail[u]][i];
		}
	}
};

struct Fenwick{
	std::vector<int>arr;
	int n;
	Fenwick(int n):arr(n+1),n(n){} 
	void add(int x,int v){
		for(;x<=n;x+=x&-x) arr[x]+=v;
	}
	int get(int x){
		int ret=0;
		for(;x>0;x-=x&-x) ret+=arr[x];
		return ret;
	}
};

struct Solution:ACAM<26>{
	Solution():ACAM<26>(){
		int n,m; std::cin>>n>>m;
		std::vector<std::pair<int,std::string>>qry(n+m+1);
		for(int i=1;i<=n;++i){
			std::cin>>qry[i].second;
			qry[i].first=1;
			insert(&qry[i].second[0]-1,qry[i].second.length());
		}
		for(int i=n+1;i<=n+m;++i){
			std::cin>>qry[i].first>>qry[i].second;
			if(qry[i].first==1){
				insert(&qry[i].second[0]-1,qry[i].second.length());
			}
		}
		build();
		std::vector<std::vector<int>>G(tot+1);
		std::vector<int>L(tot+1),R(tot+1);
		Fenwick bit(tot+2);
		for(int i=1;i<=tot;++i) G[fail[i]].pb(i);
		int tic=0;
		std::function<void(int)> dfs=[&](int u){
			L[u]=++tic;
			for(auto v:G[u]){
				dfs(v);
			}
			R[u]=tic;
		};
		dfs(0);
		auto query=[&](char* s,int n){
			int p=0,ret=0;
			for(int i=1;i<=n;++i){
				p=nxt[p][trans(s[i])];
				ret+=bit.get(L[p]);
			}
			return ret;
		};
		for(int i=1,cnt=0;i<=n+m;++i){
			if(qry[i].first==1){
				int p=endpos[++cnt];
				bit.add(L[p],1);
				bit.add(R[p]+1,-1);
			}else{
				std::cout<<query(&qry[i].second[0]-1,qry[i].second.length())<<'\n';
			}
		}
	}
};

int main(){
	int T; std::cin>>T;
	while(T--){
		Solution();
		// fk("---------------");
	}
	return 0; 
}