#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

template<int int_len=30>
struct Trie{
	using Node=array<int,2>;
	vector<int> lm,rm;
	vector<Node> nxt;
	vector<int>&A;
	int tot;
	Trie(vector<int>&A):lm(1),rm(1),nxt(1),A(A),tot(0){ }
	inline int new_node(){
		lm.emplace_back(0);
		rm.emplace_back(0);
		nxt.emplace_back(Node{});
		return ++tot;
	}
	void insert(int x,int idx){
		int p=0;
		for(int i=int_len;i>=0;--i){
			auto ch=(x>>i)&1;
			if(!nxt[p][ch])
				lm[nxt[p][ch]=new_node()]=idx;
			p=nxt[p][ch];
			rm[p]=idx;
		}
	}
	int query(int x,int p){
		int rt=0;
		int ret=0;
		for(int i=int_len;i>=0;--i){
			auto ch=(x>>i)&1;
			if(nxt[rt][ch]&&nxt[rt][ch]!=p)
				rt=nxt[rt][ch];
			else{
				ret|=1<<i;
				rt=nxt[rt][!ch];
			}
		}
		return ret;
	}
	ll dnc(int p){ // 分治算法，启发式合并
		if(!(nxt[p][0]||nxt[p][1]))
			return 0;
		ll ret=0;
		for(int i=0;i<2;++i)
			if(nxt[p][i])
				ret+=dnc(nxt[p][i]);
		if(nxt[p][0]&&nxt[p][1]){
			int mn=numeric_limits<int>::max();
			for(int i=lm[nxt[p][0]];i<=rm[nxt[p][0]];++i)
				mn=min(mn,query(A[i],nxt[p][0]));
			ret+=mn;
		}
		return ret;
	}
};

int32_t main(){
	int n;
	scanf("%d",&n);
	vector<int>A(n);
	for(int i=0;i<n;++i){
		scanf("%d",&A[i]);
	}
	sort(all(A));
	Trie trie(A);
	for(int i=0;i<n;++i){
		trie.insert(A[i],i);
	}
	printf("%lld\n",trie.dnc(0));
	return 0;
}

/* B算法 + Trie 纯纯的B算法，常数太大了，没有用到01Trie树和XOR的性质

#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	char ch=nc();int sum=0;
	while(!(ch>='0'&&ch<='9'))ch=nc();
	while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
	return sum;
}

template<int int_len=30>
struct Trie{
	using Node=array<int,2>;
	vector<int> cnt;
	vector<int> end;
	vector<Node> nxt;
	int tot;
	Trie():cnt(1),end(1),nxt(1),tot(0){
		cnt.reserve(200000*60);
		nxt.reserve(200000*60);
		end.reserve(200000*60);
	}
	inline int new_node(){
		cnt.emplace_back(0);
		end.emplace_back(0);
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
	#define arr (*this)
	DSU(int n):vector<int>(n){
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
	void clear(int n){
		for(int i=0;i<n;++i)
			arr[i]=i;
	}
	#undef arr
};

struct Edge{
	int u,v,d;
    friend bool operator==(const Edge&o1,const Edge&o2) {
        return o1.u==o2.u&&o1.v==o2.v&&o1.d==o2.d;
    }
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int>A(n);
	Trie trie;
	for(int i=0;i<n;++i){
		scanf("%d",&A[i]);
		trie.insert(A[i],i);
	}
	vector<vector<int>>G(n,vector<int>(1));
	for(int i=0;i<n;++i){
		G[i][0]=i;
	}
	ll ret=0;
	vector<int>id(n),hs(n);
	vector<vector<int>>nG;
	vector<Edge>st(2*n);
	DSU dsu(n);
	while(G.size()>1){
		for(int i=0;i<(int)G.size();++i)
			for(auto x:G[i])
				id[x]=i;
		int sttop=0;
		for(int i=0;i<(int)G.size();++i){
			for(auto x:G[i])
				trie.remove(A[x]);
			int mn=numeric_limits<int>::max();
			int k=-1;
			for(auto x:G[i]){
				auto [y,idx]=trie.query(A[x]);
				if(y<mn){
					mn=y;
					k=idx;
				}
			}
			st[sttop++]=Edge{min(i,id[k]),max(i,id[k]),mn};
			for(auto x:G[i])
				trie.insert(A[x],x);
		}
		for(int i=0;i<sttop;++i){
			auto&& [u,v,d]=st[i];
			int fu=dsu.find(u),fv=dsu.find(v);
			if(fu==fv)
				continue;
			ret+=d;
			dsu[fu]=fv;
		}
		int tot=0;
		fill(hs.begin(),hs.begin()+G.size(),-1);
		vector<vector<int>>().swap(nG);
		auto get=[&](int x){
			if(~hs[x])
				return hs[x];
			else
				return nG.emplace_back(vector<int>()),hs[x]=tot++;
		};
		for(int i=0;i<(int)G.size();++i){
			int u=get(dsu.find(i));
			for(auto x:G[i])
				nG[u].emplace_back(x);
		}
		G=nG;
        dsu.clear(G.size());
	}
	printf("%lld\n",ret);
	return 0;
}

*/