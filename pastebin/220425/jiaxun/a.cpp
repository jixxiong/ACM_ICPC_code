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
    std::string s;
    std::cin>>s;
    int n; std::cin>>n;
    std::vector<std::string>A(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i];
    }
    std::sort(all(A));
    auto p=std::lower_bound(all(A),s);
    if(p==A.end()||s!=(*p).substr(0,std::min((*p).length(),s.length()))) std::cout<<s<<'\n';
    else std::cout<<*p<<'\n';
    return 0;
}