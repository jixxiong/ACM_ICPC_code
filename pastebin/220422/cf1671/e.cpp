#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void dg(){ std::cerr<<'\n'; } template<class fst,class...lst>
void dg(fst F, lst... L) { std::cerr<<F<<' '; dg(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ull=unsigned long long;

int main(){
    int n; std::cin>>n;
    n=(1<<n)-1;
    std::string s; std::cin>>s; s=' '+s;
    const int mo=100000799;const int m2=1000000409;
    std::vector<int>id(n+1); int c=1;
    std::vector<int>fk(n+1),fk2(n+1);
    std::function<void(int)>f=[&](int u){
        id[u]=c++;
        fk[u]=(s[u]=='A')?41:37;
        fk2[u]=(s[u]=='A')?23:31;
        if((u<<1)>n)return ;
        f(u<<1); f(u<<1|1);
        if((ll)fk[u<<1]*(ll)fk2[u<<1]<(ll)fk[u<<1|1]*(ll)fk2[u<<1|1]){
            fk[u]=(ll)fk[u]*((3ll*fk[u<<1]%mo+233)%mo+fk[u<<1|1]%mo);
            fk[u]%=mo;
            fk2[u]=(ll)fk2[u]*((7ll*fk2[u<<1]%m2+4933)%m2+fk2[u<<1|1]%m2);
            fk2[u]%=m2;
        }else{
            fk[u]=(ll)fk[u]*((3ll*fk[u<<1|1]%mo+233)%mo+fk[u<<1]%mo);
            fk[u]%=mo;
            fk2[u]=(ll)fk2[u]*((7ll*fk2[u<<1|1]%m2+4933)%m2+fk2[u<<1]%m2);
            fk2[u]%=m2;
        }
    };
    f(1);
    std::function<int(int)>dfs=[&](int u){
        int v1=u<<1,v2=u<<1|1;
        if(v1>n) return 1ll;
        int m1=dfs(v1);
        int m2=dfs(v2);
        return (ll)m1*m2%mo*(fk[v1]==fk[v2]&&fk2[v1]==fk2[v2]?1:2)%mo;
    };
    std::cout<<dfs(1)<<'\n';
    return 0;
}