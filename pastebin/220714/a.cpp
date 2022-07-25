#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
    #define de(...) void()
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){std::cerr<<"[LINE: "<<__LINE__<<"]: ";_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int fcmp(ld x,ld y=0){ if(std::abs(x-y)<EPS) { return 0; } else { return x<y?-1:1; } }

struct Point{
    ld x,y;
    Point(ld x=0,ld y=0):x(x),y(y){}
    friend std::istream& operator>>(std::istream& is,Point& o){ return is>>o.x>>o.y; }
    friend std::ostream& operator<<(std::ostream& os,Point& o){ return os<<'('<<o.x<<", "<<o.y<<')'; }
    Point operator+(Point o){ return Point{x+o.x,y+o.y}; }
    Point operator-(Point o){ return Point{x-o.x,y-o.y}; }
    ld dot(Point o){ return x*o.x+y*o.y; }
    ld det(Point o){ return x*o.y-y*o.x; }
    ld len2(){ return x*x+y*y; }
    ld len(){  return std::sqrt(len2()); }
    ld dis2(Point o){ return (*this-o).len2(); }
    ld dis(Point o){  return (*this-o).len();  }
    int quad(){
        int fx=fcmp(x),fy=fcmp(y);
        if(fx>0&&fy>=0) return 1;
        if(fy>0&&fx<=0) return 2;
        if(fx<0&&fy<=0) return 3;
        if(fy<0&&fx>=0) return 4;
        return 0;
    }
};

int32_t main(){
    int n; std::cin>>n;
    std::vector<Point>A(n);
    std::vector<int>B(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i]>>B[i];
    }
    std::vector<Point>C;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(B[i]>B[j]){
                C.pb(A[i]-A[j]);
            }
        }
    }
    std::sort(all(C),[&](Point o1,Point o2){
        int q1=o1.quad(), q2=o2.quad();
        if(q1!=q2) return q1<q2;
        return fcmp(o1.det(o2))>0;
    });
    int sz=(int)C.size();
    bool ok=false;
    for(int i=0;i<sz;++i){
        de(C[i]);
        if(fcmp(C[i].det(C[(i+1)%sz]))<0||
            (fcmp(C[i].det(C[(i+1)%sz]))==0&&
                fcmp(-C[i].dot(C[(i+1)%sz]),C[i].len()*C[(i+1)%sz].len())==0)){
            ok=true;
        }
    }
    std::cout<<(ok||sz<=1?"Y":"N")<<'\n';
    return 0;
}