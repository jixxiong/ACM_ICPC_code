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
    const int N=40000;
    const int mod=1000000007;
    std::vector<int>num;
    for(int i=1;i<=N;++i){
        auto is_pali=[&](int x){
            int t=0,y=x;
            while(x) t=t*10+x%10,x/=10;
            return t==y;
        };
        if(is_pali(i))num.pb(i);
    }
    for(auto x:num) pr(x);
    // std::vector<std::vector<int>>f(N+1,std::vector<int>(num.size()));
    // for(int i=0;i<(int)num.size();++i) f[0][i]=1;
    // for(int i=1;i<=N;++i){
    //     for(int j=1;j<(int)num.size();++j){
    //         if(i>=num[j])
    //         f[i][j]=(f[i][j-1]+f[i-num[j]][j-1])%mod;
    //     }
    // }
    // std::cout<<f[12][num.size()-1];
    // pr(num.size());
    // std::vector<std::vector<int>>f(N+1,std::vector<int>(num.size()));
    // for(int i=0;i<(int)num.size();++i) f[num[i]][i]=1;
    // for(int i=1;i<=N;++i){
    //     for(int j=0;j<(int)num.size();++j){
    //         for(int k=j;k<(int)num.size();++k){
    //             for(int t=i+num[k];t<=N;t+=num[k]){
    //                 f[t][k]+=f[i][j];
    //                 f[t][k]%=mod;
    //                 // pr(i,j,k,t);
    //             }
    //         }
    //     }
    // }
    // int q=12;
    // std::cout<<std::accumulate(f[q].begin(),f[q].end(),0)<<'\n';
    return 0;
}