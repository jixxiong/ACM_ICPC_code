#include <bits/stdc++.h>

using namespace std::string_literals;
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


const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

struct Node{
    int x{},p{},id{};
    Node(int x=0,int p=0,int id=0):x(x),p(p),id(id){}
    bool operator<(Node o)const{
        return x<o.x;
    }
};

template<typename T> auto Vec(T init,int s){ return std::vector(s,init); }
template<typename T,typename...L> auto Vec(T init,int s,L...l){ return std::vector(s,Vec<T>(init,l...)); }

struct SparseTable:std::vector<std::vector<int>>{
    #define self (*this)
    int merge(int x,int y){
        return std::max(x,y);
    }
    SparseTable(std::vector<int>const&A,int n):std::vector<std::vector<int>>(Vec<int>(0,std::__lg(n+1)+1,n+1)){
        self[0]=A;
        for(int t=1;t<=std::__lg(n);++t){
            for(int i=1;(i+(1<<t)-1)<=n;++i){
                self[t][i]=merge(self[t-1][i],self[t-1][i+(1<<(t-1))]);
            }
        }
    }
    int get(int l,int r){
        assert(l<=r);
        int s=std::__lg(r-l+1);
        return merge(self[s][l],self[s][r-(1<<s)+1]);
    }
    #undef self
};

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,m; std::cin>>n>>m;
        auto A=Vec<Node>(Node(),n+1);
        auto t=Vec<int>(0,n+2);
        auto d=Vec<int>(0,n+2);
        for(int i=1;i<=n;++i){
            std::cin>>A[i].x>>A[i].p; A[i].id=i;
        }
        std::sort(1+all(A));
        for(int i=1;i<=n;++i){
            auto [x,p,_]=A[i];
            int b=std::lower_bound(1+all(A),Node(x-p))-A.begin();
            d[b]++; t[b]+=p-x;
            int e=std::upper_bound(1+all(A),Node(x))-A.begin();
            d[e]--; t[e]-=p-x;
            b=std::upper_bound(1+all(A),Node(x))-A.begin();
            d[b]--; t[b]+=p+x;
            e=std::upper_bound(1+all(A),Node(x+p))-A.begin();
            d[e]++; t[e]-=p+x;
        }
        for(int i=1;i<=n;++i){
            d[i]+=d[i-1];
            t[i]+=t[i-1];
        }
        for(int i=1;i<=n;++i){
            t[i]+=d[i]*A[i].x;
        }
        auto t1=t; auto t2=t;
        for(int i=1;i<=n;++i){
            t1[i]-=A[i].x;
            t2[i]+=A[i].x;
        }
        SparseTable st(t,n),st1(t1,n),st2(t2,n);
        auto ans=Vec<char>('1',n+1);
        for(int i=1;i<=n;++i){
            auto [x,p,id]=A[i];
            int b=std::lower_bound(1+all(A),Node(x-p))-A.begin();
            if(b>1&&st.get(1,b-1)>m){
                ans[id]='0';
                continue;
            } 
            int e=std::upper_bound(1+all(A),Node(x))-A.begin()-1;
            assert(b<=e);
            du(b,e);
            if(st1.get(b,e)>p-x+m){
                ans[id]='0';
                continue;
            }
            b=e+1;
            e=std::upper_bound(1+all(A),Node(x+p))-A.begin()-1;
            if(e<n&&st.get(e+1,n)>m){
                ans[id]='0';
                continue;
            }
            if(b>e) continue;
            if(st2.get(b,e)>p+x+m){
                ans[id]='0';
                continue;
            }
        }
        for(int i=1;i<=n;++i){
            std::cout<<ans[i];
        }
        std::cout<<'\n';
    }
    return 0;
}