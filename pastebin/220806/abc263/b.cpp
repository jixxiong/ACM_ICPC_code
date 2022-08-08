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

vc<i32>ret;
i32 n,m;

auto dfs(i32 i,i32 j)->void{
    if(i==n){
        bool first=true;
        for(auto x:ret){
            if(first) first=false;
            else std::cout<<' ';
            std::cout<<x;
        }
        std::cout<<'\n';
        return ;
    }
    if(j>m) return ;
    ret.pb(j);
    dfs(i+1,j+1);
    ret.pop_back();
    dfs(i,j+1);
}

int32_t main(){
    std::cin>>n>>m;
    dfs(0,1);
    return 0;
}