#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
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
    friend point operator*(db k,point o){ return o*k; }
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

// 凸包定义
using polygon=std::vector<point>;

// 返回 A 中的点所构成的凸包
polygon get_convex_hull(std::vector<point> A){
    sort_by_ltl(A);
    A.erase(std::unique(all(A)),A.end());
    if(A.size()==1) return A;
    std::vector<int>B{0,1};
    std::vector<int>fck;
    for(int i=2;i<(int)A.size();++i){
        while(((int)B.size()>=2)&&
            (!to_left(A[*next(B.rbegin())],A[B.back()],A[i]))){
            fck.pb(B.back());
            B.pop_back();
        }
        B.pb(i);
    }
    
    polygon ret; ret.reserve(B.size());
    std::for_each(all(B),[&](int i){ret.pb(A[i]);});
    return ret;
}

// 返回凸包 g 的面积
db area(polygon const& g){
    db ret=0;
    int n=(int)g.size();
    for(int i=0;i<n;++i)
        ret+=crs(g[i],g[(i+1)%n])/2;
    return fcmp(ret)<0?-ret:ret;
}

int main(){
    int n; std::cin>>n;
    std::vector<point>A(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i].x>>A[i].y;
    }
    return 0;
}