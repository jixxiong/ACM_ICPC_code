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
    int n; std::cin>>n;
    std::vector<int>A(n+1),B(n+1),C;
    for(int i=1;i<=n;++i) std::cin>>A[i],C.pb(A[i]);
    for(int i=1;i<=n;++i) std::cin>>B[i],C.pb(B[i]);
    std::sort(all(C));
    C.erase(std::unique(all(C)),C.end());
    for(int i=1;i<=n;++i){
        A[i]=std::lower_bound(all(C),A[i])-C.begin();
        B[i]=std::lower_bound(all(C),B[i])-C.begin();
    }
    int q; std::cin>>q;
    std::vector<node>Q(q);
    for(int i=0;i<q;++i){
        std::cin>>Q[i].l>>Q[i].r;
        Q[i].id=i;
    }
    const int BLOCKSIZE=500;
    std::sort(all(Q),
        [&](node const&o1,node const&o2){
            return o1.l/BLOCKSIZE!=o2.l/BLOCKSIZE?o1.l<o2.l:o1.r<o2.r;
        });
    std::vector<int>c1(C.size()),c2(C.size());
    std::vector<char>ans(q);
    int f1=0,f2=0;
    for(int i=0,l=0,r=0;i<q;++i){
        auto [ql,qr,qid]=Q[i];
        while(l>ql){
            c1[A[l]]--;
            if(c1[A[l]]==0&&c2[A[l]])f2++;
            if(c1[A[l]]==0&&!c2[A[l]])f1--;
            --l;
        }
        while(l<ql){
            ++l;
            c1[A[l]]++;
            if(c1[A[l]]==1&&c2[A[l]])f2--;
            if(c1[A[l]]==1&&!c2[A[l]])f1++;
        }
        while(r>qr){
            c2[B[r]]--;
            if(c2[B[r]]==0&&c1[B[r]])f1++;
            if(c2[B[r]]==0&&!c1[B[r]])f2--;
            --r;
        }
        while(r<qr){
            ++r;
            c2[B[r]]++;
            if(c2[B[r]]==1&&c1[B[r]])f1--;
            if(c2[B[r]]==1&&!c1[B[r]])f2++;
        }        
        ans[qid]=!f1&&!f2;
    }
    for(int i=0;i<q;++i) std::cout<<(ans[i]?"Yes":"No")<<'\n';
    return 0;
}