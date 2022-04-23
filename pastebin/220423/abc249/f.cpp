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
    int n,k; std::cin>>n>>k;
    std::vector<std::pair<int,int>>A(n+1);
    A[0]={1,0};
    for(int i=1;i<=n;++i){
        std::cin>>A[i].first>>A[i].second;
    }
    int cnt=0;
    std::priority_queue<int,std::vector<int>,std::less<int>>q1;
    ll ret=-1e18,tot=0,sum=0;
    for(int p=n;p>=0;p--){
        while(A[p].first==2){
            if(A[p].second<0){
                q1.push(A[p].second);
                sum+=A[p].second;
            }
            tot+=A[p].second;
            p--;
        }
        if(k-cnt<0) break;
        while((int)q1.size()>(k-cnt)){
            auto top=q1.top(); q1.pop();
            sum-=top;
        }
        ret=std::max(ret,A[p].second+tot-sum);
        cnt++;
    }
    std::cout<<ret<<'\n';
    return 0;
}