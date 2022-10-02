#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
#define ld long double
#define ll long long
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;
template<typename T>using vvvvvc=std::vector<vvvvc<T>>;
template<typename T>vvc<T> vcc(i32 s1=0,i32 s2=0,const T&init=T()){ return vvc<T>(s1,vc<T>(s2,init)); }
template<typename T>vvvc<T> vccc(i32 s1=0,i32 s2=0,i32 s3=0,const T&init=T()){ return vvvc<T>(s1,vcc(s2,s3,init)); }
template<typename T>vvvvc<T> vcccc(i32 s1=0,i32 s2=0,i32 s3=0,i32 s4=0,const T&init=T()){ return vvvvc<T>(s1,vccc(s2,s3,s4,init)); }
template<typename T>vvvvvc<T> vccccc(i32 s1=0,i32 s2=0,i32 s3=0,i32 s4=0,i32 s5=0,const T&init=T()){ return vvvvvc<T>(s1,vcccc(s2,s3,s4,s5,init)); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

int32_t main(){
    std::set<i32>st;
    for(i32 i=1;i<=5;++i){
        i32 x; std::cin>>x;
        st.insert(x);
    }
    std::cout<<(i32)st.size()<<'\n';
    return 0;
}
