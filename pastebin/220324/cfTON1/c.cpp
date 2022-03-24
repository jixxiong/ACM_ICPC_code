#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); }
#endif
void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int>A(n+1);
        bool one=false,zer=false;
        for(int i=1;i<=n;++i){
            cin>>A[i];
            if(A[i]==1) one=true;
            if(A[i]==0) zer=true;
        }
        if(one&&zer){
            puts("NO");
        }else if(one){
            sort(all(A));
            bool ok=true;
            for(int i=2;i<=n;++i){
                if(A[i]!=1&&A[i]-A[i-1]==1){
                    ok=false;
                }
            }
            puts(ok?"YES":"NO");
        }else{
            puts("YES");
        }
    }
    return 0; 
}