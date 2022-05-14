#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int A,B,C,D;
    std::cin>>A>>B>>C>>D;
    ll ret=0;
    for(int i=A+B;i<=B+C;++i){
        ll m1=std::min(i-B,B)-std::max(i-C,A)+1;
        if(m1<=0) continue;
        ll m2=std::min(i-1,D)-C+1;
        if(m2<=0) continue;
        ret+=m1*m2;
    }
    std::cout<<ret<<'\n';
    return 0;
}