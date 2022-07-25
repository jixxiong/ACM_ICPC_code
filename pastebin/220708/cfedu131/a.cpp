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
		int a,b,c,d; std::cin>>a>>b>>c>>d;
		if(a==0&&b==0&&c==0&&d==0) std::cout<<"0\n";
		else if(a==1&&b==1&&c==1&&d==1) std::cout<<"2"<<'\n';
		else std::cout<<"1\n"<<'\n';
	}
	return 0;
}