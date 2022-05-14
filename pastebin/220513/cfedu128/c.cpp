#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int T; std::cin>>T;
    while(T--){
        std::string s; std::cin>>s;
        int n=s.length();
        s=' '+s;
        std::vector<int>A(n+1),B(n+1);
        for(int i=1;i<=n;++i){
            A[i]=A[i-1]+(s[i]=='1');
            B[i]=i-A[i];
        }
        int ret=0x3f3f3f3f;
        for(int i=1;i<=n;++i){
            int l=i-1,r=n+1;
            while(l+1<r){
                int mid=(l+r)>>1;
                if(B[mid]-B[i-1]<=A[i-1]+A[n]-A[mid])
                    l=mid;
                else
                    r=mid;
            }
            ret=std::min(ret,std::max(B[l]-B[i-1],A[i-1]+A[n]-A[l]));
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}