#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
    #define de(...) 4933
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_de(args);}
#endif

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
        ll n; int k,q; std::cin>>n>>k>>q;
        ll on=n;
        std::string s; std::cin>>s; s=' '+s;
        std::map<ll,ll,std::greater<ll>>id;
        id[1]=1;
        while(k--){
            ll l,r; std::cin>>l>>r;
            id[n+1]=l;
            n+=r-l+1;
        }
        while(q--){
            ll x; std::cin>>x;
            while(x>on){
                auto pt=id.lower_bound(x);
                x=pt->second+x-pt->first;
            }
            de(x);
            std::cout<<s[x]<<'\n';
        }
    }
    return 0;
}