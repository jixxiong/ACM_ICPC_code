#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;
using i32=int32_t;
using i64=int64_t;
using i128=__int128;

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

using node = std::pair<i32,i32>;
vc<node>mv{{-1,0},{1,0},{0,-1},{0,1}};

int32_t main(){
    i32 n,m; std::cin>>n>>m;
    vvc<i32>A(n+2,vc<i32>(m+2));
    vvc<i32>vis(n+2,vc<i32>(m+2));
    vvc<i64>ans(n+2,vc<i64>(m+2));
    for(i32 i=1;i<=n;++i){
        for(i32 j=1;j<=m;++j){
            std::cin>>A[i][j];
        }
    }
    i32 cnt=0;
    auto check=[&](i32 h,i32 bx,i32 by,bool clear){
        vc<node>visited; visited.pb(node(bx,by));
        std::queue<node>q; q.push(node(bx,by));
        vis[bx][by]=++cnt;
        bool ok=true;
        while(!q.empty()){
            auto [x,y]=q.front(); q.pop();
            for(auto [dx,dy]:mv){
                auto nx=x+dx,ny=y+dy;
                if(vis[nx][ny]==cnt) continue;
                if(A[nx][ny]>=h) continue;
                if(nx==0||nx==n+1||ny==0||ny==m+1){
                    ok=false;
                    break;
                }
                vis[nx][ny]=cnt;
                q.push(node(nx,ny));
                visited.pb(node(nx,ny));
            }
            if(!ok) break;
        }
        if(clear){
            for(auto [x,y]:visited){
                vis[x][y]=0;
            }
        }else{
            for(auto [x,y]:visited){
                ans[x][y]=(i64)h-A[x][y];
            }
        }
        return ok;
    };
    for(i32 i=1;i<=n;++i){
        for(i32 j=1;j<=m;++j){
            if(vis[i][j]) continue;
            i32 l=A[i][j]-1,r=1000000001;
            while(l+1<r){
                i32 mid=((i64)l+r)>>1;
                if(check(mid,i,j,true)) l=mid;
                else r=mid;
            }
            if(l!=A[i][j]-1){
                check(l,i,j,false);
            }
        }
    }
    for(i32 i=1;i<=n;++i){
        for(i32 j=1;j<=m;++j){
            std::cout<<ans[i][j]<<" \n"[j==m];
        }
    }
    return 0;
}