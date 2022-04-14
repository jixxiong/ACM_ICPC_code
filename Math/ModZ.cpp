#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

struct Z{
    signed x;
    const static signed p=1000000007;
    Z(int x=0):x(x%p){ }
    Z operator+(const Z&o)const{ return (x+o.x)%p; }
    Z operator-(const Z&o)const{ return (p+x-o.x)%p; }
    Z operator*(const Z&o)const{ return (long long)x*o.x%p; }
    Z& operator+=(const Z&o){ x=(x+o.x)%p; return *this; }
    Z& operator-=(const Z&o){ x=(p+x-o.x)%p; return *this; }
    Z& operator*=(const Z&o){ x=((long long)x*o.x)%p; return *this; }
    Z inv(){
        signed a=x,b=p-2,c=1;
        for(;b>0;b>>=1,a=(long long)a*a%p)
            if(b&1) c=(long long)c*a%p;
        return Z(c);
    }
    bool operator==(const Z&o)const{ return x==o.x;}
    friend ostream&operator<<(ostream&os,const Z&o){ return os<<o.x; }
};

signed main(){

    return 0;
}