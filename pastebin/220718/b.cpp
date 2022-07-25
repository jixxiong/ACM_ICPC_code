#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

using namespace std::string_literals;
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

struct Node{
    int l,r; 
    Node(int l=0,int r=0):l(l),r(r){ }
    bool operator<(Node o){
        if(l==o.l) return r>o.r;
        return l<o.l;
    }
};

int32_t main(){
    int n; std::cin>>n;
    std::vector<Node>A(n);
    for(int i=0;i<n;++i){
        int x,r; std::cin>>x>>r;
        A[i]=Node(x-r,x+r);
    }
    std::sort(all(A));
    int x=A[0].r;
    int cnt=0;
    for(auto [l,r]:A){
        if(l>x){
            cnt+=l-x;
        }
        x=std::max(x,r);
    }
    std::cout<<cnt<<'\n';
    return 0;
}