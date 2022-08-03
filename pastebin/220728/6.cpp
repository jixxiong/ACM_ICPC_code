#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=double;
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

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int fcmp(ld x,ld y=0,ld eps=EPS){
    if(std::abs(x-y)<eps) return 0;
    return x<y?-1:1;
}

int fcmp(ll x,ll y){
    if(x==y) return 0;
    return x<y?-1:1;
}

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n; 
        ll t1=0,t2=0;
        for(int i=0;i<n;++i){
            ll x; std::cin>>x; x*=20;
            ll xx=x;
            if(fcmp(x)>0&&fcmp(t1,2000)<0){
                ll tk=2000-t1;
                t1=std::min(t1+x,(ll)2000);
                x-=std::min(x,tk);
            }
            if(fcmp(x)>0&&fcmp(t1,2000)>=0&&fcmp(t1,4000)<0){
                ll tk=4000-t1;
                t1=std::min(t1+x/5*4,(ll)4000);
                x-=std::min(x,tk*5/4);
            }
            if(fcmp(x)>0&&fcmp(t1,4000)>=0){
                t1+=x/2;
            }
            x=xx;
            if(fcmp(t2,2000)<0){
                t2+=x;
            }else if(fcmp(t2,4000)<0){
                t2+=x*4/5;
            }else{
                t2+=x/2;
            }
        }
        std::cout<<std::fixed<<std::setprecision(3);
        std::cout<<t1/20.0<<' '<<t2/20.0<<'\n';
    }
    return 0;
}