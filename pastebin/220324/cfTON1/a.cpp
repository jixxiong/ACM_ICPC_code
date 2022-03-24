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
        for(int i=1;i<=n;++i)
            cin>>A[i];
        int r=max_element(A.begin()+1,A.end())-A.begin();
        int l=min_element(A.begin()+1,A.end())-A.begin();
        cout<<l<<" "<<r<<'\n';
    }
    return 0; 
}