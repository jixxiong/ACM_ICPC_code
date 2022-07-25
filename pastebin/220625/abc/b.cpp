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
using ld=long double;

int32_t main(){
    int n,k,q; std::cin>>n>>k>>q;
    std::vector<int>A(n+1);
    std::vector<int>B(k+1);
    for(int i=1;i<=k;++i){
        int x; std::cin>>x;
        A[x]=i;
        B[i]=x;
    }
    for(int i=1;i<=q;++i){
        int x; std::cin>>x;
        if(B[x]+1>n||A[B[x]+1]) continue;
        else{
            A[B[x]+1]=x;
            A[B[x]]=0;
            B[x]++;
        }
    }
    for(int i=1;i<=k;++i) std::cout<<B[i]<<" \n"[i==k];
    return 0;
}