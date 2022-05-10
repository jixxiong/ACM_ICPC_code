#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

// pre=>O(n^2), qry=>O(1), any mod number
struct conbi_dp{
    const int p=1000000007; 
    std::vector<std::vector<int>>dp;
    conbi_dp(int n):dp(n+1,std::vector<int>(n+1)){
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

struct fint{
    static ll const p=1000000000039ll;
    ll x;
    fint(ll x=0):x(x){ }
    friend fint operator+(fint x,fint y){
        ll z=x.x+y.x;
        if(z>=p) z-=p;
        if(z<0) z+=p;
        return z;
    }
    friend fint operator-(fint x,fint y){
        y.x=-y.x;
        return x+y;
    }
    friend fint operator*(fint x,fint y){
        ll res=0;
        while(y.x){
            if(y.x&1)res=(res+x.x)%p;
            x=x+x; y.x>>=1;
        }return res;
    }
    friend fint operator/(fint x,fint y){
        return x*y.inv();
    }
    fint pow(fint y){
        if(y==0)
            return 1;
        fint x=*this;
        fint res=1;
        for(;y>0;y.x>>=1,x=x*x)
            if(y.x&1)
                res=res*x;
        return res;
    }
    fint inv(){
        return this->pow(p-2);
    }
    friend bool operator==(fint x,fint y){
        return x.x==y.x;
    }
    friend bool operator<(fint x,fint y){
        return x.x<y.x;
    }
    friend bool operator>(fint x,fint y){
        return x.x>y.x;
    }
    friend bool operator!=(fint x,fint y){
        return x.x!=y.x;
    }
};

// pre=>O(n), qry=>O(1), large prime number
struct conbi_lin{
    const static ll p=1000000000039ll;
    std::vector<fint>fac,inv;
    conbi_lin(int n):fac(n+1),inv(n+1){
        fac[0]=1;
        for(int i=1;i<=n;++i)
            fac[i]=fac[i-1]*i;
        inv[n]=fac[n].inv();
        for(int i=n-1;i>=0;--i)
            inv[i]=inv[i+1]*(i+1);
    }
    ll operator()(int x,int y){
        if(y<0||y>x)
            return 0;
        return (fac[x]*inv[y]*inv[x-y]).x;
    }
};