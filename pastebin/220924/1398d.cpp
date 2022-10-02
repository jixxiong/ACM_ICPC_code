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
    vc<i32>S(3); std::cin>>S[0]>>S[1]>>S[2];
    auto A=vcc<i32>(3);
    for(i32 i=0;i<3;++i){
        A[i].resize(S[i]+1);
        for(i32 j=1;j<=S[i];++j){
            std::cin>>A[i][j];
        }
    }
    for(i32 i=0;i<3;++i){
        std::sort(A[i].begin()+1,A[i].end(),std::greater<i32>());
    }
    auto dp=vccc<i64>(S[0]+1,S[1]+1,S[2]+1);
    i64 ret=0;
    for(i32 i=0;i<=S[0];++i){
        for(i32 j=0;j<=S[1];++j){
            for(i32 k=0;k<=S[2];++k){
                if(i&&j){
                    dp[i][j][k]=std::max(dp[i][j][k],dp[i-1][j-1][k]+A[0][i]*A[1][j]);
                }
                if(i&&k){
                    dp[i][j][k]=std::max(dp[i][j][k],dp[i-1][j][k-1]+A[0][i]*A[2][k]);
                }
                if(j&&k){
                    dp[i][j][k]=std::max(dp[i][j][k],dp[i][j-1][k-1]+A[1][j]*A[2][k]);
                }
                ret=std::max(ret,dp[i][j][k]);
            }
        }
    }
    std::cout<<ret<<'\n';
    return 0;
}
