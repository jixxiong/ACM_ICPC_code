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
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n+1);
        for(int i=1;i<=n;++i){
            std::cin>>A[i];
        }
        if(n&1){
            std::cout<<"Mike\n";
            continue;
        }else{
            int mi=1,mj=2;
            for(int i=3;i<=n;++i){
                if(i&1){
                    if(A[i]<A[mi]) mi=i;
                }else{
                    if(A[i]<A[mj]) mj=i;
                }
            }
            if(A[mi]==A[mj]){       
                std::cout<<(mi<mj?"Joe\n":"Mike\n");
            }else{
                std::cout<<(A[mi]<A[mj]?"Joe\n":"Mike\n");
            }
            
        }
    }
    return 0;
}