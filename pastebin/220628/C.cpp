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
#define int long long

int32_t main(){
	int T; std::cin>>T;
	while(T--){
		int n; std::cin>>n;
		std::set<ll>st;
		std::vector<int>A(n);
		for(int i=0;i<n;++i){
			std::cin>>A[i];
			st.insert(A[i]);
		}
		std::sort(all(A));
		if((A[0]==0&&A[n-2]==0)||
			(A[1]==0&&A[n-1]==0)){
			std::cout<<"YES"<<'\n';
			continue;
		}
		bool fail=(((ll)A[0]+A.back())!=0);
		for(int i=1;i<n-1;++i) if(A[i]) fail=true;
		if(fail){
			if(n<=20){
				bool ok=true;
				for(int i=0;i<n;++i){
					for(int j=i+1;j<n;++j){
						for(int k=j+1;k<n;++k){
							if(!st.count((ll)A[i]+A[j]+A[k])){
								ok=false;
							}
						}
					}
				}
				std::cout<<(ok?"YES":"NO")<<'\n';
			}else{
				std::cout<<"NO"<<'\n';
			}
		}else{
			std::cout<<"YES"<<'\n';
		}
	}
	return 0;
}