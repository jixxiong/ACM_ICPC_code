#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;

struct point{
    ld x,y;
    point operator+(point p){
        return {p.x+x,p.y+y};
    }
    point operator-(point p){
        return {x-p.x,y-p.y};
    }
    point operator*(ld d){
        return {x*d,y*d};
    }
    ld dot(point p){
        return x*p.x+y*p.y;
    }
    ld det(point p){
        return x*p.y-y*p.x;
    }
};

int cmp(ld x,ld y){
    if(fabs(x-y)<1e-12) return 0;
    return x<y?-1:1;
}

bool on_seg(point A,point B,point C){ // C in AB
    return cmp((A-C).det(B-C),0)==0&&cmp((A-C).dot(B-C),0)<=0;
}

std::pair<bool,point> intersect(point A, point B, point C, point D){
    point ret=A+(B-A)*(((D-C).det(C-A))/((D-C).det(B-A)));
    return {on_seg(C,D,ret),ret};
}

int main(){
    int n,m; std::cin>>n>>m;
    point s,t;
    std::cin>>s.x>>s.y>>t.x>>t.y;
    std::vector<point>A(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i].x>>A[i].y;
    }
    while(m--){
        int h,k; std::cin>>h>>k; h--;
        std::vector<point>B; B.reserve(n-1);
        for(int i=0;i<n;++i){
            if(i==h) continue;
            auto [flg,pnt]=intersect(A[i],A[h],s,t);
            if(flg){
                B.push_back(pnt);
            }
        }
        if((int)B.size()<k){
            std::cout<<"-1\n";
            continue;
        }
        std::nth_element(B.begin(),B.begin()+k-1,B.end(),[&](const point&o1,const point&o2){
            if(s.x!=t.x) return cmp(s.x,t.x)<0?cmp(o1.x,o2.x)<0:cmp(o1.x,o2.x)>0;
            return cmp(s.y,t.y)<0?cmp(o1.y,o2.y)<0:cmp(o1.y,o2.y)>0;
        });
        auto [x,y]=*(B.begin()+k-1);
        std::cout<<std::fixed<<std::setprecision(7)<<x<<' '<<y<<'\n';
    }
    return 0;
}