#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f
#define endl '\n'
#define MOD 998244353
#define IOS ios::sync_with_stdio(false);cin.tie(0);
int l,n,k;
int a[100005];
int isleft(int x){
	int cnt=0;
    for(int i=2;i<=n;++i){
        cnt+=(a[i]-a[i-1]-1)/x;
    }
	return cnt>=k;
}
int solve(int l,int r){
	while(l+1!=r){
		int mid=(l+r)>>1;
		if(isleft(mid))	l=mid;
		else			r=mid;
	}
	return l;
}
signed main(){
	    IOS
	    cin>>l>>n>>k;
	    for(int i=1;i<=n;i++)	cin>>a[i];
	    cout<<solve(0,l+1)<<endl;
}


//考虑边界了？
//考虑特殊情况？
//考虑输出中间值勘误？