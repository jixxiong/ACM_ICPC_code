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
    vc<i32>A(n+1);
    for(i32 i=1;i<=n;++i){
        std::cin>>A[i];
    }
    vc<i32>B(n+1);
    std::iota(all(B),0);
    std::sort(1+all(B),[&](i32 i,i32 j){
        return A[i]<A[j];
    });
    std::queue<i32>q;
    for(i32 i=1;i<=n;++i){
        q.push(B[i]);
    }
    vc<i32>ans(2*n+1);
    i32 j=1;
    while(!q.empty()){
        i32 i=q.front(); q.pop();
        bool fail=false;
        du(i);
        for(i32 k=1;k<(2*n+A[i]-1)/A[i];++k){
            i32 pos=j+(k-1)*A[i];
            if(ans[pos]){
                fail=true;
                q.push(i);
                break;
            }
        }
        if(!fail){
            for(i32 k=1;k<=(2*n+A[i]-1)/A[i];++k){
                i32 pos=j+(k-1)*A[i];
                while(ans[pos]){
                    pos--;
                    if(pos==0) pos=2*n;
                }
                ans[pos]=i;
            }
        }
    }
    std::cout<<2*n<<'\n';
    for(i32 i=1;i<=2*n;++i){
        std::cout<<(ans[i]?ans[i]:B[n])<<" \n"[i==2*n];
    }
    return 0;
}