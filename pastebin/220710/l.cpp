#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define de(...) void()
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){std::cerr<<"[DEBUG: LINE "<<__LINE__<<"]: ";_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int n=16;

struct Node{
    std::string s;
    char l;
    Node(int n):s(n+4,0),l(0){}
    Node(Node const& o):s(o.s),l(l){}
    bool operator<(Node const& o)const{
        if(s!=o.s) return s<o.s;
        return l<o.l;
    }
    bool empty(){
        for(auto x:s){
            if(x==0) return 0;
        }
        return 1;
    }
};

std::map<Node,char>mp;

char dfs(Node const& nd){
    if(mp.find(nd)!=mp.end()) return mp[nd];
    if(nd.empty()){
        return mp[nd]=-1;
    }
    for(int i=1;i<=n;++i){
        
    }
}

int32_t main(){
    
    return 0;
}