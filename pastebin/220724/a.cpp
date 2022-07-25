#include <bits/stdc++.h>

using namespace std::string_literals;
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

template<typename T,T init=T{}> auto Vec(int s){ return std::vector(s,init); }
template<typename T,T init=T{},typename...L> auto Vec(int s,L...l){ return std::vector(s,Vec<T,init>(l...)); }

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        for(int i=2;i<=n;++i){
            std::cout<<i<<' ';
        }
        std::cout<<1<<'\n';
    }
    return 0;
}