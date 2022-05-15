#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) (x).begin(),(x).end()
#define pb emplace_back
using ll=long long;

using db=long double;
db const eps=1e-9;
db const PI=std::acos((db)-1.0);

int fcmp(ll x,ll y=0){
    if(x==y) return 0;
    return x<y?-1:1;
}

int fcmp(db x,db y=0){
    if(fabs(x-y)<eps) return 0;
    return x<y?-1:1;
}

struct point{
    db x,y;
    point(db x=0,db y=0):x(x),y(y){ }
    // 返回向量 o1, o2 之和
    friend point operator+(point o1,point o2){ return {o1.x+o2.x,o1.y+o2.y}; }
    // 返回向量 o1,o2 之差
    friend point operator-(point o1,point o2){ return {o1.x-o2.x,o1.y-o2.y}; }
    // 返回向量 o 的相反向量
    friend point operator-(point o){ return {-o.x,-o.y}; }
    // 返回 k 倍的向量 o
    friend point operator*(point o,db k){ return {o.x*k,o.y*k}; }
    friend point operator*(db k,point o){ return {o.x*k,o.y*k}; }
    // 返回 1/k 的向量 o
    friend point operator/(point o,db k){ return {o.x/k,o.y/k}; }
    // 返回 o1 和 o2 是否为同一点（向量）
    friend bool operator==(point o1,point o2){ return fcmp(o1.x,o2.x)==0&&fcmp(o1.y,o2.y)==0; }
    // 返回 o1 和 o2 是否不为同一点（向量）
    friend bool operator!=(point o1,point o2){ return !(o1==o2); }
    // 返回向量 o1 和 o2 的叉积
    friend db crs(point o1,point o2){ return o1.x*o2.y-o1.y*o2.x; }
    // 返回向量 o1 和 o2 的点积
    friend db dot(point o1,point o2){ return o1.x*o2.x+o1.y*o2.y; }
};

// 返回 o 是否在有向直线 o1->o2 的左侧 
bool to_left(point o1,point o2,point o){
    return fcmp(crs((o2-o1),(o-o2)))>0;
}

// 返回点所在的象限
int get_quad(point a){
    if(fcmp(a.x)>0&&fcmp(a.y)>=0) return 1;
    if(fcmp(a.x)<=0&&fcmp(a.y)>0) return 2;
    if(fcmp(a.x)<0&&fcmp(a.y)<=0) return 3;
    if(fcmp(a.x)>=0&&fcmp(a.y)<0) return 4;
    assert(false);
}

// 返回极角序大小，原点为 (0,0) 
bool cmp_by_quad(point o1,point o2){
    int q1=get_quad(o1),q2=get_quad(o2);
    if(q1!=q2) return q1<q2;
    return to_left({0,0},o1,o2);
}

// 按照极角序排 arr，原点为 (0,0)
void sort_by_ori(std::vector<point>&arr){ 
    std::sort(all(arr),cmp_by_quad);
}

// 按照极角序排 arr，原点为 最左下角的点
void sort_by_ltl(std::vector<point>&arr){
    point ltl=*std::min_element(all(arr),
        [](point o1,point o2){ 
            int f1=fcmp(o1.x,o2.x);
            return f1!=0?f1<0:fcmp(o1.y,o2.y)<0;
        });
    std::sort(all(arr),
        [ltl](point o1,point o2){
            db cross=crs((o1-ltl),(o2-o1));
            if(fcmp(cross)==0)
                return fcmp(o1.x,o2.x)<0||fcmp(o1.y,o2.y)<0;
            return fcmp(cross)>0;
        });
}

// 返回点 o1 和 o2 的距离的平方
db distance_squ(point o1,point o2){
    return (o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y);
}

// 返回点 o1 和 o2 的距离
db distance(point o1,point o2){
    return std::sqrt(distance_squ(o1,o2));
}

// 返回点 p 在逆时针旋转 ang 角度后的点
point rotate(point p,db ang){
    return {p.x*std::cos(ang)-p.y*std::sin(ang),
            p.x*std::sin(ang)+p.y*std::cos(ang)};
}

