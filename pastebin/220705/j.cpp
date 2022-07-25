#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int unsigned long long
#define ll unsigned long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,inf=2e9;
    int n;
    map<int,int> dp;
    std::vector<int>A(n);
    bool zero(int n){
    	if(n<=150) return 0;
    	int up=(int)-1;
    	if(up-n<10) return 0;
    	int lower=std::__lg(n);
    	if(n-((ll)1<<lower)<50) return 0;
    	if(lower==63) return 1;
    	if(((ll)1<<(lower+1))-n<50) return 0;
    	return 1;
    }
    inline int dfs(int n)
    {
    	if(zero(n)) return 0;
    	if(dp.count(n)) return dp[n];
        if(n&1){
        	ll f1=dfs(n/2);
        	if(f1==0) return 0;
        	return dp[n]=f1*f1;
        }else{
        	ll f1=dfs(n/2);
        	if(f1==0) return 0;
        	ll f2=dfs(n/2-1);
        	if(f2==0) return 0;
        	return dp[n]=2*f1*f2;
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        dp[1]=dp[0]=1;
        while(qwq--)
        {
        	int x;
        	cin>>x;
            std::cout<<dfs(x)<<'\n';
        }
        // for(int i=1;i<=1200;++i)
        // {
        //     cout<<i<<' '<<dfs(i)<<'\n';
        // }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*

dp[n]=dp[n/2]*dp[n/2] (n is odd)

dp[n]=dp[n/2]*dp[n/2-1]*2 (n is oushu)

*/

