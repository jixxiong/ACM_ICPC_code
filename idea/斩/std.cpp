#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

using namespace std::string_literals;
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int h,k,n,x,y; std::cin>>h>>k>>n>>x>>y;
        if(
            ((h>k)&&(h-n*y>k)) ||
            ((h<=k)&&(h+n*x<=k))
        ){
            std::cout<<(h>k?h-n*y:h+n*x)<<'\n';
        }else{
            int l=-1,r=n+1;
            while(l+1<r){
                int mid=(l+r)>>1;
                int nh=h+mid*x-(n-mid)*y;
                if(nh<=k+x) l=mid;
                else r=mid;
            }
            std::cout<<h+l*x-(n-l)*y<<'\n';
        }
    }
    return 0;
}