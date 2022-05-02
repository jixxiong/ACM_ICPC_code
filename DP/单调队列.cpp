#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int n; std::cin>>n;
    std::vector<int>A(n+1),B(n+1);
    for(int i=1;i<=n;++i){
        std::cin>>A[i]>>B[i];
    }
    std::list<int>q;
    std::list<int>t;
    for(int i=1;i<=n;++i){
        while(!q.empty()&&A[q.front()]<i){
            if(!t.empty()&&t.front()==q.front()) t.pop_front();
            q.pop_front();
        }
        q.push_back(i);
        while(!t.empty()&&B[t.back()]<=B[i]) t.pop_back();
        t.push_back(i);
        std::cout<<B[t.front()]<<'\n';
    }
    return 0;
}