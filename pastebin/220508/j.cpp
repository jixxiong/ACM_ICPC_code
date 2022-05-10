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
    int id,ti;
    bool operator<(node const&o)const {
        return ti<o.ti;
    }
};

int main(){
    int n,k; std::cin>>n>>k;
    std::vector<int>A(n);
    for(int i=0;i<n;++i) std::cin>>A[i];
    auto B=A;
    std::sort(all(B));
    B.erase(std::unique(all(B)),B.end());
    for(int i=0;i<n;++i) A[i]=std::lower_bound(all(B),A[i])-B.begin();
    int l=0,r=n+1;
    while(l+1<r){
        int mid=(l+r)>>1;
        std::vector<char>vis(B.size(),-1);
        std::set<node>st;
        int sz=0;
        int c=0;
        for(int i=0;i<n;++i){
            if(~vis[A[i]]){
                c++;
                int tic=vis[A[i]];
                auto p=st.find(node{A[i],tic});
                st.erase(p);
                st.insert(node{A[i],i});
                vis[A[i]]=i;
                continue;
            }
            if(sz==mid){
                auto [id,ti]=*st.begin(); 
                st.erase(st.begin());
                vis[id]=-1;
                vis[A[i]]=i;
                st.insert(node{A[i],i});
            }else{
                vis[A[i]]=i;
                st.insert(node{A[i],i});
                sz++;
            }
        }
        if(c>=k) r=mid;
        else l=mid;
    }
    if(r==n+1) std::cout<<"cbddl"<<'\n';
    else std::cout<<r<<'\n';
    return 0;
}