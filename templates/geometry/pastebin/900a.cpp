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
    int ca=0,cb=0;
    for(int i=0;i<n;++i){
        int x,y; std::cin>>x>>y;
        if(x<0)ca++;
        else cb++;
    }
    std::cout<<(ca<=1||cb<=1?"Yes":"No")<<'\n';
    return 0;
}