#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;

using i32=__int32_t;
using i64=__int64_t;
using i128=__int128;
ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

namespace MathBase{
    i32 qpow(i32 x,i32 y,i32 p=mod){
        if(y==0) return 1;
        i32 ret=1;
        while(y){
            if(y&1) ret=(i64)ret*x%p;
            x=(i64)x*x%p;
            y>>=1;
        }
        return ret;
    }
};
using MathBase::qpow;

namespace NTT{
    i32 const p=998244353,g=3,gi=p/g+1;
    vc<i32>R; i32 limit;
    void pre(i32 n){
        i32 L=std::__lg(n)+1; limit=1<<L;
        if((i32)R.size()==limit) return ;
        R.resize(limit);
        for(i32 i=0;i<limit;++i) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
    }
    void dft(vc<i32>&A,i32 tp){
        if((i32)A.size()<limit) A.resize(limit);
        for(i32 i=0;i<limit;++i) if(i<R[i]) std::swap(A[i],A[R[i]]);
        for(i32 mid=1;mid<limit;mid<<=1){
            i32 const wn=qpow((tp==1?g:gi),(p-1)/(mid<<1),p);
            for(i32 len=mid<<1,j=0;j<limit;j+=len){
                for(i32 k=0,w=1;k<mid;++k,w=(i64)w*wn%p){
                    i32 x=A[j+k],y=(i64)w*A[j+k+mid]%p;
                    A[j+k]=(x+y)%p;
                    A[j+k+mid]=(x-y+p)%p;
                }
            }
        }
        if(tp==1) return ;
        i32 inv=qpow(limit,p-2);
        for(i32 i=0;i<limit;++i) A[i]=(i64)A[i]*inv%p;
    }
    vc<i32> mul(vc<i32>a,vc<i32>b,i32 upper=0x3f3f3f3f){
        if((i32)a.size()>upper+1) a.resize(upper+1);
        if((i32)b.size()>upper+1) b.resize(upper+1);
        i32 n=a.size()-1,m=b.size()-1;
        pre(n+m);
        dft(a,1), dft(b,1);
        vc<i32>c(limit);
        for(i32 i=0;i<limit;++i) c[i]=(i64)a[i]*b[i]%p;
        dft(c,-1);
        c.resize(std::min(upper+1,n+m+1));
        return c;
    }
};
using NTT::mul;

i32 main(){
    i32 n,m; std::cin>>n>>m;
    vc<i32>A(n+1),B(m+1);
    for(i32 i=0;i<=n;++i) std::cin>>A[i];
    for(i32 i=0;i<=m;++i) std::cin>>B[i];
    auto C=mul(A,B);
    for(int i=0;i<=n+m;++i) std::cout<<C[i]<<' ';
    return 0;
}