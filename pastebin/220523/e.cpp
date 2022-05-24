#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

std::array<ll,4> operator+(std::array<ll,4> const&o1, std::array<ll,4>const& o2){
    return std::array<ll,4>{
        std::min(o1[0]+o2[0],o1[3]+o2[2]),
        std::min(o1[2]+o2[3],o1[1]+o2[1]),
        std::min(o1[2]+o2[0],o1[1]+o2[2]),
        std::min(o1[0]+o2[3],o1[3]+o2[1]),
    };
}

struct SegTree{
    using node=std::array<ll,4>;
    std::vector<node>arr;
    std::vector<int> const &dx;
    std::vector<int> const &dy;
    void pushup(int ni){
        arr[ni]=arr[ni<<1]+arr[ni<<1|1];
    }
    void build(int ni,int nl,int nr){
        if(nl==nr){
            arr[ni]=node{
                std::abs(dx[nl]-dx[nl-1])+1,
                std::abs(dy[nl]-dy[nl-1])+1,
                2*nl-dy[nl-1]-dx[nl]+1,
                2*nl-dx[nl-1]-dy[nl]+1
            };
            return ;
        }
        int mid=(nl+nr)>>1;
        build(ni<<1,nl,mid);
        build(ni<<1|1,mid+1,nr);
        pushup(ni);
    }
    SegTree(int n,std::vector<int> const &dx,std::vector<int>&dy):arr(n<<2|3),dx(dx),dy(dy){
        build(1,1,n-1);
    }
    node get(int ni,int nl,int nr,int l,int r){
        if(l<=nl&&nr<=r) return arr[ni];
        int mid=(nl+nr)>>1;
        if(l<=mid){
            node res=get(ni<<1,nl,mid,l,r);
            if(r>mid) res=res+get(ni<<1|1,mid+1,nr,l,r);
            return res;
        }else{
            return get(ni<<1|1,mid+1,nr,l,r);
        }
    }
};

int32_t main(){
    int n; std::cin>>n;
    std::vector<int>dx(n+1),dy(n+1);dx[0]=1,dy[0]=1;
    for(int i=1,t;i<n;++i){
        std::cin>>t>>dy[i]>>dx[i]>>t;
    }
    SegTree seg(n,dx,dy);
    int q; std::cin>>q;
    while(q--){
        int x1,y1,x2,y2; std::cin>>x1>>y1>>x2>>y2;
        auto l1=std::max(x1,y1),l2=std::max(x2,y2);
        if(l1>l2) std::swap(x1,x2),std::swap(y1,y2),std::swap(l1,l2);
        auto get=[](int x1,int y1,int x2,int y2){
            auto l1=std::max(x1,y1),l2=std::max(x2,y2);
            assert(l1==l2);
            auto dx1=y1==l1?x1:2*l1-y1;
            auto dx2=y2==l1?x2:2*l2-y2;
            return std::abs(dx1-dx2);
        };
        if(l1==l2){
            std::cout<<get(x1,y1,x2,y2)<<'\n';
        }else if(l1+1==l2){
            auto res=std::min({
                get(x1,y1,dx[l1],l1)+get(dx[l1],l2,x2,y2)+1,
                get(x1,y1,l1,dy[l1])+get(l2,dy[l1],x2,y2)+1,
            }); 
            std::cout<<res<<'\n';   
        }else{
            auto pt=seg.get(1,1,n-1,l1+1,l2-1);
            auto res=std::min({
                pt[0]+get(x1,y1,dx[l1],l1)+get(x2,y2,dx[l2-1],l2)+1,
                pt[1]+get(x1,y1,l1,dy[l1])+get(x2,y2,l2,dy[l2-1])+1,
                pt[2]+get(x1,y1,l1,dy[l1])+get(x2,y2,dx[l2-1],l2)+1,
                pt[3]+get(x1,y1,dx[l1],l1)+get(x2,y2,l2,dy[l2-1])+1,
            });
            std::cout<<res<<'\n';
        }
    }
    return 0;
}
