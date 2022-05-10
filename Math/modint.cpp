#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct fint{
    static ll const p=1000000000039ll;
    ll x;
    fint(ll x=0):x(x){ }
    friend fint operator+(fint x,fint y){
        ll z=x.x+y.x;
        if(z>=p) z-=p;
        if(z<0) z+=p;
        return z;
    }
    friend fint operator-(fint x,fint y){
        y.x=-y.x;
        return x+y;
    }
    friend fint operator*(fint x,fint y){
        ll res=0;
        while(y.x){
            if(y.x&1)res=(res+x.x)%p;
            x=x+x; y.x>>=1;
        }return res;
    }
    friend fint operator/(fint x,fint y){
        return x*y.inv();
    }
    fint pow(fint y){
        if(y==0)
            return 1;
        fint x=*this;
        fint res=1;
        for(;y>0;y=y.x>>1,x=x*x)
            if(y.x&1)
                res=res*x;
        return res;
    }
    fint inv(){
        return this->pow(p-2);
    }
    friend bool operator==(fint x,fint y){
        return x.x==y.x;
    }
    friend bool operator<(fint x,fint y){
        return x.x<y.x;
    }
    friend bool operator>(fint x,fint y){
        return x.x>y.x;
    }
    friend bool operator!=(fint x,fint y){
        return x.x!=y.x;
    }
};