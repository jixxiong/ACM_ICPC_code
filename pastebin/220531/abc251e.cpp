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
ll const INF=0x3f3f3f3f3f3f3f3f;

int32_t main(){
    int n; std::cin>>n;
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    std::vector<std::vector<std::vector<ll>>>f(2,std::vector<std::vector<ll>>(2,std::vector<ll>(n+1)));
    f[0][0][1]=0; f[1][0][1]=INF;
    f[1][1][1]=A[1]; f[0][1][1]=INF;
    for(int i=2;i<=n-1;++i){
        for(int j=0;j<2;++j){
            f[j][0][i]=f[j][1][i-1];
            f[j][1][i]=std::min(f[j][0][i-1],f[j][1][i-1])+A[i];
        }
    }
    std::cout<<std::min({f[0][1][n-1]+A[n],f[0][0][n-1]+A[n],f[1][0][n-1]+A[n],f[1][1][n-1]})<<'\n';
    return 0;
}