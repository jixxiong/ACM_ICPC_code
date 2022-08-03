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

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
int const P=998244353;


int32_t main(){
    int n; std::cin>>n;
    vc<int>A(n+1);
    for(int i=1;i<=n;++i){
        std::cin>>A[i];
    }
    int ans=n;
    for(int mod=2;mod<=n;++mod){
        vvc<int> f(110,vc<int>(110));
        vvc<int> g(110,vc<int>(110));
        f[0][0]=g[0][0]=1;
        for(int i=1;i<=n;++i){
            int x=A[i]%mod;
            for(int j=1;j<=mod;++j){
                for(int k=0;k<mod;++k){
                    f[j][k]=(g[j][k]+g[j-1][((k-x)%mod+mod)%mod])%P;
                }
            }
            g=f;
        }
        ans=(ans+f[mod][0])%P;
    }
    std::cout<<ans<<'\n';
    return 0;
}