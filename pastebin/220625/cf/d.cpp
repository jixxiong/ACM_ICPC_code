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
    	std::deque<int>l1{0},l2{0};
    	std::vector<int>A(n+1);
    	std::vector<int>dp(n+1,0x3f3f3f3f);
    	dp[1]=0;
    	for(int i=1;i<=n;++i){
    		int x; std::cin>>x; A[i]=x;
    		while(l1.back()!=0&&A[l1.back()]<x)l1.pop_back();
    		while(l1.back()!=0&&A[l2.back()]>x)l2.pop_back();
    		l1.push_back(i), l2.push_back(i);
    		int l=-1,r=(int)l1.size();
    		while(l+1<r){
    			int mid=(l+r)>>1;
    			if(l1[mid]>*std::next(l2.rbegin())) r=mid;
    			else l=mid;
    		}
    		if(r!=(int)l1.size()) dp[i]=std::min(dp[i],dp[l1[r]]+1);
    		l=-1,r=(int)l2.size();
    		while(l+1<r){
    			int mid=(l+r)>>1;
    			if(l2[mid]>*std::next(l1.rbegin())) r=mid;
    			else l=mid;
    		}
    		if(r!=(int)l2.size()) dp[i]=std::min(dp[i],dp[l2[r]]+1);
    	}
    	std::cout<<dp[n]<<'\n';
    }
    return 0;
}