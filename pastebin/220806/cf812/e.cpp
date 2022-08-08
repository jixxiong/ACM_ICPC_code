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

struct DSU{
    vc<i32>A;
    DSU(i32 n):A(n+1){ std::iota(all(A),0); }
    i32 get(i32 x){ return x==A[x]?x:(A[x]=get(A[x])); }
    void merge(i32 x,i32 y){ i32 fx=get(x),fy=get(y); if(fx!=fy) A[fx]=fy; }
};

int32_t main(){
    i32 T; std::cin>>T;
    while(T--){
        i32 n; std::cin>>n;
        vvc<i32>A(n+1,vc<i32>(n+1));
        for(i32 i=1;i<=n;++i){
            for(i32 j=1;j<=n;++j){
                std::cin>>A[i][j];
            }
        }
        DSU dsu(2*n);
        for(i32 i=1;i<=n;++i){
            for(i32 j=i+1;j<=n;++j){
                if(A[i][j]==A[j][i]) continue;
                i32 k=A[i][j]>A[j][i];
                i32 fi=dsu.get(i),finvi=dsu.get(i+n),fj=dsu.get(j),finvj=dsu.get(j+n);
                if(k){
                    if(fi==fj||finvi==finvj) continue;
                    dsu.merge(fi,finvj); dsu.merge(fj,finvi);
                    std::swap(A[i][j],A[j][i]);
                }else{
                    if(fi==finvj||fj==finvi){
                        std::swap(A[i][j],A[j][i]);
                        continue;
                    }
                    dsu.merge(fi,fj); dsu.merge(finvi,finvj);
                }
            }
        }
        for(i32 i=1;i<=n;++i){
            for(i32 j=1;j<=n;++j){
                std::cout<<A[i][j]<<" \n"[j==n];
            }
        }
    }
    return 0;
}