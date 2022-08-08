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
};
using mint=ModInt<int32_t,mod>;

// 0-indexed 
vc<mint> gauss_elimination(vvc<mint>A){
    i32 n=A.size();
    for(i32 i=0;i<n;++i){
        for(i32 j=i;j<n;++j){
            if(A[j][i]!=0){
                std::swap(A[i],A[j]);
                break;
            }
        }
        for(i32 j=i+1;j<n;++j){
            if(A[j][i]!=0){
                mint delta=A[j][i]*A[i][i].inv();
                for(i32 k=i;k<=n;++k){
                    A[j][k]-=A[i][k]*delta;
                }
                A[j][n]-=A[i][n]*delta;
            }
        }
    }
    vc<mint>ret(n);
    for(i32 i=n-1;i>=0;--i){
        for(i32 j=i+1;j<n;++j){
            A[i][n]-=A[j][n]*A[i][j];
        }
        ret[i]=A[i][n]*=A[i][i].inv();
    }
    return ret;
}

int32_t main(){
    i32 n; std::cin>>n;
    vvc<mint>A(n,vc<mint>(n+1));
    for(i32 i=0;i<n;++i){
        for(i32 j=0;j<=n;++j){
            std::cin>>A[i][j];
        }
    }
    for(mint x:gauss_elimination(A)){
        std::cout<<x<<',';
    }
    return 0;
}

/*

4
1 6 9 18 18
1 7 12 25 28
1 8 15 34 39
1 9 18 45 51

*/