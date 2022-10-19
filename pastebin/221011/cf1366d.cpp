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

namespace Input {
    constexpr size_t BUF_SZ = 1 << 15;
    char buf[1 << 15];
    size_t pos, len;
    char nc() {
        if (pos == len) pos = 0, len = (size_t)fread(buf, 1, BUF_SZ, stdin);
        if (!len) return EOF;
        return buf[pos++];
    }
    template<typename T=int32_t> T read() {
        T x = 0; char ch; T flg = 1;
        while (!isdigit(ch = nc())) if (ch == '-') flg = -flg;
        while ( isdigit(ch)) x = x * 10 + (ch ^ '0'), ch = nc();
        return x * flg;
    }
}
using Input::read;

namespace Output {
    constexpr size_t BUF_SZ = 1 << 15;
    char buf[BUF_SZ];
    size_t pos;
    void flush() { fwrite(buf, 1, pos, stdout); pos = 0; }
    void putch(char c) {
        if (pos == BUF_SZ) flush();
        buf[pos++] = c;
    }
    void putstr(char const* str) { for(; *str; str++) putch(*str); }
    template<typename T> void print(T x) {
        static char num_buf[32];
        if (x < 0)  putch('-'), x = -x;
        size_t len = 0;
        for (; x >= 10; x /= 10) num_buf[len++] = (x % 10) ^ '0';
        putch(x ^ '0');
        while (len) putch(num_buf[--len]);
    }
    template<typename T> void println(T x) { print(x); putch('\n'); }
    __attribute((destructor)) void exit() { flush(); }
}
using Output::putch, Output::print, Output::println, Output::putstr;


// find all the prime numbers no greater than n with time complexity O(n)
struct EulerSieve:std::vector<int>{
    std::vector<char>isPrime; // isPrime[i] => whether i is a prime number; isPrime[1] not defined
    std::vector<int>min_factor;
    EulerSieve(int n):std::vector<int>(),isPrime(n+1),min_factor(n+1){
        std::vector<char>vis(n+1);
        reserve(n/std::__lg(n));
        min_factor[1]=1;
        for(int i=2;i<=n;++i){
            if(!vis[i]) {
                push_back(i);
                vis[i]=true;
                isPrime[i]=true;
                min_factor[i]=i;
            }
            for(auto p:*this){
                if(i*p>n) break;
                vis[i*p]=true;
                if(i%p==0) {
                    min_factor[i*p]=p;
                    break;
                }
                min_factor[i*p]=min_factor[i];
            }
        }
    }
};

int32_t main() {
    i32 n = read();
    auto sieve = EulerSieve(10000010);
    vc<i64> A(n + 1, -1), B(n + 1, -1);
    for (i32 i = 1; i <= n; ++i) {
        i64 x = read();
        i64 min_factor = sieve.min_factor[x];
        while (x % min_factor == 0) x /= min_factor;
        if (x == 1) continue;
        A[i] = x;
        B[i] = min_factor;
    }
    for (i32 i = 1; i <= n; ++i) {
        print(A[i]); putch(" \n"[i == n]);
    }
    for (i32 i = 1; i <= n; ++i) {
        print(B[i]); putch(" \n"[i == n]);
    }
    return 0;
}
