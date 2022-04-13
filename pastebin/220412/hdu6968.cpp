#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int T; std::cin>>T;
    for(int _=1;_<=T;++_){
        int n; std::cin>>n;
        std::map<std::string,int>mp;
        for(int i=1;i<=n;++i){
            std::string s; std::cin>>s;
            mp[s]=i;
        }
        int m; std::cin>>m;
        std::vector<std::vector<int>>f(n+1,std::vector<int>(101,0x3f3f3f3f));
        for(int i=1;i<=n;++i) f[i][0]=0;
        for(int i=1;i<=m;++i){
            std::string s; int sc,dy;
            std::cin>>s>>sc>>dy;
            int id=mp[s];
            for(int j=99;j>=0;--j){
                f[id][std::min(100,j+sc)]=std::min(f[id][std::min(100,j+sc)],f[id][j]+dy);
            }
        }
        std::vector<int>tk;
        for(int i=1;i<=n;++i){
            int cst=0x3f3f3f3f;
            for(int j=60;j<=100;++j){
                cst=std::min(cst,f[i][j]);
            }
            tk.pb(cst);
        }
        int t,p; std::cin>>t>>p;
        std::sort(all(tk));
        ll cst=0;
        for(int i=0;i<n-p;++i)cst+=tk[i];
        if(cst>t){
            std::cout<<"-1\n";
            continue;
        }
        std::vector<std::vector<int>>g(t+1,std::vector<int>(p+1));
        std::vector<std::vector<int>>h(t+1,std::vector<int>(p+1));
        for(int i=1;i<=n;++i){
            if(i>1){
                h=g;
                for(auto&x:g) std::fill(all(x),0);
            }
            for(int j=t;j>=0;--j){
                for(int k=0;k<60;++k){
                    for(int q=1;q<=p;++q){
                        if(j>=f[i][k]) g[j][q]=std::max(g[j][q],h[j-f[i][k]][q-1]+k);
                    }
                }
                for(int k=60;k<=100;++k){
                    for(int q=0;q<=p;++q){
                        if(j>=f[i][k]) g[j][q]=std::max(g[j][q],h[j-f[i][k]][q]+k);
                    }
                }
            }
        }
        int ret=0;
        for(int i=0;i<=p;++i) ret=std::max(ret,g[t][i]);
        std::cout<<ret<<'\n';
    }
    return 0;
}