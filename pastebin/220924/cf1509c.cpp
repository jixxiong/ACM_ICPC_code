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
template<typename T>T inf(){ return std::numeric_limits<T>::max(); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;

int32_t main(){
    i32 n; std::cin>>n;
    vc<i32>A(n+1);
    for(i32 i=1;i<=n;++i){
        std::cin>>A[i];
    }
    std::sort(1+all(A));
    auto dp=vcc<i64>(n+1,n+1,inf<i64>());
    auto Max=vcc<i64>(n+1,n+1);
    auto Min=vcc<i64>(n+1,n+1);
    for(i32 l=1;l<=n;++l){
        for(i32 r=l;r<=n;++r){
            if(l==r){
                Max[l][r]=A[l];
                Min[l][r]=A[l];
            }else{
                Max[l][r]=std::max(Max[l][r-1],(i64)A[r]);
                Min[l][r]=std::min(Min[l][r-1],(i64)A[r]);
            }
        }
    }
    for(i32 len=1;len<=n;++len){
        for(i32 l=1;l+len-1<=n;++l){
            i32 r=l+len-1;
            i64 max=Max[l][r],min=Min[l][r];
            if(l==r){
                dp[l][r]=0;
            }else{
                dp[l][r]=std::min(dp[l+1][r],dp[l][r-1])+max-min;
            }
        }
    }
    std::cout<<dp[1][n]<<'\n';
    return 0;
}
