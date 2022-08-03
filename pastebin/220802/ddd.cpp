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

struct node{
    int p,x;
    bool operator<(node o)const{
        return p+x>o.p+o.x;
    }
};

int32_t main(){
    int n,q; std::cin>>n>>q;
    vc<node>A(q+1);
    for(int i=1;i<=q;++i){
        std::cin>>A[i].p>>A[i].x;
    }
    std::sort(1+all(A),
        [&](node p1,node p2){
            return p1.p<p2.p;
        });
    vc<int>ans(n+1);
    std::priority_queue<node>pq;
    int sum=0;
    for(int i=1,j=1;i<=n;++i){
        while(j<=q&&A[j].p<=i){
            pq.push(A[j]);
            sum+=A[j].p+A[j].x;
            j+=1;
        }
        while(!pq.empty()&&pq.top().p+pq.top().x<=i){
            sum-=pq.top().p+pq.top().x;
            pq.pop();
        }
        ans[i]=n-i+1+(sum-i*(int)pq.size());
    }
    for(int i=1;i<=n;++i){
        std::cout<<ans[i]<<" \n"[i==n];
    }
    return 0;
}