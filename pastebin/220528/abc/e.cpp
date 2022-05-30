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

int32_t main(){
    int const p=998244353;
    int n,m,k; std::cin>>n>>m>>k;
    if(k==0){
        int ret=1;
        for(int i=1;i<=n;++i) ret=(ll)ret*m%p;
        std::cout<<ret<<'\n';
        return 0;
    }
    std::vector<std::vector<int>>f(n+1,std::vector<int>(m+1));
    for(int i=1;i<=m;++i) f[1][i]=i;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(j-k>=1) f[i][j]=f[i-1][j-k];
            if(j+k<=m) f[i][j]=(f[i][j]+(p+(f[i-1][m]-f[i-1][j+k-1])%p)%p)%p;
            f[i][j]=(f[i][j]+f[i][j-1])%p;
        }
    }
    std::cout<<f[n][m]<<'\n';
    return 0;
}