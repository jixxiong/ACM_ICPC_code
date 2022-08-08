#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6+10,mod=998244353,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,m;cin>>n>>m;
        vector<int> a(n+1),b(n+1);
        struct node
        {
            int l,r,id;
        };
        int cnt=sqrt(n);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            --a[i];
            a[i]^=a[i-1];
            b[i]=(i-1)/cnt+1;
        }
        vector<node> q(m+1);
        vector<int> ret(m+1);
        for(int i=1;i<=m;++i)
        {
            cin>>q[i].l>>q[i].r;
            --q[i].l,q[i].r;
            q[i].id=i;
        }
        sort(q.begin()+1,q.end(),[&](node i,node j){return (b[i.l]^b[j.l])?b[i.l]<b[j.l]:((b[i.l]&1)?i.r<j.r:i.r>j.r);});
        vector<int> ans(2);
        vector sum(2,vector<int>(1000001));
        auto del=[&](int x,int b) -> void
        {
            --sum[b][x];
            ans[b]-=sum[b][x];
        };
        auto add=[&](int x,int b) -> void
        {
            ans[b]+=sum[b][x];
            ++sum[b][x];
        };
        int tl=0,tr=-1;
        for(int i=1;i<=m;++i)
        {
            while(tl<q[i].l) {del(a[tl],tl&1);++tl;}
            while(tl>q[i].l) {--tl;add(a[tl],tl&1);}
            while(tr<q[i].r) {++tr;add(a[tr],tr&1);}
            while(tr>q[i].r) {del(a[tr],tr&1);--tr;}
            int len=q[i].r-q[i].l;
            ret[q[i].id]=len*(len+1)/2;
            ret[q[i].id]-=ans[0]+ans[1];
            
        }
        for(int i=1;i<=m;++i) cout<<ret[i]<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/
template<class fint,fint p>
struct ModInt{
    using self=ModInt<fint,p>;
    fint _x;
    ModInt(fint x=0):_x((x%p+p)%p){ }
    fint val()const{ return _x; }
    self operator+(self o)const{ fint x=_x+o._x; if(x<0) x+=p; if(x>=p) x-=p; return self(x); }
    self operator-(self o)const{ fint x=_x-o._x; if(x<0) x+=p; if(x>=p) x-=p; return self(x); }
    self operator*(self o)const{ fint x=(int64_t)_x*o._x%p; if(x<0) x+=p; return self(x); }
    friend std::istream& operator>>(std::istream& is,self& o){ return is>>o._x; }
    friend std::ostream& operator<<(std::ostream& os,self  o){ return os<<o._x; }
    bool operator==(self o)const{ return _x==o._x; }
    bool operator!=(self o)const{ return _x!=o._x; }
    self& operator+=(self o){ return *this=*this+o; }
    self& operator-=(self o){ return *this=*this-o; }
    self& operator*=(self o){ return *this=*this*o; }
    self pow(self _y)const{
        self x=*this; fint y=_y.val();
        if(y==0) return self(1); 
        self ret(1);
        while(y){
            if(y&1) ret=ret*x;
            x*=x; y>>=1;
        }
        return ret;
    }
    self inv()const{ return pow(p-2); }
};
using mint=ModInt<int32_t,mod>;


template<class fint,fint p>
struct ModInt{
    using self=ModInt<fint,p>;
    fint _x;
    ModInt(fint x=0):_x((x%p+p)%p){ }
    fint val()const{ return _x; }
    self operator+(self o)const{ fint x=_x+o._x; if(x<0) x+=p; if(x>=p) x-=p; return self(x); }
    self operator-(self o)const{ fint x=_x-o._x; if(x<0) x+=p; if(x>=p) x-=p; return self(x); }
    self operator*(self o)const{ fint x=(int64_t)_x*o._x%p; if(x<0) x+=p; return self(x); }
    friend std::istream& operator>>(std::istream& is,self& o){ return is>>o._x; }
    friend std::ostream& operator<<(std::ostream& os,self  o){ return os<<o._x; }
    bool operator==(self o)const{ return _x==o._x; }
    bool operator!=(self o)const{ return _x!=o._x; }
    self& operator+=(self o){ return *this=*this+o; }
    self& operator-=(self o){ return *this=*this-o; }
    self& operator*=(self o){ return *this=*this*o; }
    self pow(self _y)const{
        self x=*this; fint y=_y.val();
        if(y==0) return self(1);
        self ret(1);
        while(y){
            if(y&1) ret=ret*x;
            x*=x; y>>=1;
        }
        return ret;
    }
    self inv()const{ return pow(p-2); }
    self operator/(self o)const{ return self*o.inv(); }
};
using mint=ModInt<int32_t,mod>;

struct Conbi{
    vc<mint>fac,invfac;
    Conbi(int n):fac(n+1),invfac(n+1){ 
        fac[0]=1;
        for(int i=1;i<=n;++i){
            fac[i]=fac[i-1]*i;
        }
        invfac[n]=fac[n].inv();
        for(int i=n-1;i>=0;--i){
            invfac[i]=invfac[i+1]*(i+1);
        }
    }
    mint operator()(int x,int y)const{
        if(y<0||y>x) return mint(0);
        return fac[x]*invfac[x-y]*invfac[y];
    }
};
