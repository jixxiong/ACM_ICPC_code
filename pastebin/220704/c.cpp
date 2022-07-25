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

ll p=1000000007;

int32_t main(){
	int T; std::cin>>T;
	while(T--){
		int n; std::cin>>n;
		std::vector<int>A(n+1);
		std::vector<int>B(n+1);
		for(int i=1;i<=n;++i) std::cin>>A[i],A[i]++,B[A[i]]=i;
		ll ret=1;
		ll l=n+1,r=0;
		int tk=0;
		for(int i=1;i<=n;++i){
			if(B[i]>r)r=B[i];
			if(B[i]<l)l=B[i];
			if(l==B[i]||r==B[i]){
				tk++;
				continue;
			}
			ret=ret*(i-tk)%p;
		}
		std::cout<<ret<<'\n';
	}
	return 0;
}