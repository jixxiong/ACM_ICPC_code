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
    int n; cin>>n;
    set<int>st;
    n=n<<1|1;
    for(int i=1;i<=n;++i)
        st.insert(i);
    while(!st.empty()){
        cout<<*st.begin()<<endl;
        st.erase(st.begin());
        if(st.empty())
            break;
        cin>>n;
        st.erase(n);
    }
    return 0; 
}