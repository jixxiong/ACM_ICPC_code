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

// pre=>O(n), qry=>O(1), prime mod number only
struct conbi_lin{
    const static int p=1000000007;
    std::vector<int>fac,inv;
    int qpow(int x,int y){
        if(y==0)
            return 1;
        int res=1;
        for(;y>0;y>>=1,x=(ll)x*x%p)
            if(y&1)
                res=(ll)res*x%p;
        return res;
    }
    conbi_lin(int n):fac(n+1),inv(n+1){
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

int32_t main(){
	conbi_lin conb(3000010);
    int n; std::cin>>n;
    ll ret=0;
    for(int i=1;i<=n+1;++i){
    	int x; std::cin>>x;
    	ret+=conb(i+x-1,x-1);
    	ret%=1000000007;
    }
    std::cout<<ret<<'\n';
    return 0;
}