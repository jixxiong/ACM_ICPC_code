#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x7fffffff
#define endl '\n'
int a[100005];
int n,m;
string s;
int isleft(int x){
	int p=1-x,cnt=0;
	for(int i=1;i<=m;i++){
		while(p+x+x<=a[i])	cnt++,p+=x;
		p=a[i];
	}
	while(p+x<=n)	cnt++,p+=x;
	return cnt<=2;
}
int solve(int l,int r){
	while(l+1!=r){
		int mid=(l+r)/2;
		if(isleft(mid))	l=mid;
		else			r=mid;
	}
	return l;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;s=" "+s;
    for(int i=1;i<=n;i++){
    	if(s[i]-'0'==1)	a[++m]=i;
	}
	int l=1,r=n;
	for(int i=1;i<m;i++){
		r=min(a[i+1]-a[i],r);
	}
	cout<<solve(1,r+1);
}


//考虑边界了？
//考虑特殊情况？
//考虑输出中间值勘误？