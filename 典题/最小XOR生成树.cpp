#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

template<int int_len=30>
struct Trie{
	using Node=array<int,2>;
	vector<int> cnt;
	vector<int> end;
	vector<Node> nxt;
	int tot;
	Trie():cnt(1),end(1),nxt(1),tot(0){ }
	inline int new_node(){
		cnt.emplace_back(0);
		nxt.emplace_back(Node{});
		return ++tot;
	}
	void insert(int x,int j){
		int p=0;
		for(int i=int_len;i>=0;--i){
			auto ch=(x>>i)&1;
			if(!nxt[p][ch])
				nxt[p][ch]=new_node();
			p=nxt[p][ch];
			cnt[p]++;
		}
		end[p]=j;
	}
	void remove(int x){
		int p=0;
		for(int i=int_len;i>=0;--i){
			auto ch=(x>>i)&1;
			p=nxt[p][ch];
			cnt[p]--;
		}
	}
	pair<int,int> query(int x){
		int p=0,ret=0;
		for(int i=int_len;i>=0;--i){
			auto ch=(x>>i)&1;
			if(nxt[p][ch]&&cnt[nxt[p][ch]]){
				p=nxt[p][ch];
			}else{
				ret|=1<<i;
				p=nxt[p][!ch];
			}
		}
		return {ret,end[p]};
	}
};

struct DSU:vector<int>{
	vector<int>&arr;
	DSU(int n):vector<int>(n),arr(*this){
		for(int i=0;i<n;++i)
			arr[i]=i;
	}
	int find(int x){
		return arr[x]==x?x:(arr[x]=find(arr[x]));
	}
	void merge(int x,int y){
		int fx=find(x),fy=find(y);
		if(fx!=fy)
			arr[fx]=fy;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int>A(n+1);
	Trie<30> trie;
	for(int i=1;i<=n;++i){
		scanf("%d",&A[i]);
		trie.insert(A[i],i);
	}
	vector<vector<int>>G(n); // 下标从0开始
	for(int i=1;i<=n;++i)
		G[i-1].emplace_back(i);
	ll ret=0;
	while(G.size()>1){
		set<array<int,3>>st;
		for(int i=0;i<(int)G.size();++i){
			for(auto x:G[i])
				trie.remove(A[x]);
			int mn=numeric_limits<int>::max();
			int k=-1;
			for(auto x:G[i]){
				auto [y,idx]=trie.query(x);
				if(y<mn){
					mn=y;
					k=idx;
				}
			}
			st.insert(array<int,3>{min(k,i),max(k,i),mn});
			for(auto x:G[i])
				trie.insert(A[x],x);
		}
		DSU dsu(G.size());
		for(auto v:st){
			ret+=v[2];
			dsu.merge(v[0],v[1]);
		}
		map<int,int>mp;
		vector<vector<int>>nG;
		auto get=[&](int x){
			if(mp.count(x))
				return mp[x];
			else
				return nG.emplace_back(vector<int>()),mp[x]=mp.size();
		};
		for(int i=0;i<(int)G.size();++i){
			int u=get(dsu.find(i));
			for(auto x:G[i])
				nG[u].emplace_back(x);
		}
		G=nG;
	}
	printf("%lld\n",ret);
	return 0;
}