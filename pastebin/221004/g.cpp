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
template<class T>T INF(){ return std::numeric_limits<T>::max(); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;

struct my_hash{
    size_t operator()(size_t x)const{
        static const size_t random_shift=std::chrono::steady_clock::now().time_since_epoch().count();
        x+=random_shift;
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
};

i64 qpow(i64 x,i64 y,i64 m){
    if(y==0) return 1;
    i64 ret=1;
    for(;y>0;y>>=1,x=x*x%m)
        if(y&1) ret=ret*x%m;
    return ret;
}

i64 BSGS(i64 A, i64 B, i64 P){
    if (B == 1) return 0;
    static std::unordered_map<i64, i64, my_hash> hs; hs.clear();
    i64 t = (i64)sqrt(P) + 1;
    for (i64 i = 0, cur = B; i < t; ++i)
        hs[cur] = i, cur = cur * A % P;
    i64 GS = qpow(A, t, P);
    for (i64 a = 1, cur = GS; a <= t; ++a) {
        auto it = hs.find(cur);
        if(it != hs.end()) return a * t - it->second;
        cur = cur * GS % P;
    }
    return -1;
}

int32_t main(){
    i32 T; std::cin >> T;
    while (T--) {
        i64 P, A, B, S, G; std::cin >> P >> A >> B >> S >> G;
        if (S == G) {
          std::cout << "0\n";
        } else if (A == 0) {
            if (G == B) {
                std::cout << "1\n";
            } else {
                std::cout << "-1\n";
            }
        } else if (A == 1) {
            // G = S + i * B
            // i = (G - S) / B
            if (B == 0) {
                std::cout << "-1\n";
            } else {
                std::cout << (G - S + P) % P * qpow(B, P - 2, P) % P << '\n';
            }
        } else {
            // x_0 = S
            // x_i = A * x_{i - 1} + B (mod P)
            // G = A ^ i * S + (A ^ i - 1) / (A - 1) * B
            // A ^ i * (S + B / (A - 1)) - B / (A - 1) = G
            // A ^ i = (G + B / (A - 1)) / (S + B / (A - 1))
            i64 B_over_A_minus_1 = B * qpow(A - 1, P - 2, P) % P;
            i64 fz = (G + B_over_A_minus_1) % P;
            i64 fm = qpow((S + B_over_A_minus_1) % P, P - 2, P);
            i64 ret = BSGS(A, fz * fm % P, P);
            std::cout << ret << '\n';
        }
    }
    return 0;
}
