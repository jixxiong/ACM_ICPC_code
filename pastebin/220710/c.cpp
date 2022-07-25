#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define de(...) void()
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){std::cerr<<"[DEBUG: LINE "<<__LINE__<<"]: ";_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int32_t main(){
    std::string s,t; 
    std::cin>>s>>t;
    std::string a,b;
    int n=(int)s.length();
    for(int l=0,r;l<n;l=r){
        r=l+1;
        while(r<n&&s[r]==s[l]) r++;
        a+=s[l]; 
        if(r-l>1) a+=s[l];
    }
    n = t.length();
    for(int l=0,r;l<n;l=r){
        r=l+1;
        while(r<n&&t[r]==t[l]) r++;
        b+=t[l]; 
        if(r-l>1) b+=t[l];
    }
    de(a,b);
    std::cout<<(a==b?"Yes":"No")<<'\n';
    return 0;
}