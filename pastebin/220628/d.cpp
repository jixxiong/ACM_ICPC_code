#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
	// __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
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

int32_t main(){
	int T; std::cin>>T;
	while(T--){
		int n; std::cin>>n;
		int l=0,r=n+1;
		while(l+1<r){
			int mid=(l+r)>>1;
			std::cout<<"? "<<1<<' '<<mid<<std::endl;
			int cnt=0;
			for(int i=1;i<=mid;++i){
				int x;
				std::cin>>x;
				if(x>mid) cnt++;
			}
			if((mid-cnt)&1) r=mid;
			else l=mid;
		}
		std::cout<<"! "<<r<<std::endl;
	}
	return 0;
}