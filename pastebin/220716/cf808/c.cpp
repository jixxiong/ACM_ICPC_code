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
        int n; std::cin>>n;
        int q; std::cin>>q;
        std::vector<int>A(n+1);
        for(int i=1;i<=n;++i){
            std::cin>>A[i];
        }
        auto is_right=[&](int x){
            int qq=q;
            for(int i=x;i<=n;++i){
                if(qq==0) return false;
                if(A[i]>qq) qq--;
            }
            return true;
        };
        int l=0,r=n+1;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(is_right(mid)) r=mid;
            else l=mid;
        }
        for(int i=1;i<r;++i){
            if(A[i]>q) std::cout<<0;
            else std::cout<<1;
        }
        for(int i=r;i<=n;++i){
            std::cout<<1;
        }
        std::cout<<'\n';
    }
    return 0;
}