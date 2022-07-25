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
    int T; std::cin>>T;
    while(T--){
        int n,m,k; std::cin>>n>>m>>k;
        auto A=Vec<int>(k+1);
        int tot1=0,tot2=0;
        bool ji1=false,ji2=false;
        bool lag1=false,lag2=false;
        for(int i=1;i<=k;++i){
            std::cin>>A[i];
            int x=(A[i]/(std::min(n,m)));
            if(x>=2){
                tot1+=x;
                if(x&1) ji1=true;
                if(x>3&&!(x&1)) lag1=true;
            }
            int y=(A[i]/(std::max(n,m)));
            if(y>=2){
                tot2+=y;
                if(y&1) ji2=true;
                if(y>3&&!(y&1)) lag2=true;
            }
        }
        std::cout<<((tot1>=std::max(n,m)&&(!(std::max(n,m)&1)||((tot1>std::max(n,m)&&lag1)||ji1)))||(tot2>=std::min(n,m)&&(!(std::min(n,m)&1)||((tot2>std::min(n,m)&&lag2)||ji2)))?"Yes":"No")<<'\n';
    }
    return 0;
}