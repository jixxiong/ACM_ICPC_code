#include <bits/stdc++.h>

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

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int n;

auto check(int x,int y,int j){
    int lf=j*x-y;
    int rt=(n-(lf%n+n)%n)%n;
    return rt<j;
}
// 573587
int32_t main(){
    std::cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i){
        bool ok=false;
        for(int j=10,cnt=1;j<=100000000;j*=10,cnt++){
            if(check(i-1,i,j)){
                ans+=cnt;
                ok=true;
                du(i-1,i,cnt);
                break;
            }
        }
        assert(ok);
    }
    std::cout<<ans<<'\n';
    return 0;
}