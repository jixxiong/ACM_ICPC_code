#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
#define ld long double
#define ll long long
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;
template<typename T>using vvvvvc=std::vector<vvvvc<T>>;
template<typename T>vvc<T> vcc(i32 s1=0,i32 s2=0,const T&init=T()){ return vvc<T>(s1,vc<T>(s2,init)); }
template<typename T>vvvc<T> vccc(i32 s1=0,i32 s2=0,i32 s3=0,const T&init=T()){ return vvvc<T>(s1,vcc(s2,s3,init)); }
template<typename T>vvvvc<T> vcccc(i32 s1=0,i32 s2=0,i32 s3=0,i32 s4=0,const T&init=T()){ return vvvvc<T>(s1,vccc(s2,s3,s4,init)); }
template<typename T>vvvvvc<T> vccccc(i32 s1=0,i32 s2=0,i32 s3=0,i32 s4=0,i32 s5=0,const T&init=T()){ return vvvvvc<T>(s1,vcccc(s2,s3,s4,s5,init)); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

int32_t main(){
    i32 n,k; std::cin>>n>>k;
    auto G=vcc<i32>(n+1);
    for(i32 i=1;i<n;++i){
        i32 u,v; std::cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    auto dep=vc<i32>(n+1);
    dep[1]=1;
    auto sz=vc<i32>(n+1);
    std::function<void(i32,i32)> dfs=[&](i32 u,i32 f){
        sz[u]=1;
        for(auto v:G[u]){
            if(v==f) continue;
            dep[v]=dep[u]+1;
            dfs(v,u);
            sz[u]+=sz[v];
        }
    };
    dfs(1,1);
    auto A=vc<i32>(n+1);
    std::iota(all(A),0);
    std::sort(1+all(A),[&](i32 i,i32 j){
        return dep[i]-sz[i]>dep[j]-sz[j];
    });
    auto col=vc<i32>(n+1);
    for(i32 i=1;i<=k;++i){
        col[A[i]]=1;
    }
    sz=vc<i32>(n+1);
    auto dp=vc<i64>(n+1);
    std::function<void(i32,i32)>dfs2=[&](i32 u,i32 f){
        sz[u]=col[u];
        for(auto v:G[u]){
            if(v==f) continue;
            dfs2(v,u);
            sz[u]+=sz[v];
            dp[u]+=dp[v];
        }
        if(!col[u]) dp[u]+=sz[u];
    };
    dfs2(1,1);
    std::cout<<dp[1]<<'\n';
    return 0;
}
