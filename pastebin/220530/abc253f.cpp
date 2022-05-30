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

struct Fenwick{
    int n; 
    std::vector<ll>arr;
    Fenwick(int n):n(n),arr(n+1){ }
    void add(int x,ll v){
        for(;x<=n;x+=x&-x) arr[x]+=v;
    }
    ll get(int x){
        ll ret=0;
        for(;x>0;x-=x&-x) ret+=arr[x];
        return ret;
    }
};

struct node{
    int id,col; ll s;
};

int32_t main(){
    int n,m,q; std::cin>>n>>m>>q;
    std::vector<int>t(q+n),a(q+n),b(q+n),c(q+n);
    for(int i=0;i<n;++i) t[i]=2,a[i]=i+1,b[i]=0;
    for(int i=n;i<n+q;++i){
        std::cin>>t[i];
        if(t[i]==1) std::cin>>a[i]>>b[i]>>c[i];
        else std::cin>>a[i]>>b[i];
    }
    std::vector<std::vector<node>>A(n+1);
    Fenwick fen(m);
    std::vector<ll>ret(q+n);
    for(int i=n+q-1;i>=0;--i){
        int op=t[i];
        if(op==1){
            fen.add(a[i],c[i]);
            fen.add(b[i]+1,-c[i]);
        }else if(op==2){
            for(auto [id,col,s]:A[a[i]])
                ret[id]=b[i]+fen.get(col)-s;
            std::vector<node>().swap(A[a[i]]);
        }else if(op==3){
            A[a[i]].pb(node{i,b[i],fen.get(b[i])});
        }
    }
    for(int i=n;i<n+q;++i) if(t[i]==3) std::cout<<ret[i]<<'\n';
    return 0;
}