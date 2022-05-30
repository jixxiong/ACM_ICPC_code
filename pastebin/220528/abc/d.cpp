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
    int n,a,b; std::cin>>n>>a>>b;
    ll c=(ll)a*b/std::__gcd(a,b);
    std::cout<<(
        (ll)n*(n+1)/2-
        (ll)a*(n/a)*(n/a+1)/2-
        (ll)b*(n/b)*(n/b+1)/2+
        (ll)c*(n/c)*(n/c+1)/2
    )<<'\n';
    return 0;
}