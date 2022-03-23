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

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main(){
    int x=0,y=0,d=0;
    int n; cin>>n;
    string s;cin>>s;
    for(char ch:s){
        if(ch=='S'){
            x+=dx[d];
            y+=dy[d];
        }else{
            d=(d+1)%4;
        }
    }
    cout<<x<<' '<<y<<'\n';
    return 0; 
}