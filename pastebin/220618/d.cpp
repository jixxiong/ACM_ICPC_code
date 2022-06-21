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
    int n; std::cin>>n;
    std::vector<int>vis(400010);
    for(int i=1;i<=n;++i){
        int l,r; std::cin>>l>>r;
        l<<=1, r<<=1;
        vis[l]++,vis[r]--;
    }
    for(int i=1;i<=400000;++i){
        vis[i]+=vis[i-1];
    }
    for(int l=1,r;l<=400000;l=r){
        while(l<=400000 && !vis[l]) l++;
        if(l > 400000) break;
        r = l + 1;
        while(r<=400000 && vis[r]) r++;
        std::cout<<l/2<<' '<<(r+1)/2<<'\n';
    }
    return 0;
}