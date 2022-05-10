#include <iostream>
#include <vector>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define ll long long
#define int long long

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
        for(;y>0;y.x>>=1,x=x*x)
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

// pre=>O(n), qry=>O(1), prime mod number only
struct conbi_lin{
    const static ll p=1000000000039ll;
    std::vector<fint>fac,inv;
    conbi_lin(int n):fac(n+1),inv(n+1){
        fac[0]=1;
        for(int i=1;i<=n;++i)
            fac[i]=fac[i-1]*i;
        inv[n]=fac[n].inv();
        for(int i=n-1;i>=0;--i)
            inv[i]=inv[i+1]*(i+1);
    }
    ll operator()(int x,int y){
        if(y<0||y>x)
            return 0;
        return (fac[x]*inv[y]*inv[x-y]).x;
    }
};

signed main(){
    conbi_lin C(100100);
    while(true){
        int n,m; std::cin>>n>>m;
        if(n==0&&m==0) break;
        if(n>100000){
            std::cout<<(m==0||m==n?1:n)<<'\n';
        }else{
            std::cout<<C(n,m)<<'\n';
        }
    }
    return 0;
}