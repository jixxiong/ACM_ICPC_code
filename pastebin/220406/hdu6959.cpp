#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct Fenwick:std::vector<int>{
    int n; std::vector<int>&p;
    Fenwick(int n):std::vector<int>(n+1),n(n),p(*this){}
    void add(int x,int v){
        for(;x<=n;x+=x&-x)p[x]+=v; 
    }
    int get(int x){
        int ret=0;
        for(;x>0;x-=x&-x)ret+=p[x];
        return ret;
    }
};

struct Query{
    int l,r;
    int d,u;
    int idx;
};

int main(){
    int T; std::cin>>T;
    while(T--){
        int n,q; std::cin>>n>>q;
        std::vector<int>A(n+1);
        for(int i=1;i<=n;++i) {
            std::cin>>A[i];
            A[i]++;
        }
        std::vector<Query>qry(q);
        for(int i=0;i<q;++i) {
            std::cin>>qry[i].l>>qry[i].d>>qry[i].r>>qry[i].u;
            qry[i].u++,qry[i].d++;
            qry[i].idx=i;
        }
        const int BLOCKSIZE=500;
        std::sort(all(qry),[](const Query&o1,const Query&o2){
            return o1.l/BLOCKSIZE==o2.l/BLOCKSIZE?o1.r<o2.r:o1.l<o2.l;
        });
        std::vector<int>cnt(100002);
        Fenwick bit(100001);
        auto add=[&](int x){
            if(cnt[x]++==0) bit.add(x,1);
        };
        auto del=[&](int x){
            if(--cnt[x]==0) bit.add(x,-1);
        };
        std::vector<int>ans(q);
        for(int l=1,r=0,i=0;i<q;++i){
            int lm=qry[i].l,rm=qry[i].r;
            int d=qry[i].d,u=qry[i].u;
            while(l<lm) del(A[l++]);
            while(l>lm) add(A[--l]);
            while(r<rm) add(A[++r]);
            while(r>rm) del(A[r--]);
            ans[qry[i].idx]=bit.get(u)-bit.get(d-1);
        }
        for(int i=0;i<q;++i)
            std::cout<<ans[i]<<'\n';
    }
    return 0;
}