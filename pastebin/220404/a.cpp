#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

const int p=10007;

void add(int& x,int y){
    x+=y;
    if(x>p) x-=p;
}

int main(){
    int x=10001,y=299;
    add(x,y);
    std::cout<<x<<std::endl;
    return 0;
}