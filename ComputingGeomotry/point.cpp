#pragma once

#include "head.h"

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
    for(int i=0;i<n;++i) A[i]=rotate(A[i],ang);
    // 按照 x 从小到大排，然后  y 从小到大排
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
