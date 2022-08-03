#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

template<typename T>int fcmp(T x,T y=0,ld eps=EPS){ 
    if(std::abs(x-y)<EPS) return 0;
    return x<y?-1:1;
}

struct Point3{
    ll x,y,z;
    Point3(ll x=0,ll y=0,ll z=0):x(x),y(y),z(z){ }
    Point3 operator+(Point3 o){ return Point3(x+o.x,y+o.y,z+o.z); }
    Point3 operator-(Point3 o){ return Point3(x-o.x,y-o.y,z-o.z); }
    friend std::istream& operator>>(std::istream& is,Point3& o){ return is>>o.x>>o.y>>o.z; }
    friend std::ostream& operator<<(std::ostream& os,Point3& o){ return os<<o.x<<o.y<<o.z; }
    ll dot(Point3 o){ return x*o.x+y*o.y+z*o.z; }
    Point3 det(Point3 o){ return Point3(y*o.z-o.y*z,-(x*o.z-z*o.x),x*o.y-y*o.x); }
    ll len2(){ return x*x+y*y+z*z; }
    bool is_point(){ return fcmp(len2())==0; }
};

struct Line3{
    Point3 o,v;
    Line3(Point3 a=Point3(),Point3 b=Point3(),bool dif=false):o(a),v(dif?b:b-a){ }
};

struct Plane3{
    Point3 o,v1,v2;
    Plane3(Point3 a=Point3(),Point3 b=Point3(),Point3 c=Point3()):o(a),v1(b-a),v2(c-a){ }
    Point3 phi(){ return v1.det(v2); }
    bool degenerated(){ return phi().is_point(); }
    bool touch_plane(Line3 l){
        return fcmp((l.o-o).dot(phi())*(l.o+l.v-o).dot(phi()))<=0;
    }
};

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        vc<Point3>A(2*n);
        for(auto& p:A){ 
            std::cin>>p; 
        }
        int ans=0;
        for(int i=0;i<2*n;++i){
            for(int j=i+1;j<2*n;++j){
                for(int k=j+1;k<2*n;++k){
                    Plane3 p(A[i],A[j],A[k]);
                    if(p.degenerated()) continue;
                    int cnt=0;
                    for(int id=0;id<n;++id){
                        if(p.touch_plane(Line3(A[2*id],A[2*id+1]))){
                            cnt++;
                        }
                    }
                    ans=std::max(cnt,ans);
                }
            }
        }
        if(ans==0) ans=n;
        std::cout<<ans<<'\n';
    }
    return 0;
}