#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct edge{
    int u,v,d;
};

struct DSU{
    std::vector<int>arr;
    DSU(int n):arr(n+1){
        for(int i=1;i<=n;++i) arr[i]=i;
    }
    int find(int x){
        return arr[x]==x?x:(arr[x]=find(arr[x]));
    }
};

int main(){
    int T; std::cin>>T;
    while(T--){
        int n,m,k; std::cin>>n>>m>>k;
        std::vector<edge>A(m);
        for(int i=0;i<m;++i){
            std::cin>>A[i].u>>A[i].v>>A[i].d;
        }
        std::sort(all(A),[&](const edge&o1,const edge&o2){
            return o1.d<o2.d;
        });
        int cnt=n;
        DSU dsu(n);
        auto merge=[&](int j){
            int u=A[j].u,v=A[j].v;
            int fu=dsu.find(u),fv=dsu.find(v);
            if(fu!=fv){
                dsu.arr[fu]=fv;
                cnt--;
            }
        };
        int ret=k==n?0:-1;
        for(int i=0;i<m;){
            merge(i++);
            while(i<m&&A[i].d==A[i-1].d)
                merge(i++);
            if(cnt==k){
                ret=A[i-1].d;
                break;
            }
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}