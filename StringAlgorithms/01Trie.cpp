#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

template<int int_len=30>
struct Trie{
	using Node=array<int,2>;
	vector<Node> nxt;
	int tot;
	Trie():nxt(1),tot(0){ }
	inline int new_node(){
		nxt.emplace_back(Node{});
		return ++tot;
	}
	void insert(int x){
		int p=0;
		for(int i=int_len;i>=0;--i){
			auto ch=(x>>i)&1;
			if(!nxt[p][ch])
				nxt[p][ch]=new_node();
			p=nxt[p][ch];
		}
	}
	int query_xor_max(int x){
		int p=0;
		int ret=0;
		for(int i=int_len;i>=0;--i){
			auto ch=(x>>i)&1;
			if(nxt[p][!ch]){
				p=nxt[p][!ch];
				ret|=1<<i;
			}else{
				p=nxt[p][ch];
			}
		}
		return ret;
	}
	int query_xor_min(int x){
		int p=0;
		int ret=0;
		for(int i=int_len;i>=0;--i){
			auto ch=(x>>i)&1;
			if(nxt[p][ch]){
				p=nxt[p][ch];
			}else{
				p=nxt[p][!ch];
				ret|=1<<i;
			}
		}
		return ret;
	}
};

int main(){
	Trie trie;
	trie.insert(0);
	trie.insert(1);
	trie.insert(2);
	trie.insert(3);
	cout<<trie.query_xor_max(2)<<endl;
	cout<<trie.query_xor_min(2)<<endl;
	return 0; 
}