#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,m; std::cin>>n>>m;
        std::string s1,s2; std::cin>>s1>>s2;
        if(n<m){
            std::cout<<"NO"<<'\n';
        }if(n==m){
            std::cout<<(s1==s2?"YES":"NO")<<'\n';
        }else{
            bool ok=true;
            if(m>=2){
                ok=ok&&(s1.substr(n-m+1)==s2.substr(1));
            }
            bool yes=false;
            for(int i=0;i<=n-m;++i){
                if(s1[i]==s2[0]){
                    yes=true;
                }
            }
            std::cout<<(ok&&yes?"YES":"NO")<<'\n';
        }
    }
    return 0;
}