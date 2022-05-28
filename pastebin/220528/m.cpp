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
    int n; std::cin>>n;
    std::vector<int>A(n);
    for(int i=0;i<n;++i) std::cin>>A[i];
    std::vector<std::vector<int>>c(31,std::vector<int>(2));
    for(int bit=0;bit<=30;++bit)
        for(int i=0;i<n;++i) 
            c[bit][(A[i]>>bit)&1]++;
    bool fail=false;
    for(int bit=0;bit<=30;++bit){
        if(c[bit][1]&1||!(c[bit][0]&1)) continue;
        else fail=true;
    }
    std::cout<<(fail?"NO":"YES")<<'\n';
    return 0;
}