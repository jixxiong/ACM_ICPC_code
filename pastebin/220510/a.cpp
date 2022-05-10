#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
const int p=998244353;

struct conbi_lin{
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

struct node{
    int l,r;
};

int32_t main(){
    int n,k; std::cin>>n>>k;
    std::string s; std::cin>> s;
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) A[i]=A[i-1]+(s[i-1]=='1');
    std::vector<node>B;
    for(int i=1,j=1;i<=n;++i){
        auto tmp=j;
        while(j<=n&&A[j]-A[i-1]<=k) j++;
        if(j==tmp) continue;
        if(i<j&&A[j-1]-A[i-1]==k) B.pb(node{i,j-1});
    }
    conbi_lin C(10000);
    int ret=0;
    auto fun=[&](int l,int r){
        int x=A[r]-A[l-1];
        int y=r-l+1;
        return (C(y,x)-1+p)%p;
    };
    for(int i=0;i<(int)B.size();++i){
        ret=(ret+fun(B[i].l,B[i].r))%p;
    }
    for(int i=0;i<(int)B.size();++i){
        for(int j=i+1;j<(int)B.size();++j){
            if(B[i].r<B[j].l) continue;
            ret=(ret-fun(B[j].l,B[i].r)+p)%p;
        }
    }
    std::cout<<(ret+1)%p<<'\n';
    return 0;
}