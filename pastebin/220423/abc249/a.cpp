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
    int a,b,c,d,e,f,x; std::cin>>a>>b>>c>>d>>e>>f>>x;
    std::swap(a,b); std::swap(d,e);
    ll p=x/(b+c)*b*a+(std::min(b,x%(b+c)))*a;
    ll q=x/(e+f)*e*d+(std::min(e,x%(e+f)))*d;
    if(p>q) std::cout<<"Takahashi\n";
    if(p<q) std::cout<<"Aoki\n";
    if(p==q) std::cout<<"Draw\n";
    return 0;
}