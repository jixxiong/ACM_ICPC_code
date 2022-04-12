#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

const int mo=998244353;
int pw_2[1000010];

void add(int& a,int b,int c){
    a=b+c;
    if(a>=mo) a-=mo;
}

void prd(int& a,int b,int c){
    a=(ll)b*c%mo;
}

struct SegTree{
    const int n;
    std::vector<int>low,hig;
    std::vector<char>zer;
    std::vector<int>mul;
    std::vector<char>end;
    int val(int ni){
        if(end[ni]) return ~hig[ni]?pw_2[hig[ni]]:0;
        return hig[ni];
    }
    void pushup(int ni){
        add(low[ni],low[ni<<1],low[ni<<1|1]);
        add(hig[ni],val(ni<<1),val(ni<<1|1));
        zer[ni]=zer[ni<<1]&&zer[ni<<1|1];
    }
    void modi_son(int ni,int k){
        if(end[ni]){
            if(~hig[ni])hig[ni]+=k;
            return ;
        }
        prd(hig[ni],hig[ni],pw_2[k]);
        mul[ni]+=k;
    }
    void pushdown(int ni){
        modi_son(ni<<1,mul[ni]);
        modi_son(ni<<1|1,mul[ni]);
        mul[ni]=0;
    }
    void build(int ni,int nl,int nr,std::vector<int>&A){
        if(nl==nr){
            hig[ni]=std::__lg(A[nl]);
            low[ni]=A[nl]^(1<<hig[ni]);
            end[ni]=true;
            return ;
        }
        int mid=(nl+nr)>>1;
        build(ni<<1,nl,mid,A);
        build(ni<<1|1,mid+1,nr,A);
        pushup(ni);
    }
    SegTree(int n,std::vector<int>&A)
        :n(n),low((n<<2)+1),hig((n<<2)+1),zer((n<<2)+1),mul((n<<2)+1),end((n<<2)+1){
        build(1,1,n,A);
    }
    void lowbit(int ni,int nl,int nr,int l,int r){
        if(zer[ni]) return ;
        if(nl==nr){
            if(low[ni]){
                low[ni]^=low[ni]&-low[ni];
            }else{
                hig[ni]=-1;
                zer[ni]=true;
            }
            return ;
        }
        if(mul[ni]) pushdown(ni);
        int mid=(nl+nr)>>1;
        if(l<=mid) lowbit(ni<<1,nl,mid,l,r);
        if(r> mid) lowbit(ni<<1|1,mid+1,nr,l,r);
        pushup(ni);
    }
    void highbit(int ni,int nl,int nr,int l,int r){
        if(zer[ni]) return ;
        if(l<=nl&&nr<=r){
            if(nl==nr) hig[ni]++;
            else add(hig[ni],val(ni),val(ni)), mul[ni]++;
            return ;
        }
        if(mul[ni]) pushdown(ni);
        int mid=(nl+nr)>>1;
        if(l<=mid) highbit(ni<<1,nl,mid,l,r);
        if(r> mid) highbit(ni<<1|1,mid+1,nr,l,r);
        pushup(ni);
    }
    int get(int ni,int nl,int nr,int l,int r){
        if(zer[ni]) return 0;
        if(l<=nl&&nr<=r){
            int ret=0;
            add(ret,val(ni),low[ni]);
            return ret;
        }
        if(mul[ni]) pushdown(ni);
        int mid=(nl+nr)>>1;
        int ret=0;
        if(l<=mid) add(ret,ret,get(ni<<1,nl,mid,l,r));
        if(r> mid) add(ret,ret,get(ni<<1|1,mid+1,nr,l,r));
        return ret;
    }
};

int main(){
    pw_2[0]=1;
    for(int i=1;i<=1000000;++i) add(pw_2[i],pw_2[i-1],pw_2[i-1]);
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n+1);
        for(int i=1;i<=n;++i) std::cin>>A[i];
        SegTree tr(n,A);
        int q; std::cin>>q;
        while(q--){
            int op,l,r;
            std::cin>>op>>l>>r;
            if(op==1)
                std::cout<<tr.get(1,1,n,l,r)<<'\n';
            else if(op==2)
                tr.lowbit(1,1,n,l,r);
            else
                tr.highbit(1,1,n,l,r);
        }
    }
    return 0;
}

/*

1
5
5 2 2 9 7
9
2 1 5
1 2 5
3 1 3
1 1 1
1 2 2 
1 3 3
1 4 4
1 5 5
1 2 5

1
3
1 1 1
8
3 1 3
1 1 3
3 1 3
1 1 3
3 1 3
1 1 3
3 1 3
1 1 3

*/