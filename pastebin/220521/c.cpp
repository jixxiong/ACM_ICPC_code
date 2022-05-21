#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;

ll const INF=1e18;

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
            for(int bit=0;bit<63;++bit){
                ll fk=t>>bit;
                if(fk>INF/a) continue;
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
        if(y==0){
            std::cout<<(std::__lg(x)+1)*c<<'\n';
            continue;
        }
        ll ret=0x3f3f3f3f3f3f3f3f;
        for(ll bit=0;bit<63;++bit){
            ll sum=bit*c;
            if((x>>bit)==0){
                ret=std::min(ret,sum+fun(y));
                break;
            }
            ll yy=y,zz=0,bs=0,cnt=0;
            while(yy>=(x>>bit)){
                if((yy-(x>>bit))>INF/a){
                    zz|=(yy&1)<<bs;
                    if(yy&1) cnt++;
                    bs++;
                    yy>>=1;
                    continue;
                }
                ll s=sum+(yy-(x>>bit))*a;
                s+=bs*b;
                s+=cnt*a;
                zz|=(yy&1)<<bs;
                if(yy&1) cnt++;
                bs++;
                yy>>=1;
                ret=std::min(ret,s);
            }
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}