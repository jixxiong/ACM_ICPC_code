#pragma once

#include "head.h"
#include "point.cpp"

struct line{
    point s,t;
    void regular(){ // theta(t-s) in [0,PI)
        int f=fcmp(s.y,t.y);
        if(f>0) std::swap(s,t);
        if(f==0&&fcmp(s.x,t.x)>0) std::swap(s,t);
    }
    line(db x1=0,db y1=0,db x2=0,db y2=0):s(x1,y1),t(x2,y2){ regular(); }
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
