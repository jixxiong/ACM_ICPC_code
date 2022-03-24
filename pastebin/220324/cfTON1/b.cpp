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
        int n,k; cin>>n>>k;
        multiset<int>st;
        vector<int>A;
        for(int i=1;i<=n;++i){
            int x; cin>>x;
            A.pb(x);
            st.insert(x);
        }
        bool ok=false;
        for(auto x:A){
            st.erase(st.find(x));
            if(st.count(x+k))
                ok=true;
            st.insert(x);
        }
        puts(ok?"YES":"NO");
    }
    return 0;
}