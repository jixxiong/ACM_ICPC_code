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
    int h,w,r,c;
    std::cin>>h>>w>>r>>c;
    std::vector<std::pair<int,int>>const mv{{0,1},{0,-1},{1,0},{-1,0}};
    int cnt=0;
    auto in_it=[&](int x,int y){
        return x>=1&&x<=h&&y>=1&&y<=w;
    };
    for(auto [dx,dy]:mv){
        if(in_it(r+dx,c+dy)) cnt++;
    }
    std::cout<<cnt<<'\n';
    return 0;
}