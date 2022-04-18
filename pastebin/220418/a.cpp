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
    std::array<int,10>A{};
    for(int i=0;i<9;++i){
        char x;
        std::cin>>x;
        A[x-'0']++;
    }
    for(int i=0;i<10;++i){
        if(!A[i]){
            std::cout<<(char)(i+'0')<<std::endl;
        }
    }
    return 0;
}