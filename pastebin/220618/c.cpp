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
    std::array<int,3>w,h;
    std::cin>>h[0]>>h[1]>>h[2]
            >>w[0]>>w[1]>>w[2];
    int cnt=0;
    for(int i=1;i<=30;++i){
        for(int j=1;j<=30;++j){
            for(int k=1;k<=30;++k){
                for(int r=1;r<=30;++r){
                    int r1=h[0]-i-j;
                    int r2=h[1]-k-r;
                    int c1=w[0]-i-k;
                    int c2=w[1]-j-r;
                    if(r1<=0 || r2<=0 || c1<=0 || c2<=0){
                        continue;
                    }
                    if(h[2]-c1-c2!=w[2]-r1-r2 || h[2]-c1-c2<=0){
                        continue;
                    }
                    cnt++;
                }
            }
        }
    }
    std::cout<<cnt<<'\n';
    return 0;
}