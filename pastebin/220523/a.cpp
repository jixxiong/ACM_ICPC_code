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
        int n; std::cin>>n;
        std::vector<int>A(n);
        for(int i=0;i<n;++i) std::cin>>A[i];
        int m; std::cin>>m;
        std::vector<int>B(m);
        for(int i=0;i<m;++i) std::cin>>B[i];
        std::sort(all(A));
        std::sort(all(B));
        if(A.back()==B.back()){
            std::cout<<"Alice\nBob\n";
        }else if(A.back()>B.back()){
            std::cout<<"Alice\nAlice\n";
        }else{
            std::cout<<"Bob\nBob\n";
        }
    }
    return 0;
}