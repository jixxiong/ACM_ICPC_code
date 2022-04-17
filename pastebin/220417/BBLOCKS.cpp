#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
const int mod=998244353;
#define int long long

int fast(int x,int k){
    int ret=1;
    while(k){
        if(k&1) ret=(ll)ret*x%mod;
        x=(ll)x*x%mod;
        k>>=1;
    }
    return ret;
}

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        int w,h; std::cin>>w>>h;
        w=w<<1|1, h=h<<1|1;
        std::vector<int>num[2];
        num[0].pb(1),num[0].pb(w);
        num[1].pb(1),num[1].pb(h);
        std::vector<std::array<int,4>>A(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<4;++j){
                std::cin>>A[i][j]; A[i][j]=A[i][j]<<1|1;
                num[j&1].pb(A[i][j]);
                if(A[i][j]-1>0) num[j&1].pb(A[i][j]-1);
                if(A[i][j]+1<(j&1?w:h)) num[j&1].pb(A[i][j]+1);
            }
        }
        for(int i=0;i<2;++i){
            std::sort(all(num[i]));
            num[i].erase(std::unique(all(num[i])),num[i].end());
        }
        w=std::lower_bound(all(num[0]),w)-num[0].begin();
        h=std::lower_bound(all(num[1]),h)-num[1].begin();
        for(int i=0;i<n;++i)
            for(int j=0;j<4;++j)
                A[i][j]=std::lower_bound(all(num[j&1]),A[i][j])-num[j&1].begin();
        std::vector<char>vis(1<<n,true);
        bool fail=true;
        for(int i=0;i<(1<<n);++i){
            std::vector<ll>B(w+1);
            for(int j=0;j<n;++j){
                if((i>>j)&1){
                    ll ret=0;
                    for(int t=A[j][1];t<=std::min(h,A[j][3]);++t)
                        ret|=1ll<<t;
                    for(int t=A[j][0];t<=std::min(w,A[j][2]);++t)
                        B[t]|=ret;
                }
            }
            for(int j=0;j<=w;++j){
                if(B[j]!=(1ll<<(h+1))-1) vis[i]=false;
            }
            if(vis[i]) fail=false;
        }
        if(fail){
            std::cout<<"-1\n";
            continue;
        }
        std::vector<int>dp(1<<n);
        for(int s=(1<<n)-1;s>=0;--s){
            if(vis[s]) continue;
            int tot=0;
            for(int i=0;i<n;++i){
                if(((s>>i)&1)==0){
                    dp[s]+=dp[s^(1<<i)];
                    dp[s]%=mod;
                }
                else ++tot;
            }
            dp[s]=(dp[s]+n)%mod;
            dp[s]=(ll)dp[s]*fast(n-tot,mod-2)%mod;
        }
        std::cout<<dp[0]<<'\n';
    }
    return 0;
}

/**
 * @brief 
 * 
 * 
1
3
1 3
0 0 1 1
0 1 1 2
0 2 1 3
 * 
 */