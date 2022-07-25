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

int32_t main(){
	int T; std::cin>>T;
	while(T--){
		int n; std::cin>>n;
		std::vector<int>A(n);
		for(int i=0;i<n;++i){
			std::cin>>A[i];
		}
		for(int i=0;i<n;++i){
			int s=0;
			for(int j=0;j<n;++j){
				if(j==i) continue;
				s^=A[j];
			}
			if(s==A[i]){
				std::cout<<s<<'\n';
				break;
			}
		}
	}
	return 0;
}