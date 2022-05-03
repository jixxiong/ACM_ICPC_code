#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    auto win=[](char x,char y){
        return (x=='0'&&y=='2')||(x=='2'&&y=='5')||(x=='5'&&y=='0');
    };
    auto get=[win](char x,char y){
        if(win(x,y)) return 1;
        if(win(y,x)) return -1;
        return 0;
    };
    int K; std::cin>>K;
    std::string s,t; std::cin>>s>>t;
    int n=s.length(),m=t.length();
    int p=n*m/std::__gcd(n,m);
    std::vector<int>wn(p+1);
    for(int i=0;i<p;++i){
        wn[i+1]=wn[i]+get(s[i%n],t[i%m]);
    }
    std::cout<<(K/p)*wn[p]+wn[K%p]<<'\n';
    return 0;
}