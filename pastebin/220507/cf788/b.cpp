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
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::string s; std::cin>>s;
        int k; std::cin>>k;
        std::array<bool,128>vis{};
        for(int i=0;i<k;++i){
            char ch; std::cin>>ch;
            vis[ch]=true;
        }
        std::set<int>fuk;
        for(int i=0;i<n;++i) if(vis[s[i]])fuk.insert(i);
        std::set<int,std::greater<int>>era;
        for(int i=0;i<n;++i) era.insert(i);
        int c=0;
        while(true){
            std::vector<int>gan;
            for(auto i:fuk){
                auto p=era.upper_bound(i);
                if(p!=era.end())gan.pb(*p);
            }
            if(gan.empty())break;
            for(auto i:gan){
                era.erase(i);
                if(fuk.count(i)) fuk.erase(i);
            }
            c++;
        }
        std::cout<<c<<'\n';
    }
    return 0;
}