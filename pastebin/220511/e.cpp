#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int n,a,r,m; std::cin>>n>>a>>r>>m;
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    auto fun=[&](ll mid){
        ll x=0,y=0;
        for(ll i=1;i<=n;++i){
            if(A[i]<mid) x+=mid-A[i];
            if(A[i]>mid) y+=A[i]-mid;
        }
        ll tot=0;
        ll min=std::min(x,y);
        tot+=(ll)min*std::min(a+r,m);
        tot+=(ll)a*(x-min);
        tot+=(ll)r*(y-min);
        return tot;
    };
    ll L=-1,R=1000000000;
    while(L<R){
        ll lm=(L*2+R)/3;
        ll rm=(L+R*2)/3;
        if(lm==rm) lm=L,rm=R;
        if(fun(lm)>fun(rm)) L=lm+1;
        else R=rm-1;
    }
    std::cout<<fun(L)<<'\n';
    return 0;
}