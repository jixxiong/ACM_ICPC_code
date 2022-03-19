#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

// basic Sufix Automaton
template<int sigma=26>
struct SAM{
	using Node=array<int,sigma>;
	vector<int>len,fa;
	vector<Node>nxt;
	int las,tot;
	SAM(char* str,int len):len(2),fa(2),nxt(2),las(1),tot(1){ 
		for(int i=1;i<=len;++i)
			add(str[i]);
	}
	int trans(int c){
		return c-'a';
	}
	int new_node(){
		len.pb(0),fa.pb(0),nxt.pb(Node{});
		return ++tot;
	}
	void add(int c){
		c=trans(c);
		int p=las,np=las=new_node();
		len[np]=len[p]+1;
		for(;p&&!nxt[p][c];p=fa[p]) nxt[p][c]=np;
		if(!p) fa[np]=1;
		else{
			int q=nxt[p][c];
			if(len[q]==len[p]+1) fa[np]=q;
			else{
				int nq=new_node(); 
				nxt[nq]=nxt[q],len[nq]=len[q],fa[nq]=fa[q];
				len[nq]=len[p]+1; fa[q]=fa[np]=nq;
				for(;p&&nxt[p][c]==q;p=fa[p]) nxt[p][c]=nq;
			}
		}
	}
};

int main(){
	string str(1000010,0);
	scanf("%s",&str[1]);
	int n=strlen(&str[1]);
	SAM sam(&str[0],n);
	return 0;
}

// ----------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

// luogu p3804 
// 求出 S 的所有出现次数不为 1 的子串的出现次数乘上该子串长度的最大值
template<int sigma=26>
struct SAM{
	using Node=array<int,sigma>;
	vector<int>len;            // 节点对应的 endpos 等价类的最大子串长度
	vector<int>fa;             // 后缀链接树上节点的父亲指针
	vector<Node>nxt;           // 状态图节点的 nxt 指针
	vector<int>size;           // 子串的出现次数
	vector<vector<int>>tree;   // 后缀链接树(邻接表)
	int las,tot;
	ll ans;
	SAM(char* str,int len):len(2),fa(2),nxt(2),size(2),las(1),tot(1),ans(0){ 
		for(int i=1;i<=len;++i)
			add(str[i]);
		tree.resize(tot+1);
		for(int i=2;i<=tot;++i)
			tree[fa[i]].emplace_back(i);
	}
	int trans(int c){
		return c-'a';
	}
	int new_node(){
		len.pb(0),fa.pb(0),nxt.pb(Node{}),size.pb(0);
		return ++tot;
	}
	void add(int c){
		c=trans(c);
		int p=las,np=las=new_node(); size[tot]=1;
		len[np]=len[p]+1;
		for(;p&&!nxt[p][c];p=fa[p]) nxt[p][c]=np;
		if(!p) fa[np]=1;
		else{
			int q=nxt[p][c];
			if(len[q]==len[p]+1) fa[np]=q;
			else{
				int nq=new_node(); 
				nxt[nq]=nxt[q],len[nq]=len[q],fa[nq]=fa[q];
				len[nq]=len[p]+1; fa[q]=fa[np]=nq;
				for(;p&&nxt[p][c]==q;p=fa[p]) nxt[p][c]=nq;
			}
		}
	}
	void dfs(int u){ // graph part
		for(auto v:tree[u]){
			dfs(v);
			size[u]+=size[v];
		}
		if(size[u]!=1)
			ans=max(ans,(ll)size[u]*len[u]);
	}
};

int main(){
	string str(1000010,0);
	scanf("%s",&str[1]);
	int n=strlen(&str[1]);
	SAM sam(&str[0],n);
	sam.dfs(1);
	printf("%lld\n",sam.ans);
	return 0;
}