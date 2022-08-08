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

auto query(i32 a,i32 b)->i32{
    std::cout<<"? "<<a<<' '<<b<<std::endl;
    i32 x; std::cin>>x;
    return x;
}

auto pick_one_from_two(i32 a,i32 b)->i32{
    i32 x=query(a,b);
    assert(x!=0);
    return x==1?a:b;
}

auto pick_one_from_four(i32 a,i32 b,i32 c,i32 d)->i32{
    i32 x=query(a,c);
    if(x==0) return query(b,d)==1?b:d;
    if(x==2) std::swap(a,c),std::swap(b,d);
    return query(a,d)==1?a:d;
}

int32_t main(){
    i32 T; std::cin>>T;
    while(T--){
        i32 n; std::cin>>n;
        vc<i32>ask(1<<n);
        std::iota(all(ask),1);
        while(ask.size()>=4){
            vc<i32>next; next.reserve(ask.size()/4);
            for(i32 i=3;i<(i32)ask.size();i+=4){
                next.pb(pick_one_from_four(ask[i-3],ask[i-2],ask[i-1],ask[i]));
            }
            ask=next;
        }
        i32 ans=((i32)ask.size()==2?pick_one_from_two(ask[0],ask[1]):ask[0]);
        std::cout<<"! "<<ans<<std::endl;
    }
    return 0;
}