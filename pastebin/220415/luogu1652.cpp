#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

using db=long double;
const db eps=1e-9;
const db pi=std::acos((db)-1.0);

int fcmp(ll x,ll y=0){
    if(x==y) return 0; // fabs(x-y)<eps
    return x<y?-1:1;
}
int fcmp(db x,db y=0){
    if(fabs(x-y)<eps) return 0; // fabs(x-y)<eps
    return x<y?-1:1;
}

template<typename fint=db>
struct point{
    fint x,y;
    point(fint x=0,fint y=0):x(x),y(y){ }
    template<typename dint>
    point(const point<dint>&p):x(p.x),y(p.y){ }
};
template<typename fint>
point<fint> operator+(const point<fint>&o1,const point<fint>&o2){
    return {o1.x+o2.x,o1.y+o2.y};
}
template<typename fint>
point<fint> operator-(const point<fint>&o1,const point<fint>&o2){
    return {o1.x-o2.x,o1.y-o2.y};
}
template<typename fint>
point<fint> operator-(const point<fint>&o1){
    return {-o1.x,-o1.y};
}
template<typename fint>
point<db> operator*(const point<fint>&o,db l){
    return {o.x*l,o.y*l};
}
template<typename fint>
point<db> operator*(db l,const point<fint>&o){
    return {o.x*l,o.y*l};
}
template<typename fint>
bool operator==(const point<fint>&o1,const point<fint>&o2){
    return fcmp(o1.x,o2.x)==0&&fcmp(o1.y,o2.y)==0;
}
template<typename fint>
fint crs(const point<fint>&o1,const point<fint>&o2){
    return o1.x*o2.y-o2.x*o1.y;
}
template<typename fint>
fint dot(const point<fint>&o1,const point<fint>&o2){
    return o1.x*o2.x+o1.y*o2.y;
}
template<typename fint>
bool to_left(const point<fint>&o1,const point<fint>&o2,const point<fint>&o){
    return fcmp(crs((o2-o1),(o-o2)))>0;
}
template<typename fint>
int get_quad(const point<fint>&a){
    if(fcmp(a.x)>0&&fcmp(a.y)>=0) return 1;
    if(fcmp(a.x)<=0&&fcmp(a.y)>0) return 2;
    if(fcmp(a.x)<0&&fcmp(a.y)<=0) return 3;
    if(fcmp(a.x)>=0&&fcmp(a.y)<0) return 4;
    assert(false);
}
template<typename fint>
bool cmp_quad(const point<fint>&o1,const point<fint>&o2){
    int q1=get_quad(o1),q2=get_quad(o2);
    if(q1!=q2) return q1<q2;
    return to_left({0,0},o1,o2);
}
template<typename fint>
void sort_by_ori(std::vector<point<fint>>&arr){ 
    std::sort(all(arr),cmp_quad);
}
template<typename fint>
void sort_by_ltl(std::vector<point<fint>>&arr){
    point<fint> ltl=*std::min_element(all(arr),[](const point<fint>&o1,const point<fint>&o2){
        int f1=fcmp(o1.y,o2.y);
        return f1==0?f1<0:fcmp(o1.x,o2.x)<0;
    });
    std::sort(all(arr),[&](const point<fint>&o1,const point<fint>&o2){
        fint cross=crs((o1-ltl),(o2-o1));
        if(fcmp(cross)==0){ // o1,ltl,o2 在一条直线上，按照和 ltl 距离排序
            int f1=fcmp(o1.x,o2.x);
            if(f1!=0) return f1<0;
            return fcmp(o1.y,o2.y)<0;
        }
        return fcmp(cross)>0; // o2 在 ltl->o1 的左侧
    });
}
template<typename fint>
fint distance2(const point<fint>&o1,const point<fint>&o2){
    return (o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y);
}
template<typename fint>
db distance(const point<fint>&o1,const point<fint>&o2){
    return std::sqrt(distance2(o1,o2));
}
template<typename fint>
point<db> rotate(const point<fint>&p,db ang){
    return {p.x*std::cos(ang)-p.y*std::sin(ang),
        p.x*std::sin(ang)+p.y*std::cos(ang)};
}


