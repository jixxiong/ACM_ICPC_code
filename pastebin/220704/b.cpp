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
		int n,m; std::cin>>n>>m;
		std::vector<std::vector<int>>A(std::max(n+1,5),std::vector<int>(std::max(m+1,5)));
		A[1][2]=A[1][3]=A[2][1]=A[2][4]=A[3][1]=A[3][4]=A[4][2]=A[4][3]=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(j>4){
					A[i][j]=A[i][j-4];
				}else if(i>4){
					A[i][j]=A[i-4][j];
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				std::cout<<(A[i][j])<<" \n"[j==m];
			}
		}
	}
	return 0;
}
