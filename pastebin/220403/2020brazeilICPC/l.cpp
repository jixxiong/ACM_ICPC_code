#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

using node=std::array<char,26>;

int main(){
    int n,m; std::cin>>n>>m;
    std::vector<std::string>A(n);
    for(int i=0;i<n;++i) std::cin>>A[i];
    int K; std::cin>>K;
    std::map<node,int>mp;
    for(int i=0;i<K;++i){
        std::string s; std::cin>>s;
        node t{};
        for(auto ch:s){
            t[ch-'A']++;
        }
        mp[t]=i;
    }
    std::vector<std::vector<int>>vis(n,std::vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            node tmp{};
            for(int k=j;k<m&&k<j+15;++k){
                tmp[A[i][k]-'A']++;
                if(mp.count(tmp)){
                    int id=mp[tmp];
                    for(int t=j;t<=k;++t){
                        vis[i][t]|=1<<id;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            node tmp{};
            for(int k=j;k<n&&k<j+15;++k){
                tmp[A[k][i]-'A']++;
                if(mp.count(tmp)){
                    int id=mp[tmp];
                    for(int t=j;t<=k;++t){
                        vis[t][i]|=1<<id;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            node tmp{};
            for(int k=0;k<15;++k){
                int x=i+k,y=j+k;
                if(x<n&&y<m){
                    tmp[A[x][y]-'A']++;
                    if(mp.count(tmp)){
                        int id=mp[tmp];
                        for(int t=0;t<=k;++t){
                            vis[i+t][j+t]|=1<<id;
                        }
                    }
                }else{
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            node tmp{};
            for(int k=0;k<15;++k){
                int x=i+k,y=j-k;
                if(x<n&&y>=0){
                    tmp[A[x][y]-'A']++;
                    if(mp.count(tmp)){
                        int id=mp[tmp];
                        for(int t=0;t<=k;++t){
                            vis[i+t][j-t]|=1<<id;
                        }
                    }
                }else{
                    break;
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(vis[i][j]&&(vis[i][j]&(vis[i][j]-1)))cnt++;
        }
    }
    std::cout<<cnt<<std::endl;
    return 0;
}