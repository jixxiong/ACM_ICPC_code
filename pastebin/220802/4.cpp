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

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
ll const mod=998244353;

template<typename T>
int fcmp(T x,T y=0,ld eps=EPS){
    if(std::abs(x-y)<eps) return 0;
    return x<y?-1:1;
}

template<typename T>
int sgn(T x,ld eps=EPS){
    return fcmp(x);
}

struct Point{
    ll x,y;
    Point(ll x=0,ll y=0):x(x),y(y){ }
    Point operator+(Point o){ return Point(x+o.x,y+o.y); }
    Point operator-(Point o){ return Point(x-o.x,y-o.y); }
    ll dot(Point o){ return x*o.x+y*o.y; }
    ll det(Point o){ return x*o.y-y*o.x; }
};

struct Line{
    Point u,v;
    Line(Point u=Point(),Point v=Point()):u(u),v(v-u){ }
    friend bool intersect(Line l1, Line l2){
        auto a=l1.u,b=l1.u+l1.v,c=l2.u,d=l2.u+l2.v;
        if(fcmp(std::min(a.x,b.x),std::max(c.x,d.x))>0||
            fcmp(std::min(a.y,b.y),std::max(c.y,d.y))>0||
            fcmp(std::min(c.x,d.x),std::max(a.x,b.x))>0||
            fcmp(std::min(c.y,d.y),std::max(a.y,b.y))>0){
            return false;
        }
        return sgn((b-a).det(c-a))*sgn((b-a).det(d-a))<=0&&
            sgn((d-c).det(a-c))*sgn((d-c).det(b-c))<=0;
    }
};


int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,m; std::cin>>n>>m;
        vc<Point>A(n);
        vc<std::bitset<400>>f(1<<n);
        for(int i=0;i<n;++i){
            std::cin>>A[i].x>>A[i].y;
        }
        vc<Point>rect(4*m);
        for(int i=0;i<4*m;++i){
            std::cin>>rect[i].x>>rect[i].y;
        }
        vvc<int>G(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<4*m;++j){
                Line l(A[i],rect[j]);
                bool ok=true;
                for(int k=0;k<m;++k){
                    vc<Line>ls;
                    if(4*k!=j&&4*k+1!=j) ls.pb(Line(rect[4*k],rect[4*k+1]));
                    if(4*k+1!=j&&4*k+2!=j) ls.pb(Line(rect[4*k+1],rect[4*k+2]));
                    if(4*k+2!=j&&4*k+3!=j) ls.pb(Line(rect[4*k+2],rect[4*k+3]));
                    if(4*k+3!=j&&4*k!=j) ls.pb(Line(rect[4*k+3],rect[4*k]));
                    for(auto line:ls){
                        if(intersect(l,line)){
                            ok=false;
                            break;
                        }
                    }
                }
                if(ok){
                    f[1<<i].set(j);
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                Line l(A[i],A[j]);
                bool ok=true;
                for(int k=0;k<m;++k){
                    vc<Line>ls;
                    ls.pb(Line(rect[4*k],rect[4*k+1]));
                    ls.pb(Line(rect[4*k+1],rect[4*k+2]));
                    ls.pb(Line(rect[4*k+2],rect[4*k+3]));
                    ls.pb(Line(rect[4*k+3],rect[4*k]));
                    for(auto line:ls){
                        if(intersect(l,line)){
                            ok=false;
                            break;
                        }
                    }
                }
                if(ok){
                    G[i].pb(j);
                    G[j].pb(i);
                }
            }
        }
        int ans=n+1;
        for(int i=1;i<(1<<n);++i){
            int cnt=0;
            for(int j=0;j<(n);++j){
                if((i>>j)&1){
                    bool ok=false;
                    for(auto v:G[j]){
                        if((i>>v)&1){
                            ok=true;
                            break;
                        }
                    }
                    cnt++;
                    if(ok) f[i]|=f[i^(1<<j)];
                }
            }
            if((int)f[i].count()==4*m){
                ans=std::min(cnt,ans);
            }
        }
        if(ans==n+1) std::cout<<"No Solution!"<<'\n';
        else std::cout<<ans<<'\n';
    }
    return 0;
}