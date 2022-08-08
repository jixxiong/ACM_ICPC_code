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

int32_t main(){
    i32 n; std::cin>>n;
    i32 h=4*n+5,w=13*n+19;
    vvc<char>A(h+1,vc<char>(w+1,'.'));
    for(i32 i=1;i<=w;++i){
        A[1][i]=A[h][i]='*';
    }
    for(i32 i=1;i<=h;++i){
        A[i][1]=A[i][w]='*';
    }
    [&](){ // N
        i32 x=n+2,y=n+3;
        for(i32 i=0;i<2*n+3;++i){
            A[x+i][y]='@';
            A[x+i][y+i]='@';
            A[x+i][y+2*n+2]='@';
        }
    }();
    [&](){ // F
        i32 x=n+2,y=n+3+2*n+3+n+1;
        for(i32 i=0;i<2*n+3;++i){
            A[x+i][y]='@';
            A[x][y+i]='@';
            A[x+n+1][y+i]='@';
        }
    }();
    [&](){ // L
        i32 x=n+2,y=n+3+2*n+3+n+1+2*n+3+n+1;
        for(i32 i=0;i<2*n+3;++i){
            A[x+i][y]='@';
            A[x+2*n+2][y+i]='@';
        }
    }();
    [&](){ // S
        i32 x=n+2,y=n+3+2*n+3+n+1+2*n+3+n+1+2*n+3+n+1;
        for(i32 i=0;i<n+2;++i){
            A[x+i][y]='@';
            A[x+n+1+i][y+2*n+2]='@';
        }
        for(i32 i=0;i<2*n+3;++i){
            A[x][y+i]='@';
            A[x+n+1][y+i]='@';
            A[x+2*n+2][y+i]='@';
        }
    }();
    for(i32 i=1;i<=h;++i){
        for(i32 j=1;j<=w;++j){
            std::cout<<A[i][j];
        }
        std::cout<<'\n';
    }
    return 0;
}