#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;
using i32=int32_t;
using i64=int64_t;
using i128=__int128;

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

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
    self operator/(self o)const{ return *this*o.inv(); }
};
using mint=ModInt<int32_t,mod>;

i32 d;
mint H,W;

mint z_(){
    return 1;
}

mint a_(){
    return W+H;
}

mint b_(){
    return W*H+H*H+W*W;
}

mint c_(){
    return H*W*W+W*H*H+H*H*H+W*W*W;
}

mint d_(){
    return H*H*W*W+H*H*H*W+W*W*W*H+H*H*H*H+W*W*W*W;
}

vvc<std::function<mint()>>fs{
    {},
    {z_},
    {z_,a_},
    {z_,a_,b_},
    {z_,a_,b_,c_},
    {z_,a_,b_,c_,d_}
};
vvc<mint>par{
    {},
    {1},
    {998244351,1},
    {6,mint(0)-mint(11)*mint(2).inv(),mint(1)+mint(2)*mint(3).inv()},
    {998244330,332748146,499122170,166374059,332748146,998244321,499122182,499122170,499122182,166374059},
    {104,249560934,707089806,748683260,291154603,249560934,332748336,499122106,332748122,707089806,499122106,16,748683260,332748122,291154603}
};

int32_t main(){
    std::cin>>H>>W>>d;
    mint ret=0;
    for(i32 i=0;i<(i32)fs[d].size();++i){
        ret+=fs[d][i]()*par[d][i];
    }
    std::cout<<ret<<'\n';
    return 0;
}
