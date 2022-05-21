#pragma once

#include "head.h"
#include "point.h"
#include "line.h"
#include "segment.h"

// 凸包的定义（一个 point 的数组，一般要求按照和 ltl 的极角序逆时针排序）
using polygon=std::vector<point>;

// 返回 p 是不是在凸包 g 的顶点上
bool is_on_vertex(point p,polygon const& g){
    for(const auto& pnt:g) if(p==pnt) return true;
    return false;
}

// 返回 p 是不是在凸包 g 的边上
bool is_on_edge(point p,polygon const& g){
    int n=(int)g.size();
    for(int i=0;i<n;++i)
        if(is_on_seg(p,{g[i],g[(i+1)%n]})) return true;
    return false;
}

// 返回 p 是不是在凸包 g 的内部
bool is_inside_poly(point p,polygon const& g){
    if(is_on_edge(p,g)) return false;
    int n=(int)g.size();
    for(int i=0;i<n;++i)
        if(!to_left(p,g[i],g[(i+1)%n])) return false;
    return true;
}

// 返回 p 是不是在凸包 g 的外部
bool is_outside_poly(point p,polygon const& g){
    return !(is_on_edge(p,g)||is_inside_poly(p,g));
}

// 返回凸包 g 的面积
db area(polygon const& g){
    db ret=0;
    int n=(int)g.size();
    for(int i=0;i<n;++i)
        ret+=crs(g[i],g[(i+1)%n])/2;
    return fcmp(ret)<0?-ret:ret;
}

// 返回凸包 g 的周长
db length(polygon const& g){
    db ret=0;
    int n=(int)g.size();
    if(n==2)
        return distance(g[0],g[1]);
    for(int i=0;i<n;++i)
        ret+=distance(g[i],g[(i+1)%n]);
    return ret;
}

// 返回 A 中的点所构成的凸包
polygon get_convex_hull(std::vector<point> A){
    sort_by_ltl(A);
    A.erase(std::unique(all(A)),A.end());
    if(A.size()==1) return A;
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
db diameter_squ(polygon const& g){
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
db diameter(polygon const& g){
    return std::sqrt(diameter_squ(g));
}
