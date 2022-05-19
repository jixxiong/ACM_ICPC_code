
#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct Fenwick{
    int n;
    std::vector<ll>A;
    Fenwick(int n):n(n),A(n+1){ }
    void add(int x,ll v){
        for(;x<=n;x+=x&-x) A[x]+=v;
    }
    ll get(int x){
        ll ret=0;
        for(;x>0;x-=x&-x) ret+=A[x];
        return ret;
    }
};

int main(){
    int n; std::cin>>n;
    std::vector<int>A(n+1);
    std::vector<Fenwick>bit(3,Fenwick(n/3+2));
    for(int i=0;i<n;++i){
        std::cin>>A[i];
        bit[i%3].add((i/3+1),A[i]);
    }
    std::vector<std::array<int,3>>L(n),R(n);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(i==j) L[i][j]=R[i][j]=1;
            else if(i<j) L[i][j]=0,R[i][j]=1;
            else L[i][j]=1,R[i][j]=2;
        }
    }
    for(int i=3;i<n;++i){
        for(int j=0;j<3;++j){
            L[i][j]=L[i-3][j]+1;
            R[i][j]=R[i-3][j]+1;
        }
    }
    auto get=[&](int l,int r){
        ll ret=0;
        int neg=(l%3+2)%3;
        for(int i=0;i<3;++i){
            auto l1=R[l][i];
            auto r1=L[r][i];
            auto f=l1<=r1?bit[i].get(r1)-bit[i].get(l1-1):0;
            if(i!=neg) ret+=f;
            else ret-=f;
        }
        return ret;
    };
    int q; std::cin>>q;
    while(q--){
        int op,l,r; std::cin>>op>>l>>r;
        if(op==1){
            --l;
            bit[l%3].add(l/3+1,-A[l]);
            A[l]=r;
            bit[l%3].add(l/3+1,r);
        }else{
            --l,--r;
            std::cout<<get(l,r)<<'\n';
        }
    }
    return 0;
}