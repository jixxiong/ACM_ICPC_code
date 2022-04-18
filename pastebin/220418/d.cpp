#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int n; std::cin>>n;
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    int q; std::cin>>q;
    std::vector<std::array<int,4>>Q(q);
    for(int i=0;i<q;++i){
        for(int j=0;j<3;++j) std::cin>>Q[i][j];
        Q[i][3]=i;
    }
    const int SIZE=500;
    std::sort(all(Q),[&](const std::array<int,4>&o1,const std::array<int,4>&o2){
        return o1[0]/SIZE==o2[0]/SIZE?o1[1]<o2[1]:o1[0]<o2[0];
    });
    std::vector<int>ans(q);
    std::vector<int>cnt(n+1);
    auto add=[&](int x){
        cnt[A[x]]++;
    };
    auto del=[&](int x){
        cnt[A[x]]--;
    };
    for(int i=0,l=1,r=0;i<q;++i){
        int L=Q[i][0],R=Q[i][1],x=Q[i][2],id=Q[i][3];
        while(l<L)del(l++);
        while(l>L)add(--l);
        while(r>R)del(r--);
        while(r<R)add(++r);
        ans[id]=cnt[x];
    }
    for(int i=0;i<q;++i) std::cout<<ans[i]<<'\n';
    return 0;
}