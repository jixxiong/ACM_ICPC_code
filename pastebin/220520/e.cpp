#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct node{
    int u,v,d;
    friend bool operator<(node const&o1,node const&o2){
        return o1.d<o2.d;
    }
};

struct DSU{
    std::vector<int>A;
    DSU(int n):A(n){
        std::iota(all(A),0);
    }
    int get(int x){
        return A[x]==x?x:(A[x]=get(A[x]));
    }
    void merge(int x,int y){
        int fx=get(x),fy=get(y);
        if(fx!=fy) A[fx]=fy;
    }
};

int main(){
    int n; std::cin>>n;
    std::vector<node>G(n);
    for(int i=0;i<n;++i){
        int x; std::cin>>x;
        G[i]=node{i,(i+1)%n,x};
    }
    std::sort(all(G));
    DSU dsu(n);
    ll ret=0;
    for(auto [u,v,d]:G){
        int fu=dsu.get(u),fv=dsu.get(v);
        if(fu!=fv){
            pr(u,v);
            dsu.merge(u,v);
            ret+=d;
        }
    }
    std::cout<<ret<<'\n';
    return 0;
}