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
    int T; std::cin>>T;
    while(T--){
        ll x,y; std::cin>>x>>y;
        ll a,b,c; std::cin>>a>>b>>c;
        auto count=[](ll x){
            int ret=0;
            while(x) ret+=x&1,x>>=1;
            return ret;
        };
        auto fun=[&](ll t){
            ll ret=0x3f3f3f3f3f3f3f3f;
            for(int bit=0;bit<=63;++bit){
                ll fk=t>>bit;
                ll sum=fk*a;
                fk=(t&((1ll<<(bit))-1));
                sum+=bit*b;
                sum+=count(fk)*a;
                ret=std::min(ret,sum);
            }
            return ret;
        };
        if(x==0){
            std::cout<<fun(y)<<'\n';
            continue;
        }
        ll ret=0x3f3f3f3f3f3f3f3f;
        for(ll bit=0;bit<=63;++bit){
            ll sum=bit*c;
            if((x>>bit)==0){
                ret=std::min(ret,sum+fun(y));
                break;
            }
            ll lgx=std::__lg(x>>bit);
            ll lgy=std::__lg(y);
            if(lgx>lgy) continue;
            ll dif_bit=lgy-lgx;
            ll add=(y>>dif_bit);
            if(add>(x>>bit)) continue;
            sum+=(add-(x>>bit))*a;
            sum+=dif_bit*b;
            sum+=count(((1ll<<(lgy-dif_bit))-1)&y)*a;
            ret=std::min(sum,ret);
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}