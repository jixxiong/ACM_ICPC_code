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

const ld EPS=1e-10;
const ld PI=std::acos((ld)-1.0);

int fcmp(ld x,ld y=0,ld eps=EPS){
    if(std::abs(x-y)<EPS) return 0;
    if(x<y) return -1;
    return 1;
}

struct Edge{
    int u,v;
    ld d;
};

bool bellman_ford(std::vector<Edge>const&G,int n){
    std::vector<ld>dis(n+1,1e18); dis[0]=0;
    for(int i=1;i<=n;++i){
        bool flg=false;
        for(auto [u,v,d]:G){
            if(fcmp(dis[u]+d,dis[v])<0){
                flg=true;
                dis[v]=dis[u]+d;
            }
        }
        if(flg&&i==n){
            return true;
        }
    }
    return false;
}

int32_t main(){
    int n,m; std::cin>>n>>m;
    std::vector<Edge>A;
    for(int i=1;i<=m;++i){
        int u,v,x,y; 
        std::cin>>x>>u>>y>>v;
        A.pb(Edge{u,v,-std::log(1.0*y/x)});
    }
    ld l=EPS,r=1;
    while(fcmp(l,r)<0){
        ld mid=(l+r)/2;
        auto B=A;
        for(auto& [u,v,d]:B){
            d-=std::log(mid);
        }
        if(bellman_ford(B,n))r=mid;
        else l=mid;
    }
    std::cout<<std::fixed<<std::setprecision(10);
    std::cout<<l<<'\n';
    return 0;
}