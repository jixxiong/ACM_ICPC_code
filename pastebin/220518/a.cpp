#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
#define int long long

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int a,b,n,m,h; std::cin>>a>>b>>n>>m>>h;
        int l=0,r=m;
        while(l+1<r){
            int mid=(l+r)>>1;
            int t1=n/b*(b-a);
            int t2=(n+mid)/b*(h-b);
            if(t1+t2+mid>=m) r=mid;
            else l=mid;
        }
        std::cout<<r+n<<'\n';
    }
    return 0;
}
