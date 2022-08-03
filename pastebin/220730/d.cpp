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

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);
int const mod=998244353;

int qpow(int x,int y,int p=mod){
    if(y==0) return 1;
    int ret=1;
    while(y){
        if(y&1) ret=ret*x%p;
        x=x*x%p;
        y>>=1;
    }
    return ret;
}

std::bitset<401>ok[11][401][401];
int n;

int32_t solve(int32_t iq,int32_t eq,int32_t aq){
    int32_t ret=0;
    for(int32_t i=1;i<=n;++i){
        ret+=ok[i][iq][eq][aq];
    }
    return ret;
};

int32_t main(){
    int32_t q; std::cin>>n>>q;
    for(int32_t i=1;i<=n;++i){
        int32_t k; std::cin>>k; 
        for(int32_t j=0;j<k;++j){
            int32_t a,b,c;
            std::cin>>a>>b>>c;
            ok[i][a][b][c]=true;
        }
    }
    for(int32_t i=1;i<=n;++i){
        for(int32_t j=1;j<=400;++j){
            for(int32_t k=1;k<=400;++k){
                for(int32_t r=1;r<=400;++r){
                    ok[i][j][k][r]=(ok[i][j][k][r]||ok[i][j-1][k][r]||ok[i][j][k-1][r]||ok[i][j][k][r-1]);
                }
            }
        }
    }
    int seed; std::cin>>seed;
    std::mt19937 rng(seed);
    std::uniform_int_distribution<> u(1,400);
    int32_t lastans=0;
    int ret=0;
    for(int32_t i=1;i<=q;i++){
        int32_t IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
        int32_t EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
        int32_t AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
        lastans=solve(IQ,EQ,AQ);        // The answer to the i-th friend
        ret=(ret+lastans*qpow(seed,q-i)%mod)%mod;
    }
    std::cout<<ret<<'\n';
    return 0;
}