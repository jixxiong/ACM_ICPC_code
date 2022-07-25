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
const ld EPS=1e-8;

int32_t main(){
	int T; std::cin>>T;
	while(T--){
		int n; std::cin>>n;
		std::vector<int>A(n+1);
		std::vector<int>L(n+1),R(n+1);
		std::vector<int>ans(n+1);
		std::set<int>rest;
		for(int i=1;i<=n;++i) rest.insert(i);
		for(int i=1;i<=n;++i){
			std::cin>>A[i];
			if(A[i]==0){
				L[i]=i+1;
				R[i]=n;
			}else{
				L[i]=(i/(A[i]+1))+1;
				R[i]=i/(A[i]);
			}
		}
		std::vector<int>id(n+1);
		std::iota(all(id),0);
		std::sort(1+all(id),[&](int i,int j){
			if(R[i]==R[j]) return L[i]<L[j];
			return R[i]<R[j];
		});
		for(int i=1;i<=n;++i){
			int j=id[i];
			ans[j]=*rest.lower_bound(L[j]);
			rest.erase(ans[j]);
		}
		for(int i=1;i<=n;++i){
			std::cout<<ans[i]<<" \n"[i==n];
		}
	}
	return 0;
}