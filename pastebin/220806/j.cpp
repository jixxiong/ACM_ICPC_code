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

using node=std::pair<i32,i32>;

vc<node>A;
vc<i32>X={1,1,1,1,1};
vc<i32>Y={1,2,3,4,5};

i32 mx=18;
i32 d=2;
vc<node>B;

auto check()->bool{
    if(B.empty()) return false;
    for(auto [x,y]:B){
        for(i32 i=0;i<(i32)X.size();++i){
            auto dx=X[i],dy=Y[i];
            i32 cnt=0;
            for(auto [nx,ny]:B){
                if((nx-x)*dy==(ny-y)*dx){
                    cnt++;
                }
            }
            if(cnt!=d){
                return false;
            }
        }
    }
    return true;
}

auto dfs(i32 i)->void{
    if(check()){
        std::cout<<"FUCK YOU"<<'\n';
        for(auto [x,y]:B){
            std::cout<<x<<' '<<y<<'\n';
        }
        std::cout<<"========\n";
    }
    if((i32)B.size()>mx||i>=(i32)A.size()){
        return ;
    }
    dfs(i+1);
    B.pb(A[i]);
    dfs(i+1);
    B.pop_back();
}

int32_t main(){
    for(i32 i=0;i<=6;++i){
        for(i32 j=0;j<=6;++j){
            A.pb(node(i,j));
        }
    }
    dfs(0);
    return 0;
}