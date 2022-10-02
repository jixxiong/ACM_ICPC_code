#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
#define ld long double
#define ll long long
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
template<class T>using vc    =std::vector<T>;
template<class T>using vvc   =vc<vc<T>>;
template<class T>using vvvc  =vc<vvc<T>>;
template<class T>using vvvvc =vc<vvvc<T>>;
template<class T>using vvvvvc=vc<vvvvc<T>>;
template<class T>auto  vcc   (i32 _1=0,i32 _2=0,const T&init=T()){ return vvc<T>(_1,vc<T>(_2,init)); }
template<class T>auto  vccc  (i32 _1=0,i32 _2=0,i32 _3=0,const T&init=T()){ return vvvc<T>(_1,vcc(_2,_3,init)); }
template<class T>auto  vcccc (i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,const T&init=T()){ return vvvvc<T>(_1,vccc(_2,_3,_4,init)); }
template<class T>auto  vccccc(i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,i32 _5=0,const T&init=T()){ return vvvvvc<T>(_1,vcccc(_2,_3,_4,_5,init)); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;
i64 const inf=0x3f3f3f3f3f3f3f3f;

int32_t main(){
    i32 T; std::cin>>T;
    while(T--){
        i32 n,k; std::cin>>n>>k;
        vc<i64>A(n+1);
        vvc<i32>G(n+1);
        for(i32 i=1;i<=n;++i){
            std::cin>>A[i];
            if(A[i]>=0){
                if(i>=k) G[i].pb(i+1);
                if(i<=k) G[i].pb(i-1);
            }
        }
        std::map<i64,i32>mp1{{0,k}};
        std::map<i64,i32>mp2{{0,k}};
        vc<i64>S(n+1);
        for(i64 i=k-1,sum=0;i>=1;--i){
            sum+=A[i];
            if(!mp1.count(sum)){
                mp1[sum]=i;
            }
            S[i]=sum+A[k];
        }
        for(i64 i=k+1,sum=0;i<=n;++i){
            sum+=A[i];
            if(!mp2.count(sum)){
                mp2[sum]=i;
            }
            S[i]=sum+A[k];
        }
        for(i32 i=k;i<=n;++i){
            if(S[i]<0){
                i64 cur=S[i];
                if(mp1.lower_bound(-cur)!=mp1.end()){
                    auto p=mp1.lower_bound(-cur)->second;
                    G[p].pb(i);
                    du(p,i);
                }
            }
        }
        for(i32 i=k;i>=1;--i){
            if(S[i]<0){
                i64 cur=S[i];
                if(mp1.lower_bound(-cur)!=mp1.end()){
                    auto p=mp1.lower_bound(-cur)->second;
                    G[p].pb(i);
                    du(p,i);
                }
            }
        }
        std::queue<i32>q;
        vc<char>vis(n+2);
        q.push(k);
        vis[k]=true;
        bool ok=false;
        while(!q.empty()){
            i32 u=q.front(); q.pop();
            if(u==0||u==n+1){
                ok=true;
            }
            for(auto v:G[u]){
                if(vis[v]) continue;
                vis[v]=true;
                q.push(v);
            }
        }
        std::cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}
