#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<'\n'; } template<class F,class...L> 
void fo(F fst,L...lst) { cerr<<fst<<' '; fo(lst...); }
#define all(x) (x).begin(), (x).end()
using ll=long long;

// AC自动机
// 求文本串中出现了多少字典中的单词
// luoguP3808
template<int sigma=26>
struct ACAM{
	using Node=array<int,sigma>;
	vector<Node>nxt;
	vector<int>val;
	vector<int>f; // fail ָ指针
	int tot;
	int trans(char ch){
		return ch-'a'; 
	}
	int new_node(){
		nxt.emplace_back(Node{});
		val.emplace_back(0);
		return ++tot;
	}
	ACAM():nxt(1),val(1),tot(0){}
	void insert(const char* s){
		int p=0;
		for(int i=1;s[i];++i){
			auto ch=trans(s[i]);
			if(!nxt[p][ch])
				nxt[p][ch]=new_node();
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




//---------------------------------------

// 找出哪些模式串在文本串中出现的次数最多
// luoguP3796

#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

template<int sigma=26>
struct ACAM{
	using Node=array<int,sigma>;
	vector<Node>nxt;
	vector<int>f;
	vector<int>cnt;
	vector<int>end;
	int tot;
	int trans(char ch){
		return ch-'a'; 
	}
	int new_node(){
		nxt.emplace_back(Node{});
		end.emplace_back(0);
		return ++tot;
	}
	ACAM():nxt(1),f(),cnt(1),end(1),tot(0){}
	void insert(const char* s,int idx){
		int p=0;
		cnt.emplace_back(0);
		for(int i=1;s[i];++i){
			auto ch=trans(s[i]);
			if(!nxt[p][ch])
				nxt[p][ch]=new_node();
			p=nxt[p][ch];
		}
		end[p]=idx;
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
	void query(const char* s){
		int p=0;
		for(int i=1;s[i];++i){
			p=nxt[p][trans(s[i])];
			for(int u=p;u;u=f[u])
				if(end[u])
					cnt[end[u]]++;
		}
	}
};

char t[200][100];
char str[1000010];

int main(){
	int n;
	while(scanf("%d",&n),n){
		ACAM ac;
		for(int i=1;i<=n;++i){
			scanf("%s",t[i]+1);
			ac.insert(t[i],i);
		}
		ac.build();
		scanf("%s",str+1);
		ac.query(str);
		int mx=*max_element(ac.cnt.begin()+1,ac.cnt.end());
		vector<int>ret;
		for(int i=1;i<=n;++i)
			if(mx==ac.cnt[i])
		 		ret.emplace_back(i);
		printf("%d\n",mx);
		for(auto x:ret){
			puts(t[x]+1);
		}
	}
	return 0; 
}





//----------------------------

#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

// luoguP5357
// Fail树上差分
template<int sigma=26>
struct ACAM{
	using Node=array<int,sigma>;
	vector<Node>nxt;
	vector<int>val;
	vector<int>end; // 第i个串的结束点编号
	vector<int>f;
	vector<vector<int>>G;
	int tot;
	int trans(char ch){
		return ch-'a'; 
	}
	int new_node(){
		nxt.emplace_back(Node{});
		val.emplace_back(0);
		f.emplace_back(0);
		return ++tot;
	}
	ACAM():nxt(1),val(1),end(1),f(1),tot(0){}
	void insert(const char* s){
		int p=0;
		for(int i=1;s[i];++i){
			auto ch=trans(s[i]);
			if(!nxt[p][ch])
				nxt[p][ch]=new_node();
			p=nxt[p][ch];
		}
		end.emplace_back(p);
	}
	void build(){
		queue<int>q;
		for(int i=0;i<size;++i)
			if(nxt[0][i])
				q.push(nxt[0][i]);
		while(!q.empty()){
			int u=q.front(); q.pop();
			for(int i=0;i<size;++i)
				if(nxt[u][i]){
					f[nxt[u][i]]=nxt[f[u]][i];
					q.push(nxt[u][i]);
				}
				else
					nxt[u][i]=nxt[f[u]][i];
		}
		G.resize(tot+1);
		for(int i=1;i<=tot;++i)
			G[f[i]].emplace_back(i);
	}
	void query(const char* s){
		for(int i=1,p=0;s[i];++i){
			p=nxt[p][trans(s[i])];
			val[p]++;
		}
		function<void(int)>dfs=[&](int u){
			for(auto v:G[u]){
				dfs(v);
				val[u]+=val[v];
			}
		};
		dfs(0);
		return ;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<char>str(2000010);
	ACAM ac;
	for(int i=1;i<=n;++i){
		scanf("%s",&str[1]);
		ac.insert(&str[0]);
	}
	scanf("%s",&str[1]);
	ac.build();
	ac.query(&str[0]);
	for(int i=1;i<=n;++i)
		printf("%d\n",ac.val[ac.end[i]]);
	return 0;
}