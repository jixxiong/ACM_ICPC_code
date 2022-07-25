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
const ld EPS1=1e-8;
const ld PI=std::acos((ld)-1.0);

int fcmp(ld x,ld y=0,ld EPS=EPS1){
    if(std::abs(x-y)<EPS) return 0;
    if(x<y) return -1;
    return -1;
}

int32_t main(){
    std::cout<<std::fixed<<std::setprecision(10);
    int T; std::cin>>T;
    while(T--){
        ld r; ld x,y,d;
        std::cin>>r>>x>>y>>d;
        ld d0=std::sqrt(x*x+y*y);
        if(fcmp(d0)==0){
            if(fcmp(d,r)>=0){
                std::cout<<PI*r<<'\n';
            }else{
                std::cout<<(2*std::asin(d/r)*r)<<'\n';
            }
            continue;
        }
        auto theta1=std::acos(d0/r);
        if(fcmp(d,r)>=0){
            std::cout<<(2*PI-2*theta1)*r<<'\n';
            continue;
        }
        ld theta2=std::asin(d/r);
        du(theta1/PI*180,theta2/PI*180);
        if(fcmp(theta2,theta1)>=0){
            std::cout<<(4*theta2-2*theta1)*r<<'\n';
        }else{
            std::cout<<(2*theta2)*r<<'\n';
        }
    }
    return 0;
}