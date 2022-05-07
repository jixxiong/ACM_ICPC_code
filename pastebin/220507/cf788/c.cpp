#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct DSU{
    std::vector<int>fa;
    DSU(int n):fa(n){
        std::iota(all(fa),0);
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
    void merge(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx!=fy)fa[fx]=fy;
    }
};

int main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n),B(n),C(n);
        std::vector<int>pa(n),pb(n);
        for(int i=0;i<n;++i){
            std::cin>>A[i]; A[i]--;
            pa[A[i]]=i;
        }
        for(int i=0;i<n;++i){
            std::cin>>B[i]; B[i]--;
            pb[B[i]]=i;
        }
        for(int i=0;i<n;++i){
            std::cin>>C[i]; C[i]--;
        }
        std::vector<char>vis(n),gna(n),gnb(n);
        for(int i=0;i<n;++i){
            if(A[i]==B[i]) continue;
            if(~C[i]){
                vis[A[i]]=true;
                vis[B[i]]=true;
                if(C[i]==B[i]){
                    int x=i;
                    gnb[x]=true;
                    while(true){
                        x=pb[A[x]];
                        if(gnb[x]) break;
                        vis[A[x]]=true;
                        gnb[x]=true;
                    }
                }
                if(C[i]==A[i]){
                    int x=i;
                    gna[x]=true;
                    while(true){
                        x=pa[B[x]];
                        if(gna[x]) break;
                        vis[B[x]]=true;
                        gna[x]=true;
                    }
                }
            }
        }
        DSU dsu(n);
        for(int i=0;i<n;++i){
            if(vis[A[i]]||vis[B[i]]) continue;
            dsu.merge(A[i],B[i]);
        }
        std::set<int>st;
        for(int i=0;i<n;++i){
            if(dsu.find(i)==i) continue;
            st.insert(dsu.find(i));
        }
        int ret=1,pw=(int)st.size();
        while(pw){
            ret=ret*2%1000000007;
            pw--;
        }
        std::cout<<ret<<'\n';
    }
    return 0;
}