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
        int h,w; std::cin>>h>>w;
        std::vector<std::vector<int>>A(h+1,std::vector<int>(w+1));
        int mx=-100000;
        int mi=0,mj=0;
        for(int i=1;i<=h;++i){
            for(int j=1;j<=w;++j){
                std::cin>>A[i][j];
                if((i==1&&j==1)||A[i][j]>mx){
                    mx=A[i][j];
                    mi=i;
                    mj=j;
                }
            }
        }
        std::cout<<std::max(mi,h-mi+1)*std::max(mj,w-mj+1)<<'\n';
    }
    return 0;
}