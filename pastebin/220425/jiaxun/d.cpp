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
    int n; std::cin>>n;
    std::vector<int>A(n),B(n);
    std::vector<std::vector<int>>pool(n);
    for(int i=0;i<n;++i) std::cin>>A[i];
    for(int i=0;i<n;++i) std::cin>>B[i];
    std::vector<int>fuk=A;
    std::sort(all(fuk));
    fuk.erase(std::unique(all(fuk)),fuk.end());
    for(int i=0;i<n;++i) A[i]=std::lower_bound(all(fuk),A[i])-fuk.begin();
    for(int i=0;i<n;++i) B[i]=std::lower_bound(all(fuk),B[i])-fuk.begin();
    for(int i=0;i<n;++i) pool[A[i]].push_back(i);
    for(int i=0;i<n;++i) {
        auto tmp=B[i];
        B[i]=pool[B[i]].back();
        pool[tmp].pop_back();
    }
    std::vector<std::pair<int,int>>ans;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(B[j]==i){
                for(;j>i;--j) {
                    std::swap(B[j-1],B[j]);
                    ans.push_back(std::pair<int,int>(j,j+1));
                }
                break;
            }
        }
    }
    std::cout<<(int)ans.size()<<'\n';
    for(auto [x,y]:ans){
        std::cout<<x<<' '<<y<<'\n';
    }
    return 0;
}