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
    	int n,z; std::cin>>n>>z;
    	int ret = 0;
    	for(int i=1;i<=n;++i) {
    		int x; std::cin>>x;
    		ret = std::max(ret,x|z);
    	}
    	std::cout<<ret<<'\n';
    }
    return 0;
}