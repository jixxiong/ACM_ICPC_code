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

int ret1[1010]; // 5, 7, 11, 13
int ret2[1010]; // 5, 7, 11, 13
const int INF=0x3f3f3f3f;

int dfs1(int x){
	if(ret1[x]!=INF) return ret1[x];
	if(x==0) return ret1[x]=0;
	if(x<5) return ret1[x]=INF;
	int ans=INF;
	if(x>=5)ans=std::min(ans,dfs1(x-5)+1);
	if(x>=7)ans=std::min(ans,dfs1(x-7)+1);
	if(x>=11)ans=std::min(ans,dfs1(x-11)+1);
	if(x>=13)ans=std::min(ans,dfs1(x-13)+1);
	return ret1[x]=ans;
}

int dfs2(int x){
	if(ret2[x]!=INF) return ret2[x];
	if(x==0) return ret2[x]=0;
	if(x<2) return ret2[x]=INF;
	int ans=INF;
	if(x>=2)ans=std::min(ans,dfs2(x-2)+1);
	if(x>=3)ans=std::min(ans,dfs2(x-3)+1);
	if(x>=17)ans=std::min(ans,dfs2(x-17)+1);
	if(x>=19)ans=std::min(ans,dfs2(x-19)+1);
	return ret2[x]=ans;
}

int32_t main(){
	for(int i=1;i<=1000;++i){
		ret1[i]=ret2[i]=INF;
		dfs1(i);
		dfs2(i);
	}	
	int T; std::cin>>T;
	while(T--){
		int n; std::cin>>n;
		if(n>1000){
			std::cout<<"A\n";
		}else{
			if(ret1[n]==ret2[n]&&ret1[n]==INF) std::cout<<"-1\n";
			else if(ret1[n]==ret2[n]) std::cout<<"both\n";
			else if(ret1[n]>ret2[n]) std::cout<<"A\n";
			else std::cout<<"B\n";
		}
	}
	return 0;
}