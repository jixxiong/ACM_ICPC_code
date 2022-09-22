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

int32_t main(){
    i32 T; std::cin>>T;
    while(T--){
        i32 n; std::cin>>n;
        auto A=vc<i32>(n+1);
        i32 pos = -1;
        for(i32 i=1;i<=n;++i){
            std::cin>>A[i];
            if(i>1&&A[i]!=A[i-1]) pos=i;
        }
        if(pos==-1){
            std::cout<<"1\n";
            for(i32 i=1;i<=n;++i){
                std::cout<<1<<" \n"[i==n];
            }
            continue;
        }
        auto f=vccc<i32>(2,3,n+1);
        using node=std::tuple<i32,i32,i32>;
        auto p=vccc<node>(2,3,n+1,node(0,0,0));
        f[0][0][1]=1;
        vvc<i32> const other={{1,2},{0,2},{0,1}};
        for(i32 i=2;i<=n;++i){
            i32 bg=0;
            if(i==n&&A[n]!=A[1]){
                bg=1;
            }
            for(i32 flg=bg;flg<2;++flg){
                i32& this_dp=f[0][flg][i];
                node& this_pre=p[0][flg][i];
                if(A[i]==A[i-1]){
                    for(i32 x=0;x<2;++x){
                        if(f[0][x][i-1]){
                            this_dp=1;
                            this_pre=node(0,x,i-1);
                        }
                    }
                }else{
                    if(f[0][flg^1][i-1]){
                        this_dp=1;
                        this_pre=node(0,flg^1,i-1);
                    }
                }
            }
            for(i32 flg=bg;flg<3;++flg){
                i32& this_dp=f[1][flg][i];
                node& this_pre=p[1][flg][i];
                if(A[i]==A[i-1]){
                    for(i32 x=0;x<3;++x){
                        if(f[1][x][i-1]){
                            this_dp=1;
                            this_pre=node(1,x,i-1);
                        }
                    }
                }else{
                    for(auto x:other[flg]){
                        if(f[1][x][i-1]){
                            this_dp=1;
                            this_pre=node(1,x,i-1);
                        }
                    }
                }
            }
            i32& this_dp=f[1][2][i];
            node& this_pre=p[1][2][i];
            for(i32 x=0;x<2;++x){
                if(f[0][x][i-1]){
                    this_dp=1;
                    this_pre=node(0,x,i-1);
                }
            }
        }
        vc<i32>ans(n+1);
        for(i32 i=0;i<2;++i){
            for(i32 j=0;j<3;++j){
                if(f[i][j][n]){
                    i32 ci=i,cj=j,cn=n;
                    while(cn){
                        ans[cn]=cj + 1;
                        std::tie(ci,cj,cn) = p[ci][cj][cn];
                    }
                    goto EXIT;
                }
            }
        }
        EXIT:
        if(f[0][0][n]||f[0][1][n]){
            std::cout<<"2\n";
        }else{
            std::cout<<"3\n";
        }
        for(i32 i=1;i<=n;++i){
            std::cout<<ans[i]<<" \n"[i==n];
        }
    }
    return 0;
}
