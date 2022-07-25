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
        int n,l,r; std::cin>>n>>l>>r;
        std::vector<int>ans(n+1);
        bool fail=false;
        for(int i=n;i>=1;--i){
            for(int k=(l+i-1)/i*i;k<=r/i*i;k+=i){
                ans[i]=k;
                break;
            }
            if(ans[i]==0){
                fail=true;
                break;
            }
        }
        if(fail){
            std::cout<<"NO"<<'\n';
        }else{
            std::cout<<"YES"<<'\n';
            for(int i=1;i<=n;++i){
                std::cout<<ans[i]<<" \n"[i==n];
            }
        }
    }
    return 0;
}