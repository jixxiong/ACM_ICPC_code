// pre=>O(n^2), qry=>O(1), any mod number
struct Conbi{
	vector<vector<int>>dp;
	Conbi(int n):dp(n+1,vector<int>(n+1)){
		for(int i=0;i<=n;++i)
			for(int j=0;j<=i;++j)
				dp[i][j]=j?(dp[i-1][j-1]+dp[i-1][j])%p:1;
	}
	int operator()(int x,int y){ // x choose y mod p
		if(y<0||y>x)
			return 0;
		return dp[x][y];
	}
};

int qpow(int x,int y){
	if(y==0)
		return 1;
	int res=1;
	for(;y>0;y>>=1,x=x*x%p)
		if(y&1)
			res=res*x%p;
	return res;
}

// pre=>O(n), qry=>O(1), prime mod number only
struct Conbi{
	const static int mod=1000000007;
	vector<int>fac,inv;
	int qpow(int x,int y){
		if(y==0)
			return 1;
		int res=1;
		for(;y>0;y>>=1,x=(ll)x*x%p)
			if(y&1)
				res=(ll)res*x%p;
		return res;
	}
	Conbi(int n):fac(n+1),inv(n+1){
		fac[0]=1;
		for(int i=1;i<=n;++i)
			fac[i]=(ll)fac[i-1]*i%p;
		inv[n]=qpow(fac[n],p-2);
		for(int i=n-1;i>=0;--i)
			inv[i]=(ll)inv[i+1]*(i+1)%p;
	}
	int operator()(int x,int y){
		if(y<0||y>x)
			return 0;
		return (ll)fac[x]*inv[y]%p*inv[x-y]%p;
	}
};