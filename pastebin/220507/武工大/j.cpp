#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
#define int long long

struct SegTree{
    std::vector<int>A,ps;
    void pushup(int ni){
        A[ni]=A[ni<<1]+A[ni<<1|1];
    }
    void build(int ni,int nl,int nr,std::vector<int>const& arr){
        if(nl==nr) return ps[nl]=ni,A[ni]=arr[nl],void();
        int mid=(nl+nr)>>1;
        build(ni<<1,nl,mid,arr);
        build(ni<<1|1,mid+1,nr,arr);
        pushup(ni);
    }
    SegTree(std::vector<int>const&arr,int n):A(((n+1)<<2)|1),ps(n+1){ 
        build(1,1,n,arr);
    }
    void update(int x,int v){
        int idx=ps[x];
        A[idx]=v;
        idx>>=1;
        while(idx){
            pushup(idx);
            idx>>=1;
        }
    }
    int get(int ni,int nl,int nr,int x){
        if(nl==nr){
            return A[ni]>x?nl-1:nl;
        }
        int mid=(nl+nr)>>1;
        if(x<=A[ni<<1]) return get(ni<<1,nl,mid,x);
        return get(ni<<1|1,mid+1,nr,x-A[ni<<1]);
    }
};

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n+1);
        for(int i=1;i<=n;++i) std::cin>>A[i];
        SegTree seg(A,n);
        int q; std::cin>>q;
        while(q--){
            int t; std::cin>>t;
            if(t==2){
                int m; std::cin>>m;
                std::cout<<seg.get(1,1,n,m)<<' ';
                std::cout<<(seg.A[1]+m-1)/m<<'\n';
            }else{
                int x,v; std::cin>>x>>v;
                seg.update(x,v);
            }
        }
    }
    return 0;
}