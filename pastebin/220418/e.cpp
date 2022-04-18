#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct point{
    ll x,y;
    bool operator<(const point&o)const{
        if(x!=o.x) return x<o.x;
        return y<o.y;
    }
    bool operator!=(const point&o)const{
        return !(o.x==x&&o.y==y);
    }
};

struct line{
    point p;
    point a;
    line(point t,point b):p(t),a(b){}
    bool operator<(const line&o)const {
        if(p!=o.p) return p<o.p;
        return a<o.a;
    }
};

ll crs(point a,point b){
    return a.x*b.y-a.y*b.x;
}

int main(){
    int n,k; std::cin>>n>>k;
    std::vector<point>A(n+1);
    for(int i=1;i<=n;++i){
        std::cin>>A[i].x>>A[i].y;
    }
    if(k==1){
        std::cout<<"Infinity"<<'\n';
        return 0;
    }
    std::set<line>st;
    for(int i=1;i<=n;++i){
        auto ori=A[i];
        std::vector<point>B;
        for(int j=1;j<=n;++j) if(j!=i) B.pb(A[j]);
        std::sort(all(B),[&](const point& a,const point& b){
            point ca={a.x-ori.x,a.y-ori.y};
            if(ca.y<0) ca.x*=-1,ca.y*=-1;
            if(ca.y==0&&ca.x<0)ca.x*=-1;
            point cb={b.x-ori.x,b.y-ori.y};
            if(cb.y<0) cb.x*=-1,cb.y*=-1;
            if(cb.y==0&&cb.x<0)cb.x*=-1;
            return crs(ca,cb)>0;
        });
        auto equ=[&](const point&a, const point&b){
            point ca={a.x-ori.x,a.y-ori.y};
            point cb={b.x-ori.x,b.y-ori.y};
            return crs(ca,cb)==0;
        };
        for(int l=0,r;l<n-1;l=r){
            r=l+1;
            while(r<n-1&&equ(B[l],B[r])) r++;
            std::vector<point>C;
            for(int j=l;j<r;++j) C.pb(B[j]);
            C.pb(ori);
            st.insert(line(*std::min_element(all(C)),*std::max_element(all(C))));
        }
    }
    for(auto [p,q]:st){
        fk("fk",p.x,p.y,q.x,q.y);
    }
    std::cout<<(int)st.size()<<'\n';
    return 0;
}