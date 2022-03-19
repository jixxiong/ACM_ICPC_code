#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
#endif
void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

// 求前缀子串的最大 border
struct Next:vector<int>{
	// 构建 next 数组 O(n)
	Next(const char* s,int n):vector<int>(n+1){
		auto&p=*this;
		for(int i=2,j=0;i<=n;++i){
			while(j&&s[i]!=s[j+1]) j=p[j];
			if(s[i]==s[j+1]) j++;
			p[i]=j;
		}
	}
};

const int mod=1000000007;

// luogu p2375 动物园 => 失配树写法
int32_t main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int n=s.length();
		s=' '+s;
		Next nxt(&s[0],n);
		int ret=1;
		vector<vector<int>>tree(2*n+1);
		for(int i=1;i<=n;++i)
			tree[nxt[i]].emplace_back(i);
		vector<int>stk;
		function<void(int,int)>dfs=[&](int u,int l){
			stk.emplace_back(u);
			while(l+1<(int)stk.size()&&stk[l+1]*2<=u)
				l++;
			ret=(ll)ret*(l+1)%mod;
			for(auto v:tree[u])
				dfs(v,l);
			stk.pop_back();
		};
		dfs(0,0);
		cout<<ret<<'\n';
	}
	return 0;
}