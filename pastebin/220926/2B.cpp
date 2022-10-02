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
template<class T>T INF(){ return std::numeric_limits<T>::max(); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;

int32_t main(){
    i32 n; std::cin>>n;
    auto A=vcc<i32>(n+1,n+1);
    auto Two=vcc<i32>(n+1,n+1);
    auto Five=vcc<i32>(n+1,n+1);
    auto f=vcc<i32>(n+1,n+1);
    auto g=vcc<i32>(n+1,n+1);
    auto pf=vcc<char>(n+1,n+1);
    auto pg=vcc<char>(n+1,n+1);
    std::pair<i32,i32>pos{-1,-1};
    for(i32 i=1;i<=n;++i){
        for(i32 j=1;j<=n;++j){
            std::cin>>A[i][j];
            if(A[i][j]==0){
                Two[i][j]++,Five[i][j]++;
                pos=std::pair<i32,i32>{i,j};
            }else{
                while(A[i][j]%2==0){
                    Two[i][j]++;
                    A[i][j]/=2;
                }
                while(A[i][j]%5==0){
                    Five[i][j]++;
                    A[i][j]/=5;
                }
            }
        }
    }
    for(i32 i=1;i<=n;++i){
        for(i32 j=1;j<=n;++j){
            if(i==1&&j==1){
                f[i][j]=Two[i][j];
                g[i][j]=Five[i][j];
            }else if(i==1&&j!=1){
                f[i][j]=f[i][j-1]+Two[i][j];
                pf[i][j]='L';
                g[i][j]=g[i][j-1]+Five[i][j];
                pg[i][j]='L';
            }else if(j==1&&i!=1){
                f[i][j]=f[i-1][j]+Two[i][j];
                pf[i][j]='U';
                g[i][j]=g[i-1][j]+Five[i][j];
                pg[i][j]='U';
            }else{
                if(f[i-1][j]<f[i][j-1]){
                    f[i][j]=f[i-1][j]+Two[i][j];
                    pf[i][j]='U';
                }else{
                    f[i][j]=f[i][j-1]+Two[i][j];
                    pf[i][j]='L';
                }
                if(g[i-1][j]<g[i][j-1]){
                    g[i][j]=g[i-1][j]+Five[i][j];
                    pg[i][j]='U';
                }else{
                    g[i][j]=g[i][j-1]+Five[i][j];
                    pg[i][j]='L';
                }
            }
        }
    }
    std::function<void(i32,i32,vvc<char>const&)>trace=[&](i32 x,i32 y,vvc<char>const& pt)->void{
        if(x==1&&y==1) return ;
        if(pt[x][y]=='U'){
            trace(x-1,y,pt);
            std::cout<<'D';
        }else{
            trace(x,y-1,pt);
            std::cout<<'R';
        }
    };
    auto go_to_zero_then_to_end=[](i32 bx,i32 by,i32 zx,i32 zy,i32 ex,i32 ey)->void{
        while(bx<zx){
            std::cout<<'D';
            bx++;
        }
        while(by<zy){
            std::cout<<'R';
            by++;
        }
        while(zx<ex){
            std::cout<<'D';
            zx++;
        }
        while(zy<ey){
            std::cout<<'R';
            zy++;
        }
    };
    if(std::min(f[n][n],g[n][n])==0){
        std::cout<<"0\n";
        if(f[n][n]<g[n][n])
            trace(n,n,pf);
        else
            trace(n,n,pg);
    }else{
        if(pos==std::pair<i32,i32>{-1,-1}){
            std::cout<<std::min(f[n][n],g[n][n])<<'\n';
            if(f[n][n]<g[n][n])
                trace(n,n,pf);
            else
                trace(n,n,pg);
        }else{
            std::cout<<"1\n";
            go_to_zero_then_to_end(1,1,pos.first,pos.second,n,n);
        }
    }
    std::cout<<'\n';
    return 0;
}
