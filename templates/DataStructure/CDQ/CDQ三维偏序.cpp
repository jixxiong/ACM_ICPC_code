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
template<class T> auto vcc   (i32 _1=0,i32 _2=0,const T&init=T()){ return vvc<T>(_1,vc<T>(_2,init)); }
template<class T> auto vccc  (i32 _1=0,i32 _2=0,i32 _3=0,const T&init=T()){ return vvvc<T>(_1,vcc(_2,_3,init)); }
template<class T> auto vcccc (i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,const T&init=T()){ return vvvvc<T>(_1,vccc(_2,_3,_4,init)); }
template<class T> auto vccccc(i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,i32 _5=0,const T&init=T()){ return vvvvvc<T>(_1,vcccc(_2,_3,_4,_5,init)); }
template<class T>T INF(){ return std::numeric_limits<T>::max(); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;

// P3810

struct node{
    i32 x{},y{},z{},cnt{},tag{},*ans{};
    bool operator==(node const&o)const{
        return x==o.x&&y==o.y&&z==o.z;
    }
};

int32_t main(){
    i32 n,k; std::cin>>n>>k;
    vc<node>A(n),B(n),C(n);
    vc<i32>ans(n);
    for(i32 i=0;i<n;++i){
        std::cin>>A[i].x>>A[i].y>>A[i].z;
        A[i].ans=ans.data()+i;
    }
    std::sort(all(A),[](node const&o1,node const&o2)->bool{
        if(o1.x!=o2.x) return o1.x<o2.x;
        if(o1.y!=o2.y) return o1.y<o2.y;
        return o1.z<o2.z;
    });
    for(i32 i=n-2;i>=0;--i){ // 点相同怎么办P2345
        if(A[i]==A[i+1]) *A[i].ans=*A[i+1].ans+1;
    }
    std::function<void(i32,i32)>dfs1=[&](i32 l,i32 r)->void{
        if(l>=r) return ;
        i32 mid=(l+r)>>1;
        dfs1(l,mid);
        dfs1(mid+1,r);
        for(i32 i=l,j=l,k=mid+1,cnt=0;i<=r;++i){
            if((j<=mid)&&(k>r||B[j].z<=B[k].z)){
                C[i]=B[j++];
                cnt+=C[i].tag;
            }else{
                C[i]=B[k++];
                if(!C[i].tag) *C[i].ans+=cnt;
            }
        }
        for(i32 i=l;i<=r;++i) B[i]=C[i];
    };
    std::function<void(i32,i32)>dfs=[&](i32 l,i32 r)->void{
        if(l>=r) return ;
        i32 mid=(l+r)>>1;
        dfs(l,mid);
        dfs(mid+1,r);
        for(i32 i=l,j=l,k=mid+1;i<=r;++i){
            if((j<=mid)&&(k>r||A[j].y<=A[k].y)){
                B[i]=A[j++];
                B[i].tag=1;
            }else{
                B[i]=A[k++];
                B[i].tag=0;
            }
        }
        for(i32 i=l;i<=r;++i) A[i]=B[i];
        dfs1(l,r);
    };
    dfs(0,n-1);
    vc<i32>d(n);
    for(auto x:ans){
        d[x]++;
    }
    for(i32 i=0;i<n;++i){
        std::cout<<d[i]<<'\n';
    }
    return 0;
}
