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
        int k; std::cin>>k;
        std::vector<int>A(2*n);
        for(int i=0;i<2*n;++i){
            std::cin>>A[i];
        }
        std::sort(all(A));
        bool fail=false;
        for(int i=0;i<n;++i){
            if(A[i+n]-A[i]<k){
                fail=true;
            }
        }
        std::cout<<(fail?"NO":"YES")<<'\n';
    }
    return 0;
}