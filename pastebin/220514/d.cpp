#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

std::mt19937 rng(114514);

int range(int l,int r){
    return rng()%(r-l+1)+l;
}

int main(){
    // int w; std::cin>>w;
    // int const N=1000000;
    // int const s1=1,s2=1000,s3=10000;
    std::vector<int>A;
    for(int i=0;i<35;++i) A.pb(i+1);
    for(int i=0;i<65;++i) A.pb(range(1,200));
    for(int i=0;i<200;++i) A.pb(range(1000,1000000/3+1));
    std::cout<<A.size()<<'\n';
    for(auto x:A) std::cout<<x<<' ';
    std::cout<<'\n';
    return 0;
}