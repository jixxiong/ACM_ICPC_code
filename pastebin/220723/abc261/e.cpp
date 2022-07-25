#include <bits/stdc++.h>

using namespace std::string_literals;
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T,T init=T{}> auto Vec(int s){ return std::vector(s,init); }
template<typename T,T init=T{},typename...L> auto Vec(int s,L...l){ return std::vector(s,Vec<T,init>(l...)); }

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int32_t main(){
    int n,c; std::cin>>n>>c;
    auto T=Vec<int>(n+1);
    auto A=Vec<int>(n+1);
    auto B=Vec<int>(2,32,n+1);
    for(int i=0;i<30;++i){
        B[1][i][0]=1;
    }
    for(int i=1;i<=n;++i){
        std::cin>>T[i]>>A[i];
        for(int ch=30;ch>=0;--ch){
            if(T[i]==1){
                for(int j=0;j<2;++j){
                    B[j][ch][i]=B[j][ch][i-1]&((A[i]>>ch)&1);
                }
            }else if(T[i]==2){
                for(int j=0;j<2;++j){
                    B[j][ch][i]=B[j][ch][i-1]|((A[i]>>ch)&1);
                }
            }else{
                for(int j=0;j<2;++j){
                    B[j][ch][i]=B[j][ch][i-1]^((A[i]>>ch)&1);
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        int d=0;
        for(int ch=30;ch>=0;--ch){
            int x=(c>>ch)&1;
            d|=B[x][ch][i]<<ch;
        }
        c=d;
        std::cout<<c<<'\n'; 
    }
    return 0;
}