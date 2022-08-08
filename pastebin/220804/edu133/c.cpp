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
using i32=int64_t;
using i64=int64_t;
using i128=__int128;

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

struct SparseTable{
    vvc<i32>st;
    i32 n;
    SparseTable(vc<i32>const&A,i32 n):st(std::__lg(n)+1,vc<i32>(n+1)),n(n){
        for(i32 i=1;i<=n;++i) st[0][i]=A[i];
        for(i32 j=1;j<=std::__lg(n);++j){
            for(i32 i=1;i+(1<<j)-1<=n;++i){
                st[j][i]=std::max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
            }
        }
    }
    i32 get(i32 l,i32 r){
        assert(l<=r);
        i32 s=std::__lg(r-l+1);
        return std::max(st[s][l],st[s][r-(1<<s)+1]);
    }
};

int32_t main(){
    i32 T; std::cin>>T;
    while(T--){
        i32 n; std::cin>>n;
        vvc<i32>A(3,vc<i32>(n+1));
        for(i32 i=1;i<=2;++i){
            for(i32 j=1;j<=n;++j){
                std::cin>>A[i][j];
            }
        }
        vc<i32>f(2*n+1);
        for(i32 i=1;i<=2*n;++i){
            if(i<=n) f[i]=A[1][i]-i+1;
            else f[i]=A[2][2*n-i+1]-i+1;
        }
        vc<i32>g(2*n+1);
        for(i32 i=1;i<=2*n;++i){
            if(i<=n) g[i]=A[2][i]-i+1;
            else g[i]=A[1][2*n-i+1]-i+1;
        }
        auto order1=[&](i32 i,i32 j){
            return i==1?j:2*n-j+1;
        };
        auto order2=[&](i32 i,i32 j){
            return i==2?j:2*n-j+1;
        };
        SparseTable st1(f,2*n),st2(g,2*n);
        i32 ret=0x7fffffff;
        i32 sum=0;
        for(i32 i=1;i<=n;++i){
            if(i!=1) sum+=std::max(A[i&1?1:2][i]-sum,(i32)0)+1;
            if(i==n){
                ret=std::min(ret,sum+std::max(A[i&1?2:1][n]-sum,(i32)0)+1);
                break;
            }else{
                i32 bg=i&1?order1(1,i+1):order2(2,i+1),ed=i&1?order1(2,i):order2(1,i);
                auto tk=i&1?st1.get(bg,ed):st2.get(bg,ed);
                tk=std::max(tk,sum-(i&1?order1(1,i):order2(2,i)));
                ret=std::min(ret,tk+ed);
                sum+=std::max(A[i&1?2:1][i]-sum,(i32)0)+1;
            }
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}