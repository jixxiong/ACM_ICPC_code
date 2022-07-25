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

int fcmp(ld x,ld y=0){
	if(std::abs(x-y)<EPS) return 0;
	if(x<y) return -1;
	return 1;
}

struct Par{
	ld a,b,c;
	Par(ld a=0,ld b=0,ld c=0):a(a),b(b),c(c){ }
	ld operator()(ld x){
		return a*x*x+b*x+c;
	}
};

int32_t main(){
	int n; std::cin>>n;
	std::vector<Par>low;
	std::vector<Par>up;
	for(int i=0;i<n;++i){
		ld a,b,c; std::cin>>a>>b>>c;
		if(a<0) up.pb(Par(a,b,c));
		if(a>0) low.pb(Par(a,b,c));
	}
	auto low_cal=[&](ld x){
		ld y=-INF;
		for(auto p:low){
			y=std::max(y,p(x));
		}
		return y;
	};
	auto up_cal=[&](ld x){
		ld y=INF;
		for(auto p:up){
			y=std::min(y,p(x));
		}
		return y;
	};
	auto fun=[&](ld x){
		return low_cal(x)-up_cal(x);
	};
	ld l=-INF,r=INF;
	while(fcmp(l,r)<0){
		ld lm=(2*l+r)/3;
		ld rm=(l+2*r)/3;
		if(fun(lm)<fun(rm))r=rm;
		else l=lm;
	}
	std::cout<<l<<' '<<(low_cal(l)+up_cal(l))/2<<'\n';
	return 0;
}