#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
    #define de(...) 4933
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

template<typename T>
int fcmp(T x,T y=0,ld EPS=EPS){ if(std::fabs(x-y)<EPS) return 0; else return x<y?-1:1; }
template<typename T>
int sgn(T x){ return fcmp(x); }

struct Point{
    using Self=Point;
    using Inner=ld;
    Inner x,y;
    Point(Inner x=0,Inner y=0):x(x),y(y){ }
    friend std::istream& operator>>(std::istream& is,Self& o){ return is>>o.x>>o.y; }
    friend std::ostream& operator<<(std::ostream& os,Self& o){ return os<<'('<<o.x<<", "<<')';}
    Self operator+(Self o){ return Self{x+o.x,y+o.y}; }
    Self operator-(Self o){ return Self{x-o.x,y-o.y}; }
    Self operator/(Inner k){ return Self{x/k,y/k}; }
    Self operator*(Inner k){ return Self{x*k,y*k}; }
    bool operator==(Self o){ return fcmp(x,o.x)==0&&fcmp(y,o.y)==0; }
    bool operator!=(Self o){ return !(*this==o); }
    // 返回点所在的象限
    int quad(){
        int fx=fcmp(x),fy=fcmp(y);
        if(fx>0&&fy>=0) return 1;
        if(fy>0&&fx<=0) return 2;
        if(fx<0&&fy<=0) return 3;
        if(fy<0&&fx>=0) return 4;
    }
    // 返回 this 绕 ori 旋转 r 的角度之后的点
    Self rot(Inner cosr,Inner sinr,Self ori=Self{0,0}){
        return Self{
            (x-ori.x)*cosr-(y-ori.y)*sinr+ori.x,
            (x-ori.x)*sinr+(y-ori.y)*cosr+ori.y
        };
    }
    // 点积
    Inner dot(Self o){ return x*o.x+y*o.y; }
    // 叉积
    Inner det(Self o){ return x*o.y-y*o.x; }
    // 返回向量长度的平方
    Inner len2(){ return x*x+y*y; }
    // 返回向量长度
    Inner len(){ return std::sqrt(x*x+y*y); }
    // 返回点与点之间的距离的平方
    Inner dis2(Self o){ return (x-o.x)*(x-o.x)+(y-o.y)*(y-o.y); }
    // 返回点与点之间的距离
    Inner dis(Self o){ return std::sqrt((x-o.x)*(x-o.x)+(y-o.y)*(y-o.y)); }
    // 判断该点是否在有向直线 o1->o2 的左侧，1=>左侧，0=>线上，-1=>右侧
    int to_left(Self o1,Self o2){ return fcmp((o2-o1).det(*this-o2)); } 
    // 判断向量是否平行
    bool is_par(Self o){ return fcmp(det(o))==0; }
    // 判断向量是否垂直
    bool is_ver(Self o){ return fcmp(dot(o))==0; }
};

struct Line{
    using Self=Line;
    using Inner=Point;
    using dtype=ld;
    // u 为直线的某一点，v 为直线的方向向量
    Inner u,v;
    Line(Inner x=Inner(),Inner y=Inner()):u(x),v(y-x){ }
    // 判断两直线是否完全相同
    friend bool operator==(Self o1,Self o2){ return o1.v.is_par(o2.v) && o1.v.is_par(o1.u-o2.u); }
    // 判断两直线是否平行
    bool is_par(Self o){ return v.is_par(o.v) && !v.is_par(u-o.u); }
    // 判断两直线是否垂直
    bool is_ver(Self o){ return v.is_ver(o.v); }
    // 判断点 o 是否在直线上
    bool is_on(Inner o){ return v.is_par(o-u); }
    // 判断点 o 是否在线段上
    bool is_in(Inner o){ return is_on(o)&&fcmp((o-u).dot(o-(u+v)))<=0; }
    // 判断点 o 是否为端点
    bool is_edg(Inner o){ return o==u||o==u+v; }
    // 求两直线的交点
    Inner inter(Self o){ return u+v*((o.v.det(u-o.u))/(v.det(o.v))); }
    // 求点 o 到直线的距离
    dtype dis(Inner o){ return std::abs(v.det(o-u))/v.len(); }
    // 求点 o 在直线上的投影点
    Inner proj(Inner o){ return u+v*((v.dot(o-u))/(v.dot(v))); }
    // 判断两线段是否相交
    friend bool intersect(Line l1, Line l2){
        auto a=l1.u,b=l1.u+l1.v,c=l2.u,d=l2.u+l2.v;
        if( fcmp(std::min(a.x,b.x),std::max(c.x,d.x))>0 ||
            fcmp(std::min(a.y,b.y),std::max(c.y,d.y))>0 ||
            fcmp(std::min(c.x,d.x),std::max(a.x,b.x))>0 ||
            fcmp(std::min(c.y,d.y),std::max(a.y,b.y))>0 ){ return false; }
        return sgn((b-a).det(c-a))*sgn((b-a).det(d-a))<=0 &&
               sgn((d-c).det(a-c))*sgn((d-c).det(b-c))<=0;
    }
};

