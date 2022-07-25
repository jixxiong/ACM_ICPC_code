#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define er(args...) void()
#else
    #define vwn(x) #x"=",x,"\n"
    void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
    #define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;

int32_t main(){
    int n; std::cin>>n;
    std::string s; std::cin>>s;
    s=' '+s;
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    std::vector<int>B,C;
    for(int i=1;i<=n;++i){
        if(s[i]=='0') B.pb(A[i]);
        else C.pb(A[i]);
    }
    std::sort(all(B));
    std::sort(all(C));
    if((int)C.size()==0||(int)C.size()==n){
        std::cout<<n<<'\n';
        return 0;
    }
    int ret=C.size();
    for(int i=0,j=-1;i<(int)B.size();++i){
        while(j+1<(int)C.size()&&C[j+1]<=B[i])j++;
        ret=std::max(ret,i+((int)C.size()-j));
    }
    std::cout<<ret<<'\n';
    return 0;
}