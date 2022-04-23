#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int n; std::cin>>n;
    std::vector<int>A(n);
    std::map<int,int>cnt;
    for(int i=0;i<n;++i) std::cin>>A[i],cnt[A[i]]++;
    ll ret=0;
    for(auto x:A){
        for(int i=1;i<=x/i;++i){
            if(x%i==0){
                ret+=(i==x/i?1:2)*(ll)cnt[i]*cnt[x/i];
            }
        }
    }
    std::cout<<ret<<'\n';
    return 0;
}