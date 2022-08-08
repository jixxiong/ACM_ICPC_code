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
    i32 T; std::cin>>T;
    while(T--){
        i32 n; std::cin>>n;
        i32 mxx=0,mnx=0,mxy=0,mny=0;
        while(n--){
            i32 x,y; std::cin>>x>>y;
            if(y==0){
                mxx=std::max(mxx,x);
                mnx=std::min(mnx,x);
            }else{
                mxy=std::max(mxy,y);
                mny=std::min(mny,y);
            }
        }
        std::cout<<((i64)(mxx-mnx)*2+(i64)(mxy-mny)*2)<<'\n';
    }
    return 0;
}