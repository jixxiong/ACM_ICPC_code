#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

using ll=long long;
using poly=vector<ll>;

namespace Poly{
    constexpr ll p=998244353;
    constexpr ll g=3;
    constexpr ll gi=p/g+1;
    vector<int>R; int limit;
    ll qpow(ll x,ll y){
        if(y==0) return 1;
        if(x==0) return 0;
        ll ans=1;
        for(;y;y>>=1,x=x*x%p)
            if(y&1)
                ans=ans*x%p;
        return ans;
    }
    void butterfly(int n){
        int L=__lg(n)+1; limit=1<<L;
        if((int)R.size()<limit)
            R.resize(limit);
        for(int i=0;i<limit;++i)
            R[i]=R[i>>1]>>1|((i&1)<<(L-1));
    }
    void ntt(poly& A,int tp){
        if((int)A.size()<limit)
            A.resize(limit);
        for(int i=0;i<limit;++i)
            if(i<R[i])
                swap(A[i],A[R[i]]);
        for(int mid=1;mid<limit;mid<<=1){
            const ll wn=qpow((tp==1?g:gi),(p-1)/(mid<<1));
            for(int len=mid<<1,pos=0;pos<limit;pos+=len){
                ll w=1;
                for(int k=0;k<mid;k++,w=w*wn%p){
                    ll x=A[pos+k],y=w*A[pos+k+mid]%p;
                    A[pos+k]=(x+y)%p;
                    A[pos+k+mid]=(x-y+p)%p;
                }
            }
        }
        if(tp==1)
            return ;
        int inv_lim=qpow(limit,p-2);
        for(int i=0;i<limit;++i)
            A[i]=A[i]*inv_lim%p;
    }
    poly mul(poly a,poly b){
        int n=a.size()-1,m=b.size()-1;
        butterfly(n+m);
        ntt(a,1),ntt(b,1);
        poly c(limit+1);
        for(int i=0;i<limit;++i)
            c[i]=a[i]*b[i]%p;
        ntt(c,-1);
        c.resize(n+m+1);
        return c;
    }
};

signed main(){
    int n,m;
    scanf("%lld%lld",&n,&m);
    poly A(n+1),B(m+1);
    for(int i=0;i<=n;++i)
        scanf("%lld",&A[i]);
    for(int j=0;j<=m;++j)
        scanf("%lld",&B[j]);
    poly c=Poly::mul(A,B);
    for(int i=0;i<=n+m;++i)
        printf("%lld ",c[i]);
    return 0;
}