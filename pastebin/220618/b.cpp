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
    std::vector<int>A(4);
    int ans=0;
    for(int i=1;i<=n;++i){
        int x; std::cin>>x;
        A[0]++;
        for(int j=3;j>=0;--j){
            if(x + j>=4){
                ans += A[j];
                A[j]=0;
            }else{
                A[x + j] = A[j];
                A[j] = 0;
            }
        }
    }
    std::cout<<ans<<'\n';
    return 0;
}