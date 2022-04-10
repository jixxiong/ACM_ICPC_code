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
    ld crs(point p){
        return x*p.y-y*p.x;
    }
};

int cmp(ld x,ld y){
    if(fabs(x-y)<1e-12) return 0;
    return x<y?-1:1;
}

bool on_seg(point A,point B,point C){ // C in AB
    return cmp((A-C).crs(B-C),0)==0&&cmp((A-C).dot(B-C),0)<=0;
}

point intersect(point A, point B, point C, point D){
    return A+(B-A)*(((D-C).crs(C-A))/((D-C).crs(B-A)));
}

// point intersect(point A,point B,point C,point D){
//     ld A1=B.y-A.y,B1=A.x-B.x,C1=A1*A.x+B1*A.y,A2=D.y-C.y,B2=C.x-D.x,C2=A2*C.x+B2*C.y,r=A1*B2-A2*B1;
//     return {(B2*C1-B1*C2)/r,(A1*C2-A2*C1)/r};
// }

int main(){
    int n,m; std::cin>>n>>m;
    point s,t;
    std::cin>>s.x>>s.y>>t.x>>t.y;
    std::vector<point>A(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i].x>>A[i].y;
    }
    std::vector<std::vector<point>>B(n);
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(cmp((t-s).crs(A[j]-A[i]),0)==0) continue;
            if(cmp((A[j]-A[i]).crs(s-A[i])*(A[j]-A[i]).crs(t-A[i]),0)>=0) continue;
            auto pnt=intersect(A[i],A[j],s,t);
            assert(pnt.x>=-1e6-1&&pnt.x<=1e6+1);
            assert(pnt.y>=-1e6-1&&pnt.y<=1e6+1);
            B[i].pb(pnt),B[j].pb(pnt);
        }
    }
    for(int i=0;i<n;++i) {
        sort(all(B[i]),[&](const point&o1,const point&o2){
            if(cmp(s.x,t.x)!=0) return cmp(s.x,t.x)<0?cmp(o1.x,o2.x)<0:cmp(o1.x,o2.x)>0;
            return cmp(s.y,t.y)<0?cmp(o1.y,o2.y)<0:cmp(o1.y,o2.y)>0;
        });
    }
    while(m--){
        int h,k; std::cin>>h>>k; h--;
        if(k>(int)B[h].size()) std::cout<<"-1\n";
        else std::cout<<std::fixed<<std::setprecision(8)<<B[h][k-1].x<<" "<<B[h][k-1].y<<'\n';
    }
    return 0;
}