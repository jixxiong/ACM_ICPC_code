#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int f[20000];
int g[20000];
int q[20000];

int main(){
    int n,m; std::cin>>n>>m;
    int front,tail;
    for(int i=1;i<=n;++i){
        int v,w,l; std::cin>>v>>w>>l;
        std::copy(f,f+m+1,g);
        for(int r=0;r<v;++r){
            front=0,tail=-1;
            for(int j=r;j<=m;j+=v){
                while(tail>=front&&q[front]<j-l*v) front++;
                if(tail>=front) f[j]=std::max(f[j],g[q[front]]+(j-q[front])/v*w);
                while(tail>=front&&g[q[tail]]-(q[tail]-r)/v*w<=g[j]-(j-r)/v*w) tail--;
                q[++tail]=j;
            }
        }
    }
    std::cout<<f[m]<<'\n';
    return 0;
}