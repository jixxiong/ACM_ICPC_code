#include <bits/stdc++.h>

template<typename T>using vc=std::vector<T>;
using i32=int32_t;
using usize=size_t;

int32_t main(){
    i32 n; std::cin>>n;
    std::unordered_set<i32>st1,st2;
    vc<usize>hs1(n+1),hs2(n+1);
    auto hash_func = std::hash<std::string>();
    for(i32 i=1;i<=n;++i){
        i32 x; std::cin>>x;
        if(st1.count(x)){
            hs1[i]=hs1[i-1];
            continue;
        }
        st1.insert(x);
        hs1[i]=hs1[i-1]+hash_func(std::to_string(x));
    }
    for(i32 i=1;i<=n;++i){
        i32 x; std::cin>>x;
        if(st2.count(x)){
            hs2[i]=hs2[i-1];
            continue;
        }
        st2.insert(x);
        hs2[i]=hs2[i-1]+hash_func(std::to_string(x));
    }
    i32 q; std::cin>>q;
    while(q--){
        i32 x,y; std::cin>>x>>y;
        std::cout<<(hs1[x]==hs2[y]?"YES":"NO")<<'\n';
    }
    return 0;
}