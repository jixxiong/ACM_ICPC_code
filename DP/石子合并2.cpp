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
    int n; std::cin>>n;
    std::vector<int>A(n<<1);
    for(int i=0;i<n;++i) std::cin>>A[i],A[i+n]=A[i];
    n<<=1;
    std::vector<std::vector<int>>f(n,std::vector<int>(n,0x3f3f3f3f));
    for(int i=0;i<n;++i) f[i][i]=0;
    for(int l=2;l<=n;++l){
        for(int i=0;i+l-1<n;++i){
            int j=i+l-1;
            int sum=std::accumulate(A.begin()+i,A.begin()+j+1,0);
            for(int k=i;k<j;++k){
                f[i][j]=std::min(f[i][j],
                    f[i][k]+f[k+1][j]+sum);
            }
        }
    }
    n>>=1;
    int ret=f[0][n-1];
    for(int i=1;i<n;++i) ret=std::min(ret,f[i][i+n-1]);
    std::cout<<ret<<'\n';
    return 0;
}