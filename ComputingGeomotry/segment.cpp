#pragma once

#include "head.h"
#include "point.cpp"
#include "line.cpp"

using seg=line;

// 返回线段 l 的长度的平方
db length_squ(seg l){
    return distance_squ(l.s,l.t);
}

// 返回线段 l 的长度
db length(seg l){
    return distance(l.s,l.t);
}

// 返回 p 是否在线段 l 上
bool is_on_seg(point p,line l){
    if(is_point(l)) return p==l.s;
    return is_on_line(p,l)&&
            ((fcmp(l.s.y,l.t.y)==0)?
            (fcmp(p.x,l.s.x)>=0&&fcmp(p.x,l.t.x)<=0):
            (fcmp(p.y,l.s.y)>=0&&fcmp(p.y,l.t.y)<=0));
}

// 返回两线段的交点数量和交点坐标
// -1 => 线段相交于无数点
// 0  => 线段无交点（平行，共线无交点...）
// 1  => 线段仅有一个交点（可能头尾相接、交错相交）
std::pair<int,point> intersect_seg(line l1,line l2){
    if(is_point(l1)){
        if(is_on_seg(l1.s,l2)) return {1,l1.s};
        return {0,{}};   
    }
    if(is_point(l2)){
        if(is_on_seg(l2.s,l1)) return {1,l2.s};
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
