#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define er(args...) void()
#else
    #define vwn(x) #x"=",x,"\n"
    void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
    #define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct SegTree{
    struct node{
        ll sum; int ls,rs;
        node(ll s,int ls=0,int rs=0):sum(s),ls(ls),rs(rs){} 
    };
    std::vector<node>arr;
    std::vector<int>root_idx;
    int new_node(ll sum){
        arr.pb(node(sum));
        return arr.size();
    }
    int build(int nl,int nr){
        if(nl==nr) return ;
        int mid=(nl+nr)>>1;
        int id=new_node(0);
        arr[id].ls=build(nl,mid);
        arr[id].rs=build(mid+1,nr);
    }
    SegTree(int n){
        arr.reserve(n<<2|3);
        build(1,n);
    }
    void add(int fa,int nl,int nr,int x){
        
    }
    int add(int l,int r,int x){

    }
};

int32_t main(){
    int n,m,q; std::cin>>n>>m>>q;
    
    return 0;
}