// 返回平面最近点对的距离
db min_distance(std::vector<point>A){
    int n=(int)A.size();
    db ang=rand()%360*PI/180;
    for(int i=0;i<n;++i){
        A[i]=rotate(A[i],ang);
    }
    // order by x than y
    sort(all(A),
        [](point p1,point p2){
            return fcmp(p1.y,p2.y)==0?fcmp(p1.x,p2.x)<0:fcmp(p1.y,p2.y)<0;
        });
    db ret=std::numeric_limits<db>::max();
    for(int i=0;i<n-1;++i)
        for(int j=std::max(0,i-5);j<=std::min(n-1,i+5);++j)
            if(i!=j)
                ret=std::min(ret,distance(A[i],A[j]));
    return ret;
}


struct line{
    point s,t;
    void regular(){ // theta(t-s) in [0,PI)
        int f=fcmp(s.y,t.y);
        if(f>0) std::swap(s,t);
        if(f==0&&fcmp(s.x,t.x)>0) std::swap(s,t);
    }
    line(db x1,db y1,db x2,db y2):s(x1,y1),t(x2,y2){ regular(); }
    line(point s,point t):s(s),t(t){ regular(); }
};
// 返回直线是不是退化成点
bool is_point(line l){ return l.s==l.t; }
// assert 直线一定没有退化成点
void ast(line l){ assert(!is_point(l)); }

// 返回点 p 在 直线 l 上的投影
point projection(point p,line l){
    assert(l.s!=l.t);
    point a(p-l.s),b(l.t-l.s);
    return dot(a,b)/distance_squ(l.s,l.t)*b+l.s;
}

// 返回点 p 到直线 l 的距离
db distance(point p,line l){
    return distance(p,projection(p,l));
}

// 返回线段 l 的长度的平方
db length_squ(line l){
    return distance_squ(l.s,l.t);
}

// 返回线段 l 的长度
db length(line l){
    return distance(l.s,l.t);
}

// 返回 p 是否在直线 l 上
bool is_on_line(point p,line l){
    ast(l);
    return fcmp(crs((l.s-p),(l.t-l.s)))==0;
}

// 返回 p 是否在线段 l 上
bool is_on_segment(point p,line l){
    if(is_point(l)) return p==l.s;
    return is_on_line(p,l)&&
            ((fcmp(l.s.y,l.t.y)==0)?
            (fcmp(p.x,l.s.x)>=0&&fcmp(p.x,l.t.x)<=0):
            (fcmp(p.y,l.s.y)>=0&&fcmp(p.y,l.t.y)<=0));
}

// 返回直线 l1 是否平行于直线 l2
bool is_parallel(line l1,line l2){
    ast(l1),ast(l2);
    return fcmp(crs((l1.t-l1.s),(l2.t-l2.s)))==0;
}

// 返回两直线的交点数量和交点坐标
// -1 => 直线重合，无数交点
// 0  => 直线平行，0 个交点
// 1  => 直线相交，1 个交点
std::pair<int,point> intersect_line(line l1,line l2){
    ast(l1),ast(l2);
    if(is_parallel(l1,l2)) return {is_on_line(l1.s,l2)?-1:0,{}};
    point A=l1.s,B=l1.t,C=l2.s,D=l2.t;
    db A1=B.y-A.y,A2=D.y-C.y;
    db B1=A.x-B.x,B2=C.x-D.x;
    db C1=A1*A.x+B1*A.y,C2=A2*C.x+B2*C.y;
    db fm=A1*B2-A2*B1;
    assert(fcmp(fm)!=0);
    return {1,{(B2*C1-B1*C2)/fm,(A1*C2-A2*C1)/fm}};
}

