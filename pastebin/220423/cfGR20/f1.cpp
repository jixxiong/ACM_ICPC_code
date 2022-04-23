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
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n);
        std::vector<std::vector<int>>cnt(n+1);
        for(int i=0;i<n;++i){
            std::cin>>A[i];
            cnt[A[i]].push_back(i);
        }
        std::vector<int>B(n+1);
        std::iota(all(B),0);
        std::sort(all(B),[&](int x,int y){
            return cnt[x].size()<cnt[y].size();
        });
        int b=[&](){
            int i=0; for(;i<=n;++i)if(!cnt[B[i]].empty()) break;
            return i;
        }();
        std::vector<int>rest(all(cnt[B[b]]));
        std::vector<int>C(n);
        for(int i=b;i<n;++i){
            int mx=(int)std::min(cnt[B[i]].size(),cnt[B[i+1]].size());
            for(int j=0;j<mx;++j){
                C[cnt[B[i+1]][j]]=A[cnt[B[i]][j]];
            }
            for(int j=mx;j<(int)cnt[B[i+1]].size();++j){
                rest.push_back(cnt[B[i+1]][j]);
            }
        }
        for(int i=0;i<(int)rest.size();++i){
            C[rest[i]]=A[cnt[B[n]][i]];
        }
        for(int i=0;i<n;++i) std::cout<<C[i]<<' ';
        std::cout<<'\n';
    }
    return 0;
}