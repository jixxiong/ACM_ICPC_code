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
    const int N=200000;
    std::vector<int>A(N+10);
    while(T--){
        int x1,y1,x2,y2;
        std::cin>>x1>>y1>>x2>>y2;
        x1<<=1;
        x2<<=1;
        A[x1]++;
        A[x2+1]--;
    }
    int c=0;
    for(int i=1;i<=N;++i){
        A[i]+=A[i-1];
    }
    for(int l=1,r;l<=N;l=r){
        while(l<=N&&A[l]==0) l++;
        if(l>N) break;
        r=l+1;
        while(r<=N&&A[r]!=0) r++;
        c+=(r-l)/2;
    }
    std::cout<<c<<'\n';
    return 0;
}