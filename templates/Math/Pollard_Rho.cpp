#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
#define ld long double
#define ll long long
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
template<class T>using vc    =std::vector<T>;
template<class T>using vvc   =vc<vc<T>>;
template<class T>using vvvc  =vc<vvc<T>>;
template<class T>using vvvvc =vc<vvvc<T>>;
template<class T>using vvvvvc=vc<vvvvc<T>>;
template<class T> auto vcc   (i32 _1=0,i32 _2=0,const T&init=T()){ return vvc<T>(_1,vc<T>(_2,init)); }
template<class T> auto vccc  (i32 _1=0,i32 _2=0,i32 _3=0,const T&init=T()){ return vvvc<T>(_1,vcc(_2,_3,init)); }
template<class T> auto vcccc (i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,const T&init=T()){ return vvvvc<T>(_1,vccc(_2,_3,_4,init)); }
template<class T> auto vccccc(i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,i32 _5=0,const T&init=T()){ return vvvvvc<T>(_1,vcccc(_2,_3,_4,_5,init)); }
template<class T> T INF() { return std::numeric_limits<T>::max(); }

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;


/*---------------------------------------------
 利用 Miller-Rabin进行素性测试
 ----------------------------------------------*/
vc<i64> const testnum{2,7,61,3,5,11,13,19};

i64 qpow(i64 a,i64 b,i64 p){
    /*返回a^b % p*/
    i64 res = 1;
    while (b) {
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

bool isPrime(i64 n){
    /*Miller-Rabin判定x是否为素数*/
    if(n == 2) return true;
    if(n < 2 || n % 2 == 0) return false;
    i64 d = n - 1, x, y; i32 t = 0;
    while((d & 1) == 0) d >>= 1, t++;
    for (i64 a: testnum) {
        if(n == a) return true;
        x = qpow(a, d, n);
        for(i32 j = 0; j < t; ++j){
            y = x * x % n;
            if(y == 1 && x != 1 && x != n - 1) return false;
            x = y;
        }
        if(x != 1) return false;
    }
    return true;
}

/*---------------------------------------------
 利用 pollard rho 算法进行质因数分解
 ----------------------------------------------*/
struct Pollard_Rho: vc<i64> {
    static i64 rng() {
        static std::mt19937 func(4933);
        return func();
    }
    i64 pollard_rho(i64 x,i64 c){
        /* 返回 x 的一个因子或 x 本身 */
        i64 i = 1,k = 2;
        i64 tx = rng() % x;
        i64 y = tx;
        while(true){
            i++;
            tx = (tx * tx % x + c) % x;
            ll d = std::__gcd(std::abs(y - tx), x);
            if(d != 1 && d != x) return d;
            if(y == tx) return x;       //寻找失败
            if(i == k) y = tx, k += k;
        }
    }
    void findFac(i64 n){
        /* 对 n 进行质因数分解 */
        if(isPrime(n)){
            emplace_back(n);
            return ;
        }
        i64 p = n;
        /* 通过pollard_rho算法找到 n 的一个因子 p */
        while(p >= n) p = pollard_rho(p, rng() % (n - 1) + 1);
        findFac(p);     //递归分解
        findFac(n / p);
    }
    Pollard_Rho(i64 n) {
        findFac(n);
        std::sort(begin(), end());
    }
};

int32_t main() {

    return 0;
}
