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
    int T; std::cin>>T;
    while(T--){
        int n,k; std::cin>>n>>k;
        std::vector<int>A(n);
        int s=-1;
        for(int i=0;i<n;++i) std::cin>>A[i],s&=A[i];
        std::vector<int>cnt(35);
        for(int i=0;i<=30;++i){
            int b=1<<i;
            int c=0;
            for(int j=0;j<n;++j){
                c+=((A[j]&b)==0);
            }
            cnt[i]=c;
        }
        // for(int i=0;i<=30;++i) fk(">>",i,cnt[i]);
        while(k){
            bool fail=true;
            for(int i=30;i>=0;--i){
                if(cnt[i]&&k>=cnt[i]){
                    k-=cnt[i];
                    cnt[i]=0;
                    s|=(1<<i);
                    fail=false;
                    break;
                }
            }
            if(fail)break;
        }
        std::cout<<s<<'\n';
    }
    return 0;
}