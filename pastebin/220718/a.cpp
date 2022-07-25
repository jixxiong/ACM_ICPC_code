#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

using namespace std::string_literals;
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int32_t main(){
    std::string s; std::cin>>s;
    int n=s.length();
    bool ok=false;
    for(int i=0;i<n-1;++i){
        if(s[i]!='9'){
            ok=true;
            break;
        }
    }
    for(int i=1;i<n;++i){
        std::cout<<'9'
    }
    if(ok){
        return 0;       
    }else{
        std::cout<<s.back();
    }
    return 0;
}