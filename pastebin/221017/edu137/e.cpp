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

int32_t main() {
    i64 p1, t1, p2, t2, h, s;
    std::cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
    if (t1 > t2) std::swap(t1, t2), std::swap(p1, p2);
    i64 dmg1 = (t2 / t1 - 1) * (p1 - s) + (p1 + p2 - s);
    i64 tim1 = t2;
    i64 dmg2 = (t2 / t1) * (p1 - s) + (p1 + p2 - s);
    i64 tim2 = (t2 + t1 - 1) / t1 * t1;
    i64 ans = std::max(t1, t2) * h;
    for (i64 x1 = 0; x1 * dmg1 <= 2 * h; ++x1) {
        for (i64 x2 = 0; x1 * dmg1 + x2 * dmg2 <= 2 * h; ++x2) {
            if (x2) {
                /* 头上塞一个 2 */
                i64 tot_time = x1 * tim1 + x2 * tim2;
                i64 tot_dmg = x1 * dmg1 + x2 * dmg2;
                tot_time += t2 - (t1 - t2 % t1);
                tot_dmg += (p2 - s);
                tot_dmg += (t2 - (t1 - t2 % t1)) / t1 * (p1 - s);
                i64 rst_dmg = h - tot_dmg;
                if (rst_dmg > 0) {
                    i64 c1 = (ld) rst_dmg / (p1 - s + (ld)t1 / t2 * (p2 - s));
                    i64 c2 = (ld) rst_dmg / (p2 - s + (ld)t2 / t1 * (p1 - s));
                    i64 rst_time = INF<i64>();
                    for (i64 d = -4; d <= 4; ++d) {
                        i64 j1 = (c1 + d);
                        i64 j2 = (j1 * t1) / t2;
                        if (j1 >= 0 && j2 >= 0 && j1 * (p1 - s) + j2 * (p2 - s) >= rst_dmg) {
                            rst_time = std::min(rst_time, j1 * t1);
                        }
                    }
                    for (i64 d = -4; d <= 4; ++d) {
                        i64 j2 = (c2 + d);
                        i64 j1 = (j2 * t2) / t1;
                        if (j1 >= 0 && j2 >= 0 && j1 * (p1 - s) + j2 * (p2 - s) >= rst_dmg) {
                            rst_time = std::min(rst_time, j2 * t2);
                        }
                    }
                    assert(rst_time != INF<i64>());
                    tot_time += rst_time;
                }
                ans = std::min(ans, tot_time);
            }
            /* 头上不塞一个 2 */
            i64 tot_time = x1 * tim1 + x2 * tim2;
            i64 tot_dmg = x1 * dmg1 + x2 * dmg2;
            i64 rst_dmg = h - tot_dmg;
            if (rst_dmg > 0) {
                i64 c1 = (ld) rst_dmg / (p1 - s + (ld)t1 / t2 * (p2 - s));
                i64 c2 = (ld) rst_dmg / (p2 - s + (ld)t2 / t1 * (p1 - s));
                i64 rst_time = INF<i64>();
                for (i64 d = -4; d <= 4; ++d) {
                    i64 j1 = (c1 + d);
                    i64 j2 = (j1 * t1) / t2;
                    if (j1 >= 0 && j2 >= 0 && j1 * (p1 - s) + j2 * (p2 - s) >= rst_dmg) {
                        rst_time = std::min(rst_time, j1 * t1);
                    }
                }
                for (i64 d = -4; d <= 4; ++d) {
                    i64 j2 = (c2 + d);
                    i64 j1 = (j2 * t2) / t1;
                    if (j1 >= 0 && j2 >= 0 && j1 * (p1 - s) + j2 * (p2 - s) >= rst_dmg) {
                        rst_time = std::min(rst_time, j2 * t2);
                    }
                }
                assert(rst_time != INF<i64>());
                tot_time += rst_time;
            }
            ans = std::min(ans, tot_time);
        }
    }
    std::cout << ans << '\n';
    return 0;
}
