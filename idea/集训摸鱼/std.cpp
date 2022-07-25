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
    int n,m; std::cin>>n>>m;
    std::vector<int>A(m+2);
    for(int i=1;i<=n;++i){
        int k; std::cin>>k;
        std::vector<std::pair<int,int>>a;
        for(int j=1;j<=k;++j){
            int l,r; std::cin>>l>>r;
            A[l]++; A[r+1]--;
            a.push_back(std::pair<int,int>{l,r});
        }
        std::sort(all(a));
        for(int i=0;i<k-1;++i){
            assert(a[i].second<a[i+1].first);
        }
    }
    bool ok=false;
    for(int i=1;i<=m;++i){
        A[i]+=A[i-1];
        if(A[i]==n){
            ok=true;
        }
    }
    std::cout<<(ok?"YES":"NO")<<'\n';
    return 0;
}