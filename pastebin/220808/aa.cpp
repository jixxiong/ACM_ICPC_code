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

i32 d;
i32 H,W;
i32 ans=0;

char vis[20][20];
char const* str=".*#&%";

struct node{
    i32 x1,y1,x2,y2;
};

bool all_vis(i32 x1,i32 y1,i32 x2,i32 y2){
    for(i32 i=x1;i<=x2;++i){
        for(i32 j=y1;j<=y2;++j){
            if(!vis[i][j]) return false;
        }
    }
    return true;
}

bool any_vis(i32 x1,i32 y1,i32 x2,i32 y2){
    for(i32 i=x1;i<=x2;++i){
        for(i32 j=y1;j<=y2;++j){
            if(vis[i][j]) return true;
        }
    }
    return false;
}

vc<node>A;

void dfs(i32 p){
    if(p==d){
        if(all_vis(1,1,H,W)){
            ans++;
        }
        return ;
    }
    for(i32 x1=1;x1<=H;++x1){
        for(i32 y1=1;y1<=W;++y1){
            if(vis[x1][y1]) continue;
            else{
                for(i32 x2=x1;x2<=H;++x2){
                    for(i32 y2=y1;y2<=W;++y2){
                        if(any_vis(x1,y1,x2,y2)) break;
                        for(i32 x3=x1;x3<=x2;++x3){
                            for(i32 y3=y1;y3<=y2;++y3){
                                vis[x3][y3]=str[p];
                            }
                        }
                        A.pb(node{x1,y1,x2,y2});
                        dfs(p+1);
                        A.pop_back();
                        for(i32 x3=x1;x3<=x2;++x3){
                            for(i32 y3=y1;y3<=y2;++y3){
                                vis[x3][y3]=0;
                            }
                        }
                    }
                }
                return;
            }
        }
    }
}

i32 qpow(i32 x,i32 y){
    i32 ret=1;
    while(y--) ret*=x;
    return ret;
}

i32 z_(){
    return 1;
}

i32 a_(){
    return W+H;
}

i32 b_(){
    return W*H+H*H+W*W;
}

i32 c_(){
    return H*W*W+W*H*H+H*H*H+W*W*W;
}

i32 d_(){
    return H*H*W*W+H*H*H*W+W*W*W*H+H*H*H*H+W*W*W*W;
}

// i32 c_(){
//     return H*H+W*W;
// }

// i32 d_(){
//     return H*W*W+W*H*H;
// }

// i32 e_(){
//     return H*H*H+W*W*W;
// }

// i32 f_(){
//     return H*H*W*W;
// }

// i32 g_(){
//     return H*H*H*W+W*W*W*H;
// }

// i32 h_(){
//     return H*H*H*H+W*W*W*W;
// }

vvc<std::function<i32()>>fs{
    {},
    {z_},
    {z_,a_},
    {z_,a_,b_},
    {z_,a_,b_,c_},
    {z_,a_,b_,c_,d_}
};

int32_t main(){
    for(d=2;d<=5;++d){
        i32 cnt=0;
        vvc<i32>par(fs[d].size()+3);
        for(W=1,H=1;cnt<(i32)fs[d].size()+3;++H,W+=2,++cnt){
            ans=0;
            dfs(0);
            for(auto f:fs[d]) par[cnt].pb(f());
            par[cnt].pb(ans);
            du(W,H,ans);
        }
        for(auto v:par){
            for(i32 x:v){
                std::cout<<x<<' ';
            }
            std::cout<<'\n';
        }
        du("============");
    }
    return 0;
}
/*

*/