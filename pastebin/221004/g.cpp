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

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) return x = 1, y = 0, a;
    i64 d = exgcd(b, a % b, x, y), t = x;
    x = y, y = t - (a / b) * y;
    return d;
}

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

ll qpow(ll x,ll y,ll m){
    if(y==0) return 1;
    ll ret=1;
    for(;y>0;y>>=1,x=x*x%m)
        if(y&1) ret=ret*x%m;
    return ret;
}

// given a,b,m, where gcd(a,m)=1, find the minium x s.t. a^x=b(mod m)
ll BSGS(ll a,ll b,ll m){
    a%=m,b%=m;
    if(b==1) return 0;
    static std::unordered_map<ll,ll,my_hash>hs;
    hs.clear();
    ll t=(ll)sqrt(m)+1;
    for(int i=0,cur=b;i<t;++i) hs[cur]=i,cur=cur*a%m;
    ll stp=qpow(a,t,m);
    for(ll A=1,cur=stp;A<=t;++A) {
        auto it=hs.find(cur);
        if(it!=hs.end()) return A*t-it->second;
        cur=cur*stp%m;
    }
    return -1;
}


int32_t main(){
    i32 T; std::cin >> T;
    while (T--) {
        i64 P, A, B, S, G; std::cin >> P >> A >> B >> S >> G;
        if (A == 0) {
            if (G == S) {
                std::cout << "0\n";
            } else if (G == B) {
                std::cout << "1\n";
            } else {
                std::cout << "-1\n";
            }
        } else if (A == 1) {
            // B * x + P * y = G - S
            // a: B, b: P, c: G - S
            i64 a = B, b = P, c = ((G - S) % P + P) % P;
            i64 x, y;
            i64 g = exgcd(a, b, x, y);
            if (c % g != 0) {
                std::cout << "-1\n";
            } else {
                i64 d = c / g;
                x = (x % (b / g) + b / g) % (b / g);
                x *= d;
                std::cout << x << '\n';
            }
        } else {
            // A ^ k * (S + B / (A - 1)) = (B / (A - 1) + G)
            if (B % (A - 1) != 0 || (B / (A - 1) + G) % (S + B / (A - 1)) != 0) {
                std::cout << "-1\n";
            } else {
                i64 a = A, b = (B / (A - 1) + G) / (S + B / (A - 1)), m = P;
                i64 ret = BSGS(a, b, m);
                std::cout << ret << '\n';
            }
        }
    }
    return 0;
}
