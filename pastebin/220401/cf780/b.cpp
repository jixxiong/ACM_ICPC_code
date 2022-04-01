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
    int r; std::cin>>r;
    if(r<1200)std::cout<<1200;
    else if(r<1400)std::cout<<1400;
    else if(r<1600)std::cout<<1600;
    else if(r<1900)std::cout<<1900;
    else if(r<2100)std::cout<<2100;
    else if(r<2300)std::cout<<2300;
    else if(r<2400)std::cout<<2400;
    else if(r<2600)std::cout<<2600;
    else std::cout<<3000;
    return 0; 
}