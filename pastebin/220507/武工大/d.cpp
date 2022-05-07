#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int n,m; std::cin>>n>>m;
    std::vector<std::vector<int>>A(n+1,std::vector<int>(m+1));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            std::cin>>A[i][j];
        }
    }
    int x,y,w,z;
    std::cin>>x>>y>>w>>z;
    int l=A[x][y]-1,r=n*m+1;
    while(l+1<r){
        int mid=(l+r)>>1;
        std::queue<std::pair<int,int>>q;
        std::vector<std::vector<char>>vis(n+1,std::vector<char>(m+1));
        const std::vector<std::pair<int,int>>mv={{0,1},{0,-1},{1,0},{-1,0}};
        q.push({x,y}); vis[x][y]=true;
        while(!q.empty()){
            auto [cx,cy]=q.front(); q.pop();
            for(auto [dx,dy]:mv){
                int nx=cx+dx,ny=cy+dy;
                if(nx<1||nx>n||ny<1||ny>m||
                    vis[nx][ny]||
                    A[nx][ny]>mid) continue;
                vis[nx][ny]=true;
                q.push({nx,ny});
            }
        }
        if(vis[w][z]){
            r=mid;
        }else{
            l=mid;
        }
    }
    std::cout<<r<<'\n';
    return 0;
}