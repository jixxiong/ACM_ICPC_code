#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct Conbi{
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

int main(){
    int n,m; std::cin>>n>>m;
    Conbi A(n+m-1);
    std::cout<<A(n+m-1,n-1)<<'\n';
    return 0;
}