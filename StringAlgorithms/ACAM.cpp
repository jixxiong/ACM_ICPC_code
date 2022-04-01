#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fo(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fo(fst F, lst... L) { std::cerr<<F<<' '; fo(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

template<int sigma=26>
struct ACAM{
	using Node=std::array<int,sigma>;
	std::vector<Node>nxt;
	std::vector<char>end;
	std::vector<int>f;    // fail ָ指针
	int tot;
	int trans(char ch){
		return ch-'a'; 
	}
	int new_node(){
		nxt.pb(Node{});
		end.pb(0);
		return ++tot;
	}
	ACAM():nxt(1),end(1),tot(0){}
	void insert(const char* s){
		int p=0;
		for(int i=1;s[i];++i){
			auto ch=trans(s[i]);
			if(!nxt[p][ch])
				nxt[p][ch]=new_node();
			p=nxt[p][ch];
		}
		end[p]=true;
	}
	void build(){
		std::queue<int>q; f.resize(tot+1);
		for(int i=0;i<sigma;++i)
			if(nxt[0][i])
				q.push(nxt[0][i]);
		while(!q.empty()){
			int u=q.front(); q.pop();
			for(int i=0;i<sigma;++i)
				if(nxt[u][i])
					f[nxt[u][i]]=nxt[f[u]][i], q.push(nxt[u][i]);
				else
					nxt[u][i]=nxt[f[u]][i];
		}
	}
	// 匹配到多少串
	int query(const char* s){
		int p=0,ans=0;
		for(int i=1;s[i];++i){
			p=nxt[p][trans(s[i])];
			for(int u=p;u;u=f[u])
				if(end[u]) ans++;
		}
		return ans;
	}
};

int main(){

	return 0;
}