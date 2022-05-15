#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

std::mt19937 rng(114514);

int range(int l,int r){
    return rng()%(r-l+1)+l;
}

int main(){
    int const N=100000;
    std::vector<int>A;
    std::set<int>st;
    std::vector<int>vis2(N+10);
    int const M=10;
    for(int i=1;i<=M;++i){
        A.pb(i);
        st.insert(i);
        vis2[i]=true;
        for(int j=i+1;j<=M;++j){
            st.insert(i+j);
            vis2[i+j]=true;
            for(int k=j+1;k<=M;++k){
                st.insert(i+j+k);
                vis2[i+j+k]=true;
            }
        }
    }
    for(int i=4;i<=N;++i){
        if(vis2[i]) continue;
        int j=i;
        for(auto x:st){
            if(x+j>N) break;
            vis2[x+j]=true;
        }
        for(auto x:A) st.insert(x+j);
        A.pb(j);
        st.insert(j);
    }
    std::cout<<A.size()<<'\n';
    for(auto x:A) std::cout<<x<<' ';
    return 0;
}