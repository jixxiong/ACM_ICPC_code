#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;
using i32=int32_t;
using i64=int64_t;
using i128=__int128;

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

int32_t main(){
    i32 T; std::cin>>T;
    while(T--){
        std::string s; std::cin>>s;
        if((i32)s.length()==1){
            std::cout<<"1 2\n";
            continue;
        }
        if((i32)s.length()==2){
            if(s[0]==s[1]){
                std::cout<<"2 8\n";
            }else{
                std::cout<<"2 6\n";
            }
            continue;
        }
        bool same=true;
        for(i32 i=1;i<(i32)s.length();++i){
            if(s[i]!=s[i-1]) same=false;
        }
        if(same){
            std::cout<<(same?"2 4\n":"2 2\n");
        }
    }
    return 0;
}