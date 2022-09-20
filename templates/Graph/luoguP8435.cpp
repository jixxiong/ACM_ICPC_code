#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

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

using i32=int32_t;
using i64=int64_t;
using i128=__int128;
ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

// 求无向图的割点割边信息
struct CutEdge{
    vvc<char>ce;   // ce[i][j]=true 代表 i->G[i][j] 为割边
    vc <char>cv;   // cv[i]=true 代表点 i 为割点
    i32 edcc;      // edcc 边双数量
    i32 ecut_num;  // ecut_num 割边数量
    vvc<i32> eDCC; // eDCC 为按照边双连通分量缩点之后的图，用割边把边双连起来
    vc <i32> ecol; // ecol[i] 为第 i 个点所处的边双连通分量的编号
    i32 vdcc;      // vdcc 点双数量
    i32 vcut_num;  // vcut_num 割点数量
    vvc<i32> vBCC; // vBCC 为点双连通分量包含的点的编号
    vvc<i32> vDCC; // vDCC 为按照点双连通分量缩点之后的图, 点双和割点连边
    vvc<i32> vcol; // vcol[i] 为第 i 个点所处的点双连通分量的编号有哪些
    CutEdge(vvc<i32>const&G,vvc<i32>const&inv,i32 n):
    ce(n+1),cv(n+1),edcc(0),ecol(n+1),vdcc(0),vcut_num(0),vcol(n+1){
        // tarjan
        vc<i32>dfn(n+1),low(n+1);
        i32 tic=0;
        vc<i32>stk;
        std::function<void(i32,i32,i32)>tarjan=[&](i32 u,i32 f,i32 idx){
            stk.pb(u);
            low[u]=dfn[u]=++tic;
            i32 cnt=0,son=0;
            ce[u].resize(G[u].size());
            for(int i=0;i<(i32)G[u].size();++i){
                i32 v=G[u][i];
                if(!dfn[v]){
                    son++; 
                    tarjan(v,u,i);
                    low[u]=std::min(low[u],low[v]);
                    if(low[v]>dfn[u]){
                        ce[v][inv[u][i]]=ce[u][i]=true;
                    }
                    if(low[v]>=dfn[u]){
                        cnt++; vdcc++; vBCC.resize(vdcc+1);
                        do{ 
                            vcol[stk.back()].pb(vdcc);
                            vBCC[vdcc].pb(stk.back());
                            stk.pop_back();
                        }while(vBCC[vdcc].back()!=v);
                        vcol[u].pb(vdcc);
                        vBCC[vdcc].pb(u);
                    }
                }else if(~f&&v!=f&&i!=inv[f][idx]){
                    low[u]=std::min(low[u],dfn[v]);
                }
            }
            if(u==f?cnt>=2:cnt>=1){
                cv[u]=true;
            }
            if(f==-1&&son==0){
                vdcc++; vBCC.resize(vdcc+1);
                vBCC[vdcc].pb(u);
                return ;
            }
        };
        for(i32 i=1;i<=n;++i){
            if(dfn[i]) continue;
            tarjan(i,-1,0);
        }

        // // e-DCC
        // vvc<i32>g(n+1);
        // for(i32 i=1;i<=n;++i){
        //     for(i32 j=0;j<(i32)G[i].size();++j){
        //         if(!ce[i][j]){
        //             g[i].pb(G[i][j]);
        //         }
        //     }
        // }
        // std::function<void(i32)> dfs1=[&](i32 u){
        //     ecol[u]=edcc;
        //     for(auto v:g[u]){
        //         if(ecol[v]) continue;
        //         dfs1(v);
        //     }
        // };
        // for(i32 i=1;i<=n;++i){
        //     if(ecol[i]) continue;
        //     edcc++;
        //     dfs1(i);
        // }
        // eDCC.resize(edcc+1);
        // for(i32 i=1;i<=n;++i){
        //     for(i32 j=0;j<(i32)G[i].size();++j){
        //         if(ce[i][j]){
        //             eDCC[ecol[i]].pb(ecol[G[i][j]]);
        //         }
        //     }
        // }

        // v-DCC
        vc<i32>id(n+1);
        i32 vdcc_num=vdcc;
        for(i32 i=1;i<=n;++i){
            if(cv[i]){
                id[i]=++vdcc_num;
                vcut_num++;
            }
        }
        vDCC.resize(vdcc_num+1);
        for(i32 u=1;u<=vdcc;++u){
            for(auto x:vBCC[u]){
                i32 v=id[x];
                if(cv[v]){
                    vDCC[v].pb(u);
                    vDCC[u].pb(v);
                }
            }
        }
    }
};

int32_t main(){
    i32 n,m; std::cin>>n>>m;
    vvc<i32>G(n+1),inv_idx(n+1);
    for(i32 i=1;i<=m;++i){
        i32 u,v; std::cin>>u>>v;
        i32 iu=G[u].size(),iv=G[v].size();
        inv_idx[u].pb(iv),inv_idx[v].pb(iu);
        G[u].pb(v); G[v].pb(u);
    }
    CutEdge C(G,inv_idx,n);
    std::cout<<C.vdcc<<'\n';
    for(i32 i=1;i<=C.vdcc;++i){
        std::cout<<C.vBCC[i].size();
        for(i32 x:C.vBCC[i]){
            std::cout<<' '<<x;
        }
        std::cout<<'\n';
    }
    return 0;
}