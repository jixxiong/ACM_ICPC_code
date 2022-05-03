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
    std::vector<int>A;
    Fenwick(int n):n(n),A(n+1){ }
    void add(int x,int v){
        for(;x<=n;x+=x&-x) A[x]+=v;
    }
    int get(int x){
        int ret=0;
        for(;x;x-=x&-x) ret+=A[x];
        return ret;
    }
};

int main(){
    int n,m,q; std::cin>>n>>m>>q;
    auto get_idx=[&](int x,int y){
        return (y-1)*n+x;
    };
    std::vector<char>A(n*m+1);
    Fenwick bit(n*m);
    int tot=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            char ch; std::cin>>ch;
            int idx=get_idx(i,j);
            if(ch=='.') A[idx]=1,bit.add(idx,1);
            else A[idx]=0,tot++;
        }
    }
    while(q--){
        int x,y; std::cin>>x>>y;
        int idx=get_idx(x,y);
        if(A[idx]==1) bit.add(idx,-1),tot++;
        else bit.add(idx,1),tot--;
        A[idx]^=1;
        std::cout<<bit.get(tot)<<'\n';
    }
    return 0;
}