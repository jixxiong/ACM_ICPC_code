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

int32_t main(){
    std::cout<<std::fixed<<std::setprecision(10);
    int n; ld T; std::cin>>n>>T;
    vc<ld>A(n); vc<ld>c(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i];
    }
    for(int i=0;i<n;++i){
        std::cin>>c[i];
        c[i]-=T;
    }
    ld ans=0;
    vc<ld>a1,a2,c1,c2;
    ld t1=0,t2=0;
    for(int i=0;i<n;++i){
        if(fcmp(c[i])==0){
            ans+=A[i];
        }else if(fcmp(c[i])<0){
            a1.pb(A[i]);
            c1.pb(-c[i]);
            t1-=A[i]*c[i];
        }else{
            a2.pb(A[i]);
            c2.pb(c[i]);
            t2+=A[i]*c[i];
        }
    }
    if((a1.empty()||a2.empty())&&fcmp(ans)==0){
        std::cout<<0<<'\n';
        return 0;
    }
    if(fcmp(t1,t2)==0){
        ld sm=0;
        for(auto x:A){
            sm+=x;
        }
        std::cout<<sm<<'\n';
        return 0;
    }
    if(fcmp(t1,t2)>0){
        std::swap(a1,a2);
        std::swap(c1,c2);
        std::swap(t1,t2);
    }
    vc<int>id(a2.size());
    std::iota(all(id),0);
    std::sort(all(id),[&](int i,int j){
        return fcmp(c2[i],c2[j])<0;
    });
    for(auto a:a1) ans+=a;
    int sz=a2.size();
    ld sm=0;
    for(int i=0;i<sz;++i){
        if(fcmp(sm,t1)<=0){
            if(fcmp(sm+a2[id[i]]*c2[id[i]],t1)<=0){
                sm+=a2[id[i]]*c2[id[i]];
                ans+=a2[id[i]];
            }else{
                ans+=(t1-sm)/c2[id[i]];
                break;
            }
        }
    }
    std::cout<<ans<<'\n';
    return 0;
}

/*

3 100
100 100 100
98 102 101

*/