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

struct SGT{
    std::vector<ll>mx, mn, sm;
    void pushup(int ni){
        mx[ni]=std::max(mx[ni<<1],mx[ni<<1|1]);
        mn[ni]=std::min(mn[ni<<1],mn[ni<<1|1]);
        sm[ni]=sm[ni<<1]+sm[ni<<1|1];
    }
    bool zero(int ni){
        return mx[ni]==mn[ni];
    }
    void pushdown(int ni,int nl,int mid,int nr){
        if(zero(ni)){
            mx[ni<<1]=mx[ni<<1|1]=mn[ni<<1]=mn[ni<<1|1]=mx[ni];
            sm[ni<<1]=(ll)mx[ni]*(mid-nl+1);
            sm[ni<<1|1]=(ll)mx[ni]*(nr-mid);
        }
    }
    void build(int ni,int nl,int nr, std::vector<int> const & A){
        if(nl == nr){
            mx[ni] = mn[ni] = sm[ni] = A[nl];
            return ;
        }
        int mid=(nl+nr)>>1;
        build(ni<<1,nl,mid, A);
        build(ni<<1|1, mid+1, nr, A);
        pushup(ni);
    }
    SGT(std::vector<int> const & A, int n):mx(n<<2|3), mn(n<<2|3), sm(n<<2|3) {
        build(1,1,n, A);
    }
    void upd1(int ni,int nl,int nr,int l,int r, int x){
        if(l<=nl&&nr<=r&&zero(ni)){
            mx[ni]=mn[ni]=mx[ni]/x;
            sm[ni]=(ll)(nr-nl+1)*mx[ni];
            return ;
        }
        int mid=(nl+nr)>>1;
        pushdown(ni,nl,mid,nr);
        if(l<=mid) upd1(ni<<1,nl,mid,l,r,x);
        if(r >mid) upd1(ni<<1|1,mid+1,nr,l,r,x);
        pushup(ni);
    }
    void upd2(int ni,int nl,int nr,int l,int r, int x){
        if(l<=nl&&nr<=r){
            mx[ni]=mn[ni]=x; 
            sm[ni]=(ll)(nr-nl+1)*x;
            return;
        }
        int mid=(nl+nr)>>1;
        pushdown(ni,nl,mid,nr);
        if(l<=mid) upd2(ni<<1,nl,mid,l,r,x);
        if(r >mid) upd2(ni<<1|1,mid+1,nr,l,r,x);
        pushup(ni);
    }
    int inter(int nl,int nr,int l,int r){
        if(nr<l||r<nl) return 0;
        if(l<=nl&&nr<=r) return nr-nl+1;
        if(nl<=l&&r<=nr) return r-l+1;
        if(l<=nl) return r-nl+1;
        return nr-l+1;  
    }
    ll get(int ni,int nl,int nr,int l,int r){
        if(zero(ni)){
            return (ll)mx[ni]*inter(nl,nr,l,r);
        }
        ll s=0;
        int mid=(nl+nr)>>1;
        pushdown(ni,nl,mid,nr);
        if(l<=mid) s+=get(ni<<1,nl,mid,l,r);
        if(r> mid) s+=get(ni<<1|1,mid+1,nr,l,r);
        return s;
    }
};

int32_t main(){
    int n,q; std::cin>>n>>q;
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    SGT sgt(A,n);
    while(q--){
        int op,l,r,x;
        std::cin>>op>>l>>r;
        if(op==3){
            std::cout<<sgt.get(1,1,n,l,r)<<'\n';
        }else{
            std::cin>>x;
            if(op==1){
                sgt.upd1(1,1,n,l,r,x);
            }else{
                sgt.upd2(1,1,n,l,r,x);
            }
        }
    }
    return 0;
}