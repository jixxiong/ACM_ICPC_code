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
    std::string s; std::cin>>s;
    std::vector<std::vector<int>>f(n+2,std::vector<int>(n+2));
    auto match=[](char c1,char c2){
        return (c1=='['&&c2==']')||(c1=='('&&c2==')');
    };
    for(int l=2;l<=n;++l){
        for(int i=0;i+l<=n;++i){
            int j=i+l-1;
            f[i][j]=std::max(f[i+1][j],f[i][j-1]);
            if(match(s[i],s[j]))f[i][j]=std::max(f[i][j],f[i+1][j-1]+2);
            for(int k=i;k<j;++k) f[i][j]=std::max(f[i][j],f[i][k]+f[k+1][j]);
        }
    }
    std::cout<<f[0][n-1]<<'\n';
    return 0;
}