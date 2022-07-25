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
	std::function<std::pair<int,std::vector<std::string>>(std::string,std::vector<std::string>)>dfs=[&](std::string s,std::vector<std::string>v)->std::pair<int,std::vector<std::string>>{
		v.pb(s);
		int ans=0;
		auto c=v;
		for(int i=2;i<(int)s.length();++i){
			auto sl=s.substr(0,i-2);
			auto sr=i==(int)s.length()-1?std::string(""):s.substr(i+1);
			if(s[i-2]=='A'&&s[i-1]=='B'&&s[i]=='C'){
				if(i&1){
					auto [ret,g]=dfs(sl+"AC"+sr,v);
					ret++;
					if(ret>ans){
						c=g;
					}
					ans=std::max(ans,ret);
				}else{
					auto [ret,g]=dfs(sl+"B"+sr,v);
					ret++;
					if(ret>ans){
						c=g;
					}
					ans=std::max(ans,ret);
				}
			}
		}
		return {ans, c};
	};
	std::string s_; std::cin>>s_;
	auto [ans,v]=dfs(s_,{});
	std::cout<<ans<<'\n';
	for(auto x:v){
		std::cout<<x<<'\n';
	}
	return 0;
}