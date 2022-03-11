#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<'\n'; } template<class F,class...L> 
void fo(F fst,L...lst) { cerr<<fst<<' '; fo(lst...); }
#define all(x) (x).begin(), (x).end()
using ll=long long;

// AC自动机
// 求文本串中出现了多少字典中的单词
// luoguP3808
template<int size=26>
struct ACAM{
	using Node=array<int,size>;
	vector<Node>nxt;
	vector<int>val;
	vector<int>f; // fail ָ指针
	int tot;
	inline int trans(char ch){
		return ch-'a'; 
	}
	ACAM():nxt(1),val(1),f(),tot(0){}
	void insert(const char* s){
		int p=0;
		for(int i=1;s[i];++i){
			auto ch=trans(s[i]);
			if(!nxt[p][ch]){
				nxt.emplace_back(Node{});
				val.emplace_back(0);
				nxt[p][ch]=++tot;
			}
			p=nxt[p][ch];
		}
		val[p]++;
	}
	void build(){
		queue<int>q; f.resize(tot+1);
		for(int i=0;i<size;++i)
			if(nxt[0][i])
				q.push(nxt[0][i]);
		while(!q.empty()){
			int u=q.front(); q.pop();
			for(int i=0;i<size;++i)
				if(nxt[u][i])
					f[nxt[u][i]]=nxt[f[u]][i], q.push(nxt[u][i]);
				else
					nxt[u][i]=nxt[f[u]][i];
		}
	}
	int query(const char* s){
		int p=0,ans=0;
		vector<int>vis(tot+1);
		for(int i=1;s[i];++i){
			p=nxt[p][trans(s[i])];
			for(int u=p;u&&!vis[u];u=f[u])
				ans+=val[u],vis[u]=true;
		}
		return ans;
	}
};

char str[1000010];

int32_t main() {
	int n;
	scanf("%d",&n);
	ACAM ac;
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);
		ac.insert(str);
	}
	ac.build();
	scanf("%s",str+1);
	printf("%d\n",ac.query(str));
	return 0;
}




//--------------------------------------------------------------