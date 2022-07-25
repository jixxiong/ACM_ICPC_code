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
const ld PI=std::acos((ld)-1.0);
const ld EPS=1e-8;

int32_t main(){
	int T; std::cin>>T;
	std::cout<<std::fixed<<std::setprecision(10);
	while(T--){
		int n; std::cin>>n;
		std::cout<<std::cos(PI/(4*n))/std::sin(PI/(2*n))<<'\n';
	}
	return 0;
}