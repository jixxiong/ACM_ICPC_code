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
    int n,m; std::cin>>n>>m;
    std::vector<std::string>A(n);
    for(int i=0;i<n;++i) std::cin>>A[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(A[i][j]=='o'){
                for(int a=i;a<n;++a){
                    for(int b=(a==i)?j+1:0;b<m;++b){
                        if(A[a][b]=='o'){
                            std::cout<<std::abs(i-a)+std::abs(j-b)<<'\n';
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}