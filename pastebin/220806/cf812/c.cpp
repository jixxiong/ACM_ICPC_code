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

struct node{
    i32 x;
    i32 cnt;
    node(i32 x=0,i32 cnt=0):x(x),cnt(cnt){}
    bool operator<(node o)const{
        if(cnt==o.cnt) return x<o.x;
        return cnt<o.cnt;
    }
};

int32_t main(){
    i32 T; std::cin>>T;
    while(T--){
        i32 n; std::cin>>n;
        i32 sq=std::sqrt(2*n-2);
        if((sq+1)*(sq+1)<=2*n-2) sq++;
        if((sq*sq)>2*n-2) sq--;
        vc<i32>ans(n);
        vc<char>vis(n);
        bool fail=false;
        for(i32 i=n-1;i>=0;--i){
            fail=true;
            for(i32 j=sq;j*j>=i;--j){
                if(j*j-i<n&&!vis[j*j-i]){
                    vis[j*j-i]=true;
                    fail=false;
                    ans[i]=j*j-i;
                    break;
                }
            }
            if(fail) break;
        }
        if(fail){
            std::cout<<-1<<'\n';
            continue;
        }
        for(i32 i=0;i<n;++i){
            std::cout<<ans[i]<<" \n"[i==n-1];
        }
    }
    return 0;
}