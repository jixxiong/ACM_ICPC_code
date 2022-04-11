#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct my_hash{
    size_t operator()(size_t x)const{
        static const size_t random_shift=std::chrono::steady_clock::now().time_since_epoch().count();
        x+=random_shift;
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
};

ll qpow(ll x,ll y,ll m){
    if(y==0) return 1;
    ll ret=1;
    for(;y>0;y>>=1,x=x*x%m)
        if(y&1) ret=ret*x%m;
    return ret;
}

// given a,b,m, where gcd(a,m)=1, find the minium x s.t. a^x=b(mod m)
ll BSGS(ll a,ll b,ll m){
    a%=m,b%=m;
    if(b==1) return 0;
    static std::unordered_map<ll,ll,my_hash>hs;
    hs.clear();
    ll t=(ll)sqrt(m)+1;
    for(int i=0,cur=b;i<t;++i) hs[cur]=i,cur=cur*a%m;
    ll stp=qpow(a,t,m);
    for(ll A=1,cur=stp;A<=t;++A) {
        auto it=hs.find(cur);
        if(it!=hs.end()) return A*t-it->second;
        cur=cur*stp%m;
    }
    return -1;
}

int main(){
    const int p=998244353;
    int T; std::cin>>T;
    while(T--){
        ll n,x; std::cin>>n>>x;
        if(x==1)std::cout<<"0\n";
        else if(x==0)std::cout<<"1\n";
        else{
            ll res=BSGS(n-1,(x*n%p+1-n+p)%p,p);
            if(~res&&(res&1))res=-1;
            ll ret=BSGS(n-1,(x*n%p+n-1)%p,p);
            if(~ret&&!(ret&1))ret=-1;
            if(~res&&~ret) std::cout<<std::min(res,ret)<<'\n';
            else std::cout<<((~res)?res:ret)<<'\n';
        }
    }
    return 0;
}