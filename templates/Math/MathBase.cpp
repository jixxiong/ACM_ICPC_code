#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
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

namespace MathBase{
    i32 qpow(i32 x,i32 y,i32 p=mod){
        if(y==0) return 1;
        i32 ret=1;
        while(y){
            if(y&1) ret=(i64)ret*x%p;
            x=(i64)x*x%p;
            y>>=1;
        }
        return ret;
    }
};
using MathBase::qpow;

int32_t main(){
    
    return 0;
}