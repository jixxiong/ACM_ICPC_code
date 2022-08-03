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

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int32_t main(){
    int n,r,k; std::cin>>n>>r>>k;
    vc<int>A(n+1);
    auto check=[&](ll h,vc<int> tr){
        ll sum=0;
        int j=1;
        for(int i=1;i<=n;++i){
            while(j<=n&&j<=i+r){
                tr[j]+=tr[j-1];
                j++;
            }
            ll tot=tr[std::min(n,i+r)]-tr[std::max(i-r-1,0ll)];
            if(tot<=h){
                tr[std::min(n,i+r)]+=h-tot;
                sum+=h-tot;
                if(sum>k) return false;
            }
        }
        return sum<=(ll)k;
    };
    ll l=std::numeric_limits<long long>::max(),rr=0;
    for(int i=1;i<=n;++i){
        std::cin>>A[i];
        l=std::min((long long)l,A[i]);
        rr+=A[i];
    }
    rr+=k;
    l--,rr++;
    while(l+1<rr){
        ll mid=(l+rr)>>1;
        if(check(mid,A)) l=mid;
        else rr=mid;
    }
    std::cout<<(int)l<<'\n';
    return 0;
}