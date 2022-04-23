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
        int n; std::cin>>n;
        std::vector<int>A(n),B(n);
        for(int i=0;i<n;++i) std::cin>>A[i];
        for(int i=0;i<n;++i) std::cin>>B[i];
        int i=n-1,j=n-1;
        std::vector<int>cnt(n+1);
        bool fail=false;
        while(true){
            if(j<0){
                while(i>=0){
                    if(cnt[A[i]]){
                        cnt[A[i]]--;
                        i--;
                    }else{
                        fail=true;
                        break;
                    }
                }
                break;
            }
            if(A[i]==B[j]) {
                i--,j--;
                continue;
            }
            if(j+1<n&&B[j]==B[j+1]){
                cnt[B[j]]++;
                j--;
                continue;
            }
            if(cnt[A[i]]){
                cnt[A[i]]--;
                i--;
                continue;
            }
            fail=true;
            break;
        }
        std::cout<<(fail?"NO":"YES")<<'\n';
    }
    return 0;
}