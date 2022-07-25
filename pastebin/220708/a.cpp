#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
	__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
	#define de(...) void()
#else
	void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
	#define de(args...){std::cerr<<"[DEBUG: LINE "<<__LINE__<<"]: ";_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;

int32_t main(){
	int n; std::cin>>n;
	std::vector<int>A(n);
	std::vector<int>s[2];
	std::vector<int>vis(n+1,-1);
	for(int i=0;i<n;++i){
		std::cin>>A[i];
	}
	int i=0;
	for(int tar=1;tar<=n;++tar){
		while(!~vis[tar]){
			s[0].pb(A[i]);
			vis[A[i]]=0;
			std::cout<<"1\n";
			i++;
		}
		int p=vis[tar];
		while(s[p].back()!=tar){
			s[p^1].pb(s[p].back());
			vis[s[p].back()]^=1;
			std::cout<<(p+1)<<((p^1)+1)<<'\n';
			s[p].pop_back();
		}
		std::cout<<'-'<<(p+1)<<'\n';
		s[p].pop_back();
	}
	return 0;
}