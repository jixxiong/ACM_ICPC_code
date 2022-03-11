#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

template<int size=26>
struct Trie{
	using Node=array<int,size>;
	vector<char> end; // 代表该节点是否为一个串的结尾节点
	vector<Node> nxt;
	int tot;
	Trie():end(1),nxt(1),tot(0){ }
	// 从字符集到下标的映射
	inline int trans(char ch){ 
		return ch-'a';
	}
	inline int new_node(){
		end.emplace_back(0);
		nxt.emplace_back(Node{});
		return ++tot;
	}
	void insert(char* s){
		int p=0;
		for(int i=1;s[i];++i){
			auto ch=trans(s[i]);
			if(!nxt[p][ch])
				nxt[p][ch]=new_node();
			p=nxt[p][ch];
		}
		end[p]=true;
	}
	bool query(char* s){
		int p=0;
		for(int i=1;s[i];++i){
			auto ch=trans(s[i]);
			if(!nxt[p][ch])
				return false;
			p=nxt[p][ch];
		}
		return end[p];
	}
};

char str[110];

int main(){
	Trie trie;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);
		trie.insert(str);
	}
	int m=0;
	scanf("%d",&m);
	while(m--){
		scanf("%s",str+1);
		puts(trie.query(str)?"YES":"NO");
	}
	return 0; 
}