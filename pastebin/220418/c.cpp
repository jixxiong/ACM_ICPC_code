#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
const int mo=998244353;

int main(){
    int n,m,k; std::cin>>n>>m>>k;
    std::vector<int>f(k+1),g(k+1);
    g[0]=1;
    for(int i=1;i<=n;++i){
        for(int s=k;s>=1;s--){
            for(int j=1;j<=m;++j){
                if(s>=j) f[s]=(f[s]+g[s-j])%mo;
            }
        }
        g=f;std::fill(all(f),0);
    }
    int ret=0;
    for(int i=n;i<=k;++i) ret=(ret+g[i])%mo;
    std::cout<<ret<<'\n';
    return 0;
}