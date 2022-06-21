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

std::bitset<4096>vis[2][1024];

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,m; std::cin>>n>>m;
        std::vector<std::vector<int>>A(n+1,std::vector<int>(m+1));
        for(int i=1;i<=m;++i){
            vis[0][i].reset();
            vis[1][i].reset();
        }
        int flg=0;  
        for(int i=1;i<=n;++i){
            flg^=1;
            for(int j=1;j<=m;++j){
                std::cin>>A[i][j];
                if(i==1&&j==1){
                    vis[flg][1].set(2048);
                    if(A[i][j]==1){
                        vis[flg][1]=vis[flg][1]<<1;
                    }else{
                        vis[flg][1]=vis[flg][1]>>1;
                    }
                    continue;
                }
                if(A[i][j]==1){
                    vis[flg][j]=(vis[flg^1][j]<<1)|(vis[flg][j-1]<<1);
                }else{
                    vis[flg][j]=(vis[flg^1][j]>>1)|(vis[flg][j-1]>>1);
                }
            }
        }
        std::cout<<(vis[flg][m][2048]?"YES":"NO")<<'\n';
    }
    return 0;
}