// 返回两线段的交点数量和交点坐标
// -1 => 线段相交于无数点
// 0  => 线段无交点（平行，共线无交点...）
// 1  => 线段仅有一个交点（可能头尾相接、交错相交）
std::pair<int,point> intersect_segment(line l1,line l2){
    if(is_point(l1)){
        if(is_on_segment(l1.s,l2)) return {1,l1.s};
        return {0,{}};   
    }
    if(is_point(l2)){
        if(is_on_segment(l2.s,l1)) return {1,l2.s};
        return {0,{}};
    }
    if(is_parallel(l1,l2)){
        if(crs((l1.t-l2.s),(l1.s-l2.s))==0){
            if(l1.s==l2.t) return {1,l1.s};
            if(l1.t==l2.s) return {1,l1.t};
            if(fcmp(l1.s.y,l1.t.y)==0?
                (fcmp(l1.t.x,l2.s.x)<0||fcmp(l2.t.x,l1.s.x)<0):
                (fcmp(l1.t.y,l2.s.y)<0||fcmp(l2.t.y,l2.s.y)<0))
                return {0,{}};
            return {-1,{}};
        }
        return {0,{}};
    }
    if( (to_left(l1.s,l1.t,l2.s)^to_left(l1.s,l1.t,l2.t)) &&
        (to_left(l2.s,l2.t,l1.s)^to_left(l2.s,l2.t,l1.t))){
        return intersect_line(l1,l2);
    }
    return {0,{}};
}

// 凸包的定义（一个 point 的数组，一般要求按照和 ltl 的极角序逆时针排序）
using polygon=std::vector<point>;

// 返回 p 是不是在凸包 g 的顶点上
bool is_on_vertex(point p,polygon const & g){
    for(const auto& pnt:g) if(p==pnt) return true;
    return false;
}

// 返回 p 是不是在凸包 g 的边上
bool is_on_edge(point p,polygon const & g){
    int n=(int)g.size();
    for(int i=0;i<n;++i)
        if(is_on_segment(p,{g[i],g[(i+1)%n]})) return true;
    return false;
}

// 返回 p 是不是在凸包 g 的内部
bool is_inside_poly(point p,polygon const & g){
    if(is_on_edge(p,g)) return false;
    int n=(int)g.size();
    for(int i=0;i<n;++i)
        if(!to_left(p,g[i],g[(i+1)%n])) return false;
    return true;
}

// 返回 p 是不是在凸包 g 的外部
bool is_outside_poly(point p,polygon const & g){
    return !(is_on_edge(p,g)||is_inside_poly(p,g));
}

// 返回凸包 g 的面积
db area(polygon const & g){
    db ret=0;
    int n=(int)g.size();
    for(int i=0;i<n;++i)
        ret+=crs(g[i],g[(i+1)%n])/2;
    return fcmp(ret)<0?-ret:ret;
}

// 返回凸包 g 的
db length(polygon const & g){
    db ret=0;
    int n=(int)g.size();
    if(n==2)
        return distance(g[0],g[1]);
    for(int i=0;i<n;++i)
        ret+=distance(g[i],g[(i+1)%n]);
    return ret;
}

// 返回 A 中点构成的凸包
polygon get_convex_hull(std::vector<point> A){
    sort_by_ltl(A);
    std::vector<int>B{0,1};
    for(int i=2;i<(int)A.size();++i){
        while(((int)B.size()>=2)&&
            (!to_left(A[*next(B.rbegin())],A[B.back()],A[i])))
            B.pop_back();
        B.pb(i);
    }
    polygon ret; ret.reserve(B.size());
    std::for_each(all(B),[&](int i){ret.pb(A[i]);});
    return ret;
}

// 返回凸包 g 的直径的平方
db diameter_squ(polygon const & g){
    int p=1,n=g.size();
    auto area=[&](int i,int j,int q){
        return crs((g[j]-g[i]),(g[q]-g[i]));
    };
    db ret=0;
    for(int i=0;i<n;++i){
        while(area(i,(i+1)%n,p)<area(i,(i+1)%n,(p+1)%n))p=(p+1)%n;
        ret=std::max({ret,distance_squ(g[i],g[p]),distance_squ(g[(i+1)%n],g[p])});
    }
    return ret;
}

// 返回凸包 g 的直径
db diameter(polygon const & g){
    return std::sqrt(diameter_squ(g));
}

int main(){
    int n; std::cin>>n;
    std::vector<point> A(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i].x>>A[i].y;
    }
    auto g=get_convex_hull(A);
    std::cout<<diameter_squ(get_convex_hull(A))<<'\n';
    return 0;
}