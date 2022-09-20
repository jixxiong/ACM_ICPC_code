#pragma once

#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

using db=long double;
db const eps=1e-9;
db const PI=std::acos((db)-1.0);

int fcmp(ll x,ll y=0){
    if(x==y) return 0;
    return x<y?-1:1;
}

int fcmp(db x,db y=0){
    if(fabs(x-y)<eps) return 0;
    return x<y?-1:1;
}