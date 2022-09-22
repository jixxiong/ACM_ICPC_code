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
template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;
template<typename T>using vvvvvc=std::vector<vvvvc<T>>;
template<typename T>vvc<T> vcc(i32 s1=0,i32 s2=0,const T&init=T()){ return vvc<T>(s1,vc<T>(s2,init)); }
template<typename T>vvvc<T> vccc(i32 s1=0,i32 s2=0,i32 s3=0,const T&init=T()){ return vvvc<T>(s1,vcc(s2,s3,init)); }
template<typename T>vvvvc<T> vcccc(i32 s1=0,i32 s2=0,i32 s3=0,i32 s4=0,const T&init=T()){ return vvvvc<T>(s1,vccc(s2,s3,s4,init)); }
template<typename T>vvvvvc<T> vccccc(i32 s1=0,i32 s2=0,i32 s3=0,i32 s4=0,i32 s5=0,const T&init=T()){ return vvvvvc<T>(s1,vcccc(s2,s3,s4,s5,init)); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

void add(std::deque<i32>& q1,std::deque<i32>const& q2){
    if(q1.size()<q2.size()){
        q1.resize(q2.size());
    }
    for(i32 i=0;i<(i32)q2.size();++i){
        q1[i]+=q2[i];
    }
}

int32_t main(){
    i32 n,k; std::cin>>n>>k;
    auto G=vcc<i32>(n+1);
    for(i32 i=1;i<n;++i){
        i32 u,v; std::cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    vc<std::deque<i32>>cnt(n+1);
    std::function<i64(i32,i32)>dfs=[&](i32 u,i32 f)->i64{
        vc<std::deque<i32>>A;
        i64 res=0;
        for(auto v:G[u]){
            if(v==f) continue;
            res += dfs(v,u);
            A.pb(cnt[v]);
            add(cnt[u], cnt[v]);
        }
        i64 sum=0;
        i64 cur=0;
        for(i32 i=0;i<=k-2;++i){
            for(i32 j=0;j<(i32)A.size();++j){
                i32 x1 = (i32)cnt[u].size() >= i + 1 ? cnt[u][i] : 0;
                i32 x2 = (i32)A[j].size() >= i + 1 ? A[j][i] : 0;
                i32 x3 = (i32)A[j].size() >= (k - 2 - i + 1) ? A[j][k - 2 - i] : 0;
                sum += (i64)(x1 - x2) * x3;
            }
        }
        cnt[u].push_front(1);
        if((i32)cnt[u].size() >= k + 1) cur = cnt[u][k],cnt[u].resize(k + 1);
        return res + cur + sum / 2;
    };
    std::cout<<dfs(1,1)<<'\n';
    return 0;
}