struct Convex:std::vector<Point>{
    using Self=Convex;
    using Inner=Point;
    Convex(int n=0):std::vector<Point>(n){ }
    // 按照以原点为原点进行极角排序
    void sort_by_quad(Inner ori=Inner{0,0}){
        std::sort(begin(),end(),[ori](Inner o1,Inner o2){
            o1=o1-ori; o2=o2-ori;
            return o1.quad()==o2.quad()?fcmp(o1.det(o2))>0:o1.quad()<o2.quad();
        });
    }
    // 按照最左下角的点进行极角排序
    void sort_by_ltl(){
        Inner ltl=*std::min_element(begin(),end(),[](Inner o1,Inner o2){ return fcmp(o1.x,o2.x)==0?fcmp(o1.y,o2.y)<0:fcmp(o1.x,o2.x)<0; });
        std::sort(begin(),end(),[ltl](Inner o1,Inner o2){
            auto cross=(o1-ltl).det(o2-ltl);
            return fcmp(cross)==0?(fcmp(o1.x,o2.x)==0?fcmp(o1.y,o2.y)<0:fcmp(o1.x,o2.x)<0):fcmp(cross)>0;
        });
    }
    // 从点集中得到凸包
    Self get_convex(){
        Self A=*this; A.sort_by_ltl();
        A.erase(std::unique(all(A)),A.end());
        if((int)A.size()==1) return A;
        std::vector<int>B{0,1};
        for(int i=2;i<(int)A.size();++i){
            while(((int)B.size()>=2)&&(A[i].to_left(A[*next(B.rbegin())],A[B.back()])<=0)) B.pop_back();
            B.pb(i);
        }
        Self ret; ret.reserve(B.size());
        std::for_each(all(B),[&](int i){ ret.pb(A[i]); });
        return ret;
    }
    // 求凸包直径的平方
    ld dismeter2(){
        Self& g=*this;
        int p=1,n=(int)g.size();
        auto area=[&](int i,int j,int q){
            return (g[j]-g[i]).det(g[q]-g[i]);
        };
        ld ret=0;
        for(int i=0;i<n;++i){
            while(area(i,(i+1)%n,p)<area(i,(i+1)%n,(p+1)%n))p=(p+1)%n;
            ret=std::max({ret,g[i].dis2(g[p]),g[(i+1)%n].dis2(g[p])});
        }
        return ret;
    }
    // 判断点是否在多边形内（可以不是凸包）
    bool is_in(Inner p){
        Self& A=*this; int n=(int)A.size();
        int cnt = 0;
        for(int i=0;i<n;++i){
            auto u=A[i],v=A[(i+1)%n];
            Line uv(u,v);
            if(uv.is_in(p)) return true;
            int k=fcmp(uv.d.det(p-u));
            int d1=fcmp(u.y-p.y);
            int d2=fcmp(v.y-p.y);
            if(k>0 && d1<=0 && d2>0) cnt--;
            if(k<0 && d1>0 && d2<=0) cnt++;
        }
        return cnt!=0;
    }
};



int32_t main(){
    Convex A;
    int n=10;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            A.pb(Point{i,j});
        }
    }
    auto B=A.get_convex();
    for(auto [x,y]:B){
        std::cout<<x<<' '<<y<<'\n';
    }
    return 0;
}