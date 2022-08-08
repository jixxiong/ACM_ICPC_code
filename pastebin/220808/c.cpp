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
        vc<char>vis(n+1);
        vc<i32>A(n+1);
        vc<i32>B(n+1);
        i32 fail=true;
        i32 ex=0,ne=0;
        for(i32 i=1;i<=n;++i){
            std::cin>>A[i];
            B[A[i]]=i;
            if(!ex) ex=A[i];
            if(!ne&&A[i]!=ex) ne=A[i];
            if(i!=1&&A[i]!=A[i-1]) fail=false;
        }
        if(fail){
            std::cout<<"NO"<<'\n';
        }else{
            std::cout<<"YES"<<'\n';
            vc<i32>ans(n+1);
            std::iota(all(ans),0);
            for(i32 i=1;i<=n;++i){
                if(ans[i]==A[i]){
                    i32 j=B[A[i]==ne?ex:ne];
                    std::swap(ans[i],ans[j]);
                }
            }
            for(i32 i=1;i<=n;++i){
                std::cout<<ans[i]<<" \n"[i==n];
            }
        }
    }
    return 0;
}