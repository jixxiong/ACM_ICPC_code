#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int get(char x){
    return x=='#'?1:0;
}

int main(){
    std::vector<std::string>
    B_1{
        "#################",
        "#################",
        "#################",
        "####..#####..####",
        "###....###....###",
        "###....###....###",
        "####..#####..####",
        "#################",
        "#################",
        "#################"
    },
    B_2{
        "##########",
        "##########",
        "##########",
        "####..####",
        "###....###",
        "###....###",
        "####..####",
        "##########",
        "##########",
        "##########",
        "####..####",
        "###....###",
        "###....###",
        "####..####",
        "##########",
        "##########",
        "##########"
    },
    O{
        "##########",
        "##########",
        "##########",
        "####..####",
        "###....###",
        "###....###",
        "####..####",
        "##########",
        "##########",
        "##########"
    };
    int n,m; std::cin>>n>>m;
    std::vector<std::string>A(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i];
    }
    auto is_B1=[&](int x,int y){
        if(x+(int)B_1.size()-1>=n||y+(int)B_1[0].size()-1>=m) return false;
        for(int i=0;i<(int)B_1.size();++i){
            if(A[x+i].substr(y,B_1[i].size())!=B_1[i]) return false;
        }
        return true;
    };
    auto is_B2=[&](int x,int y){
        if(x+(int)B_2.size()-1>=n||y+(int)B_2[0].size()-1>=m) return false;
        for(int i=0;i<(int)B_2.size();++i){
            if(A[x+i].substr(y,B_2[0].size())!=B_2[i]) return false;
        }
        return true;
    };
    auto is_O=[&](int x,int y){
        if(x+(int)O.size()-1>=n||y+(int)O[0].size()-1>=m) return false;
        for(int i=0;i<(int)O.size();++i){
            if(A[x+i].substr(y,O[0].size())!=O[i]) return false;
        }
        return true;
    };
    int x=0,y=0;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(is_B1(i,j)||is_B2(i,j))x++;
            if(is_O(i,j))y++;
        }
    }
    std::cout<<(x)<<" "<<(y-2*x)<<'\n';
    return 0;
}