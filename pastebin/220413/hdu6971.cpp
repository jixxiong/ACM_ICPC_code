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
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n),B(n);
        for(auto& x:A) std::cin>>x;
        for(auto& x:B) std::cin>>x;
        std::vector<std::vector<int>>m(4,std::vector<int>(n));
        for(int i=n-1;i>=0;--i){
            m[0][i]=m[1][i]=A[i];
            m[2][i]=m[3][i]=B[i];
            for(int bit=18;bit>=0;--bit){
                if((i|(1<<bit))>=n) continue;
                m[0][i]=std::max(m[0][i|(1<<bit)],m[0][i]);
                m[1][i]=std::min(m[1][i|(1<<bit)],m[1][i]);
                m[2][i]=std::max(m[2][i|(1<<bit)],m[2][i]);
                m[3][i]=std::min(m[3][i|(1<<bit)],m[3][i]);
            }
        }
        std::vector<ll>f(n);
        ll ret=0;
        for(int i=n-1;i>=0;--i){
            f[i]=std::max({(ll)m[0][i]*m[2][i],(ll)m[0][i]*m[3][i],(ll)m[1][i]*m[2][i],(ll)m[1][i]*m[3][i]});
            if(i!=n-1) f[i]=std::max(f[i],f[i+1]);
            ret=(ret+f[i])%mo;
        }
        if(ret<0) ret+=mo;
        std::cout<<ret<<'\n';
    }
    return 0;
}