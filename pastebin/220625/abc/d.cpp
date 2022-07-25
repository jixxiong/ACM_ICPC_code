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
using ld=long double;

int32_t main(){
    int n; std::cin>>n;
    std::vector<int>x(n);
    std::vector<int>y(n);
    std::vector<int>P(n);
    for(int i=0;i<n;++i){
        std::cin>>x[i]>>y[i]>>P[i];
    }
    auto can_jump=[&](int i,int j,ll s){
        return (ll)s*P[i]>=std::abs((ll)x[i]-x[j])+std::abs((ll)y[i]-y[j]);
    };
    auto check=[&](ll s){
        std::vector<std::vector<int>>G(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j) continue;
                if(can_jump(i,j,s)){
                    G[i].pb(j);
                }
            }
        }
        for(int i=0;i<n;++i){
            std::vector<int>vis(n);
            vis[i]=true;
            std::queue<int>q;
            q.push(i);
            int c=n-1;
            while(!q.empty()){
                auto u=q.front(); q.pop();
                for(auto v:G[u]){
                    if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                        c--;
                    }
                }
            }
            if(c==0) return true;
        }
        return false;
    };
    ll l=0,r=10000000000;
    while(l+1<r){
        ll mid=((ll)l+r)>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    std::cout<<r<<'\n';
    return 0;
}