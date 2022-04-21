#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n+2);
        std::vector<int>pre(n+1),suf(n+2);
        std::vector<int>fow(n+2,n+1);
        for(int i=1;i<=n;++i){
            std::cin>>A[i];
            pre[i]=pre[i-1]+A[i];
        }
        for(int i=n;i>=1;--i){
            suf[i]=suf[i+1]+A[i];
        }
        int ret=0;
        for(int i=1;i<=n;++i){
            int l=0,r=n+1;
            while(l+1<r){
                int mid=(l+r)>>1;
                if(suf[mid]<=pre[i]) r=mid;
                else l=mid;
            }
            if(suf[r]==pre[i]&&r>i) ret=std::max(ret,i+n-r+1);
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}