template<typename fint=db>
struct line{
    point<fint> s,t;
    void regular(){ // theta(t-s) in [0,pi)
        int f=fcmp(s.y,t.y);
        if(f>0) std::swap(s,t);
        if(f==0&&fcmp(s.x,t.x)>0) std::swap(s,t);
    }
    line(const point<fint>&o1,const point<fint>&o2):s(o1),t(o2){regular();}
    line(fint x1,fint y1,fint x2,fint y2):s(x1,y1),t(x2,y2){regular();}
    line(std::pair<point<fint>,point<fint>>A):s(A.first),t(A.second){regular();}
};


point<db>projection(const point<db>&p,const line<db>&l){
    point<db>a(p-l.s),b(l.t-l.s);
    return (db)dot(a,b)/distance2(l.s,l.t)*b+l.s;
}
db distance(const point<db>&p,const line<db>&l){
    return distance(point<db>(p.x,p.y),projection(p,l));
}
template<typename fint>
bool is_on_line(const point<fint>&p,const line<fint>&l){
    return fcmp(crs((l.s-p),(l.t-l.s)))==0;
}
template<typename fint>
bool is_on_segment(const point<fint>&p,const line<fint>&l){
    return is_on_line(p,l)&&
            ((fcmp(l.s.y,l.t.y)==0)?
            (fcmp(p.x,l.s.x)>=0&&fcmp(p.x,l.t.x)<=0):
            (fcmp(p.y,l.s.y)>=0&&fcmp(p.y,l.t.y)<=0));
}
template<typename fint>
bool is_parallel(const line<fint>&l1,const line<fint>&l2){
    return fcmp(crs((l1.t-l1.s),(l2.t-l2.s)))==0;
}
// -1 => infinite intersection
// 0 => no intersection
// 1 => one intersection
template<typename fint>
std::pair<int,point<db>> intersect_line(const line<fint>&l1,const line<fint>&l2){
    if(is_parallel(l1,l2)) return {is_on_line(l1.s,l2)?-1:0,{}};
    const auto& [A,B]=l1; const auto& [C,D]=l2;
    fint A1=B.y-A.y,A2=D.y-C.y;
    fint B1=A.x-B.x,B2=C.x-D.x;
    fint C1=A1*A.x+B1*A.y,C2=A2*C.x+B2*C.y;
    fint fm=A1*B2-A2*B1;
    return {1,{(db)(B2*C1-B1*C2)/fm,(db)(A1*C2-A2*C1)/fm}};
}
// -1 => infinite intersection
// 0 => no intersection
// 1 => one intersection
template<typename fint>
std::pair<int,point<db>> intersect_segment(const line<fint>&l1,const line<fint>&l2){
    if(is_parallel(l1,l2)){
        if(l1.s==l2.t) return {1,point<db>(l1.s.x,l1.s.y)};
        if(l1.t==l2.s) return {1,point<db>(l1.t.x,l1.t.y)};
        if(is_on_line(l1.s,l2)) return {-1,{}};
        return {0,{}};
    }
    if((to_left(l1.s,l1.t,l2.s)^to_left(l1.s,l1.t,l2.t))&&
        (to_left(l2.s,l2.t,l1.s)^to_left(l2.s,l2.t,l1.t))){
        return intersect_line(l1,l2);
    }
    return {0,{}};
}


int main(){
    int n; std::cin>>n;
    std::vector<point<db>>A(n);
    db ang=rand()%360*pi/180;
    for(int i=0,x,y;i<n;++i){
        std::cin>>x>>y;
        A[i]=rotate(point<int>(x,y),ang);
    }
    sort(all(A),[](const point<db>&p1,const point<db>&p2){
        return fcmp(p1.y,p2.y)==0?fcmp(p1.x,p2.x)<0:fcmp(p1.y,p2.y)<0;
    });
    db ret=1e18;
    for(int i=0;i<n-1;++i)
        for(int j=std::max(0,i-5);j<=std::min(n-1,i+5);++j)
            if(i!=j)
                ret=std::min(ret,distance(A[i],A[j]));
    std::cout<<std::fixed<<std::setprecision(4)<<ret<<'\n';
    return 0;
}