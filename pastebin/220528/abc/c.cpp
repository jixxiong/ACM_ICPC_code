#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define er(args...) void()
#else
    #define vwn(x) #x"=",x,"\n"
    void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
    #define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int32_t main(){
    int q; std::cin>>q;
    std::map<int,int>mp;
    while(q--){
        int op; std::cin>>op;
        if(op==1){
            int x; std::cin>>x;
            mp[x]++;
        }else if(op==2){
            int x,c; std::cin>>x>>c;
            if(!(mp[x]-=std::min(mp[x],c))) mp.erase(x);
        }else{
            std::cout<<mp.rbegin()->first-mp.begin()->first<<'\n';
        }
    }
    return 0;
}