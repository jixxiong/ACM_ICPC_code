#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
decltype(clock()) tic, toc;
__attribute((constructor))void before(){tic=clock();}
__attribute((destructor)) void after (){toc=clock(); std::cerr<<"\nFinished in "<<toc-tic<<" ms.\n"; }
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define i32 int32_t
#define i64 int64_t
#define i128 __int128
#define ld long double
#define pb emplace_back
#define all(x) x.begin(),x.end()
template<class T> T INF() { return std::numeric_limits<T>::max(); }
template<class T,i32 D=1> struct vc: std::vector<std::conditional_t<D==1,T,vc<T,D-1>>>{
    using VC = std::conditional_t<D == 1, T, vc<T, D - 1>>;
    template<class...A> vc(A... a): std::vector<VC>(a...) { }
    template<class...A> vc(i32 s=0, A... a): std::vector<VC>(s, VC(a...)) { }
};

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;

int32_t main() {
    vc<char, 2> A(10, 10);
    std::set<std::pair<int, int>> B;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            std::cin >> A[i][j];
            if (A[i][j] == '#') {
                B.insert(std::pair<int, int>{i, j});
            }
        }
    }
    i32 cnt = 0;
    for (auto [x1, y1]: B) {
        for (auto [x2, y2]: B) {
            if (x1 == x2 && y1 == y2) continue;
            for (auto [x3, y3]: B) {
                if (x3 == x1 && y3 == y1) continue;
                if (x3 == x2 && y3 == y2) continue;
                i32 x4 = (x1 + x2 - x3);
                i32 y4 = (y1 + y2 - y3);
                if (x4 < 1 || x4 > 9 || y4 < 1 || y4 > 9) continue;
                if ((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3) == 0 &&
                    (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) ==
                    (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3) &&
                    B.count({x4, y4})) {
                        cnt++;
                    }
            }
        }
    }
    std::cout << cnt / 8 << '\n';
    return 0;
}
