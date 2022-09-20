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
    int n; std::cin>>n;
    std::vector<int>A(2*n+1);
    for(int i=1;i<2*n;i+=2){
        std::cin>>A[i];
    }
    int ret=0;
    for(int i=0;i<=2*n;++i){
        int j=1;
        while(i-j>=0&&i+j<=2*n&&A[i-j]==A[i+j])j++;
        ret=std::max(ret,j-1);
    }
    std::cout<<ret<<'\n';
    return 0;
}