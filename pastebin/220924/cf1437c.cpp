#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
#define ld long double
#define ll long long
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
template<class T>using vc    =std::vector<T>;
template<class T>using vvc   =vc<vc<T>>;
template<class T>using vvvc  =vc<vvc<T>>;
template<class T>using vvvvc =vc<vvvc<T>>;
template<class T>using vvvvvc=vc<vvvvc<T>>;
template<class T>auto  vcc   (i32 _1=0,i32 _2=0,const T&init=T()){ return vvc<T>(_1,vc<T>(_2,init)); }
template<class T>auto  vccc  (i32 _1=0,i32 _2=0,i32 _3=0,const T&init=T()){ return vvvc<T>(_1,vcc(_2,_3,init)); }
template<class T>auto  vcccc (i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,const T&init=T()){ return vvvvc<T>(_1,vccc(_2,_3,_4,init)); }
template<class T>auto  vccccc(i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,i32 _5=0,const T&init=T()){ return vvvvvc<T>(_1,vcccc(_2,_3,_4,_5,init)); }
template<class T>T INF(){ return std::numeric_limits<T>::max(); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;

struct KM {
    i32 n,nn,mm;
	i64 res;
	i64 const inf;
    vc<i32> mx,my,pre;
    vc<char> visx,visy;
    vc<i64> lx,ly,slack;
    vvc<i64> g;
    std::queue<i32> q;
    KM(i32 n_,i32 m_):
		n(std::max(n_,m_)),nn(n_),mm(m_),res(0),
		inf(INF<i64>()),mx(n,-1),my(n,-1),pre(n),
		visx(n),visy(n),lx(n,-inf),ly(n),slack(n),
        g(vcc<i64>(n,n)) {

	}
    void add(i32 u,i32 v,i64 w) {
		// u -> the u-th node in set A
		// v -> the v-th node in set B
        g[u][v]=w;
    }
    bool check(i32 v) {
        visy[v]=true;
        if(my[v]!=-1) {
            q.push(my[v]);
            visx[my[v]]=true;
            return false;
        }
        while(v!=-1) {
            my[v]=pre[v];
            std::swap(v,mx[pre[v]]);
        }
        return true;
    }
    void argument(i32 i) {
        std::queue<i32>().swap(q);
        q.push(i);
        visx[i]=true;
        while(true) {
            while(!q.empty()) {
                i32 u=q.front();
                q.pop();
                for(i32 v=0;v<n;v++) {
                    if(!visy[v]) {
                        i64 delta=lx[u]+ly[v]-g[u][v];
                        if(slack[v]>=delta) {
                            pre[v]=u;
                            if(delta) {
                                slack[v]=delta;
                            } else if(check(v)) {
                                return;
                            }
                        }
                    }
                }
            }
            i64 a=inf;
            for(i32 j=0;j<n;j++) {
                if(!visy[j]) {
                    a=std::min(a,slack[j]);
                }
            }
            for(i32 j=0;j<n;j++) {
                if(visx[j]) {
                    lx[j]-=a;
                }
                if(visy[j]) {
                    ly[j]+=a;
                } else {
                    slack[j]-=a;
                }
            }
            for(i32 j=0;j<n;j++) {
                if(!visy[j]&&slack[j]==0&&check(j)) {
                    return;
                }
            }
        }
    }
    int solve() {
        for(i32 i=0;i<n;i++) {
            for(i32 j=0;j<n;j++) {
                lx[i]=std::max(lx[i],g[i][j]);
            }
        }
        for(i32 i=0;i<n;i++) {
            std::fill(slack.begin(),slack.end(),inf);
            std::fill(visx.begin(),visx.end(),false);
            std::fill(visy.begin(),visy.end(),false);
            argument(i);
        }
        for(i32 i=0;i<n;i++) {
            if(g[i][mx[i]]>0) res+=g[i][mx[i]];
            else mx[i]=-1;
        }
        return res;
    }
};

int32_t main(){
    i32 T; std::cin>>T;
    while(T--){
        i32 n; std::cin>>n;
        vc<i32>A(n+1);
        for(i32 i=1;i<=n;++i){
            std::cin>>A[i];
        }
        KM km(2*n,n);
        for(i32 i=1;i<=n;++i){
            for(i32 j=1;j<=2*n;++j){
                km.add(i-1,j-1,2*n-std::abs(j-A[i]));
            }
        }
        std::cout<<2*n*n-km.solve()<<'\n';
    }
    return 0;
}
