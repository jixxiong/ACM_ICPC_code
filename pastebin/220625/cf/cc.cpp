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
    	int m; std::cin>>m;
    	std::vector<int>A(n);
    	for(int i=0;i<n;++i) std::cin>>A[i];
    	int k; std::cin>>k;
 		std::vector<int>B(k);
 		for(int j=0;j<k;++j) std::cin>>B[j];
 		int i=0,j=0;
 		bool fail=false;
 		auto get_r=[&](int x){
 			while(x%m==0) x/=m;
 			return x;
 		};
 		while(i<n&&j<k){
 			if(get_r(A[i])!=get_r(B[j])){
 				fail=true;
 				break;
 			}
 			ll o1=A[i];
 			ll o2=B[j];
 			while(i+1<n&&get_r(A[i+1])==get_r(A[i])) i++,o1+=A[i];
 			while(j+1<k&&get_r(B[j+1])==get_r(B[j])) j++,o2+=B[j];
 			if(o1!=o2){
 				fail=true;
 				break;
 			}
 			i++;
 			j++;
 		}   
 		std::cout<<(fail||i!=n||j!=k?"No":"Yes")<<'\n';
    }
    return 0;
}