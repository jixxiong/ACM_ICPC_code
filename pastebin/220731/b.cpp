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

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const INF=0x3f3f3f3f3f3f3f3f;

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,x; std::cin>>n>>x;
        vc<int>A(n+1);
        for(int i=1;i<=n;++i){
            std::cin>>A[i];
        }
        int lm=-INF,rm=INF;
        int cnt=0;
        for(int i=1;i<=n;++i){
            int l=A[i]-x,r=A[i]+x;
            if(l>lm) lm=l;
            if(r<rm) rm=r;
            if(lm>rm) lm=l,rm=r,cnt++;
        }
        std::cout<<cnt<<'\n';
    }
    return 0;
}