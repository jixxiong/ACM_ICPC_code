#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fuck(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fuck(fst F, lst... L) { std::cerr<<F<<' '; fuck(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct Fenwick{
    std::vector<int>arr;
    int n;
    Fenwick(int n):arr(n+1),n(n){}
    void add(int x,int v){
        for(;x<=n;x+=x&-x) arr[x]+=v;
    }
    int get(int x){
        int ret=0;
        for(;x>=1;x-=x&-x) ret+=arr[x];
        return ret;
    }
};

int main(){
    int n,m; std::cin>>n>>m;
    std::vector<int>A(n+1);
	A[0]=0x3f3f3f3f;
    std::vector<std::pair<int,int>>B(n+1);
    std::vector<std::vector<int>>G(n+1);
    for(int i=1,fa;i<=n;++i) {
        std::cin>>A[i]>>fa;
        if(i!=1) G[fa].pb(i);
        B[i].first=A[i];
        B[i].second=i;
    }
    std::vector<std::vector<int>>st(n+1,std::vector<int>(std::__lg(n)+1));
    std::vector<int>dep(n+1);
    dep[1]=1;
    std::function<void(int)>dfs=[&](int u){
        for(auto v:G[u]){
            dep[v]=dep[u]+1;
            st[v][0]=u;
            for(int i=1;i<=std::__lg(n);++i){
                st[v][i]=st[st[v][i-1]][i-1];
            }
            dfs(v);
        }
    };
    dfs(1);
    std::vector<std::array<int,2>>qry(m+1);
    for(int i=1;i<=m;++i){
        int o,l,r; std::cin>>o>>l>>r;
        for(int j=std::__lg(n);j>=0;--j)
            if(A[st[o][j]]<=r) o=st[o][j];
        qry[i]=std::array<int,2>{o,l};
    }
    std::sort(qry.begin()+1,qry.end(),[](const std::array<int,2>&o1,const std::array<int,2>&o2){
        return o1[1]>o2[1];
    });
    std::sort(B.begin()+1,B.end(),std::greater<>());
    int idx=1;
    std::vector<std::vector<int>>fk(n+1);
    std::vector<int>tic(n+1,m+1);
    for(int i=1;i<=m;++i){
        int h=qry[i][1];
        while(idx<=n&&B[idx].first>=h){
            tic[B[idx].second]=i;
			idx++;
        }
        fk[qry[i][0]].pb(i);
    }
    Fenwick bit(m+1);
    std::vector<int>ans(n+1);
    std::function<void(int)>dfs1=[&](int u){
        for(auto x:fk[u]) bit.add(x,1);
        ans[u]=bit.get(m)-bit.get(tic[u]-1);
        for(auto v:G[u]){
            dfs1(v);
        }
		for(auto x:fk[u]) bit.add(x,-1);
    };
    dfs1(1);
    for(int i=1;i<=n;++i)
        std::cout<<ans[i]<<" \n"[i==n];
    return 0;
}