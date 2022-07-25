#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
	__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
	#define er(args...) void()
#else
	#define vwn(x) #x"=",x,"\n"
	void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
	#define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;
const ll p = 998244353;

ll qpow(ll x,ll y){
	if(y==0) return 1;
	int ret = 1;
	while(y){
		if(y&1) ret = ret * x % p;
		x = x * x % p;
		y>>=1;
	}
	return ret;
}

int32_t main(){
	int n; std::cin>>n;
	
	return 0;
}