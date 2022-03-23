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
    char s[3],t[3];
    for(int i=0;i<3;++i)
        cin>>s[i];
    for(int i=0;i<3;++i)
        cin>>t[i];
    map<char,int>mp;
    for(int i=0;i<3;++i)
        mp[t[i]]=i;
    int a[3];
    for(int i=0;i<3;++i)
        a[i]=mp[s[i]];
    int cnt=0;
    for(int i=0;i<3;++i)
        for(int j=0;j<i;++j)
            if(a[j]>a[i])
                cnt++;
    puts(cnt&1?"No":"Yes");
    return 0; 
}