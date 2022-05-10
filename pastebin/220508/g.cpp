#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct node{
    int l,r,id;
};

int main(){
    int T; std::cin>>T;
    while(T--){
        int n,q; std::cin>>n>>q;
        std::vector<std::vector<int>>A(n+1);
        std::vector<int>B;
        for(int i=1;i<=n;++i){
            int x; std::cin>>x;
            for(int j=2;j<=x/j;++j){
                if(x%j==0){
                    A[i].pb(j); B.pb(j);
                    do x/=j; while(x%j==0);
                }
            }
            if(x!=1) A[i].pb(x), B.pb(x);
        }
        std::sort(all(B));
        B.erase(std::unique(all(B)),B.end());
        for(int i=1;i<=n;++i){
            for(int j=0;j<(int)A[i].size();++j){
                A[i][j]=std::lower_bound(all(B),A[i][j])-B.begin();
            }
        }
        std::vector<node>Q(q);
        for(int i=0;i<q;++i){
            std::cin>>Q[i].l>>Q[i].r;
            Q[i].id=i;
        }
        const int BLOCKSIZE=500;
        std::sort(all(Q),
            [&](node const& o1,node const& o2){
                return o1.l/BLOCKSIZE==o2.l/BLOCKSIZE?
                    o1.r<o2.r:
                    o1.l<o2.l;
            });
        int ans=0;
        std::vector<int>ret(q);
        std::vector<int>cnt(B.size());
        std::vector<int>fuk(n+2);
        fuk[0]=B.size();
        auto add=[&](int id){
            for(auto x:A[id]){
                fuk[cnt[x]++]--;
                fuk[cnt[x]]++;
                if(ans<n&&fuk[ans+1]==1)ans++;
            }
        };
        auto del=[&](int id){
            for(auto x:A[id]){
                fuk[cnt[x]--]--;
                fuk[cnt[x]]++;
                if(fuk[ans]==0)ans--;
            }
        };
        for(int i=0,l=1,r=0;i<q;++i){
            auto ql=Q[i].l,qr=Q[i].r,qid=Q[i].id;
            while(r<qr) add(++r);
            while(l>ql) add(--l);
            while(r>qr) del(r--);
            while(l<ql) del(l++);
            ret[qid]=ans;
        }
        for(int i=0;i<q;++i) std::cout<<ret[i]<<'\n';
    }
    return 0;
}