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
#define int long long
using ld=long double;
const ld EPS=1e-8;

int32_t main(){
	int T; std::cin>>T;
	while(T--){
		int n,m; std::cin>>m>>n;
		std::vector<int>A(n+1);
		std::vector<std::vector<int>>B(m+1);
		for(int i=1;i<=n;++i){
			int x; std::cin>>x;
			A[i]=x;
			B[x].pb(i);
		}
		auto check=[&](int t){
			int a=0;
			int r=0;
			for(int i=1;i<=m;++i){
				int s=(int)B[i].size();
				if(s>=t){
					a+=s-t;
				}else{
					int f=t-s;
					r+=f/2;
				}
			}
			return a<=r;
		};
		int l=0,r=n+1;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid;
		}
		std::cout<<r<<'\n';
	}
	return 0;
}