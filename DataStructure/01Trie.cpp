#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

template<int int_len=30>
struct Trie{
	using Node=array<int,2>;
	vector<int> cnt; // 节点经过次数
	vector<Node> nxt;
	int tot;
	Trie():cnt(1),nxt(1),tot(0){ }
	void insert(int x){
		int p=0;
		for(int i=int_len;i>=0;--i){
			auto ch=(x>>i)&1;
			if(!nxt[p][ch]){
				cnt.emplace_back(0);
				nxt.emplace_back(Node{});
				nxt[p][ch]=++tot;
			}
			p=nxt[p][ch];
			++cnt[p];
		}
	}
};

int main(){
	
	return 0; 
}