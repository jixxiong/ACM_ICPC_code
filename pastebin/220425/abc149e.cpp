#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int mo;

void add(int& x,int y){
    x+=y; if(x>=mo) x-=mo; if(x<0) x+=mo;
}

// struct Fenwick{
//     int n;
//     std::vector<int>arr;
//     Fenwick(int n):n(n),arr(n+1){}
//     void add(int x,int v){
//         for(;x<=n;x+=x&-x) add(arr[x],v);
//     }
//     void get(int x){
//         int ret=0;
//         for(;x>0;x-=x&-x) add(ret,arr[x]);
//         return ret;
//     }
// };

int g(int x){
    if(x<10) return 2;
    if(x<100) return 3;
    if(x<1000) return 4;
    return 5;
}

int main(){
    int n; std::cin>>n>>mo;
    std::vector<std::vector<int>>f(n+1,std::vector<int>(n+1));
    for(int i=1;i<=n;++i){
        f[g(i)][i]=26;
    }
    int ret=0;
    for(int j=1;j<=n;++j){
        for(int i=1;i<=n;++i){
            // if(g(i)==j) continue;
            if(j>3) add(f[j][i],25ll*(f[j-2][std::max(i-1,0)]   -f[j-2][std::max(i-10,0)]   +mo)%mo);
            if(j>4) add(f[j][i],25ll*(f[j-3][std::max(i-10,0)]  -f[j-3][std::max(i-100,0)]  +mo)%mo);
            if(j>5) add(f[j][i],25ll*(f[j-4][std::max(i-100,0)] -f[j-4][std::max(i-1000,0)] +mo)%mo);
            if(j>6) add(f[j][i],25ll*(f[j-5][std::max(i-1000,0)]-f[j-5][std::max(i-10000,0)]+mo)%mo);
            // std::cout<<f[j][i]<<" \n"[i==n];
        }
        add(ret,f[j][n]); 
        for(int i=1;i<=n;++i) add(f[j][i],f[j][i-1]);
    }
    // for(int i=1;i<=n;++i) assert((f[g(i)][i]-f[g(i)][i-1]+mo)%mo==26);
    std::cout<<ret<<'\n';
    return 0;
}