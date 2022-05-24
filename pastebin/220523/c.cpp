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
        std::vector<int>A(n),B(n);
        for(int i=0;i<n;++i) std::cin>>A[i];
        for(int i=0;i<n;++i) std::cin>>B[i];
        std::vector<std::pair<int,int>>seq;
        for(int i=0;i<n;++i){
            int k=i;
            for(int j=i+1;j<n;++j){
                if(A[j]<A[k]) k=j;
            }
            if(k==i) continue;
            seq.pb(std::pair<int,int>(i,k));
            std::swap(A[i],A[k]);
            std::swap(B[i],B[k]);
        }
        for(int l=0,r;l<n;l=r){
            r=l+1;
            while(r<n&&A[r]==A[l]) r++;
            for(int i=l;i<r;++i){
                int k=i;
                for(int j=i+1;j<r;++j){
                    if(B[j]<B[k]) k=j;
                }
                if(k==i) continue;
                seq.pb(std::pair<int,int>(i,k));
                std::swap(B[i],B[k]);
            }
        }
        if(std::is_sorted(all(B))){
            std::cout<<seq.size()<<'\n';
            for(auto [x,y]:seq){
                std::cout<<x+1<<' '<<y+1<<'\n';
            }
        }else{
            std::cout<<"-1\n";
        }
    }
    return 0;
}