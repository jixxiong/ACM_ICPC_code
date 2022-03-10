#include <bits/stdc++.h>
using namespace std;

struct Fenwick{
	vector<int>arr;
	int n;
	Fenwick(int n):arr(n+1),n(n){}
	void upd(int x,int v){
		for(;x<=n;x+=x&-x)
			arr[x]=max(arr[x],v);
	}
	int get(int x){
		int res=0;
		for(;x;x-=x&-x)
			res=max(res,arr[x]);
		return res;
	}
};

int LIS(vector<int>&A,int l,int r){ // A 要离散化
	Fenwick tr(*max_element(A.begin()+l,A.begin()+r+1));
	int ans=0;
	for(int i=r;i>=l;--i){
		int q=tr.get(A[i])+1;
		tr.upd(A[i],q);
		ans=max(ans,q);
	}
	return ans;
}

signed main(){
	int n;
	scanf("%d",&n);
	vector<int>A(n+1);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	vector<int>B(A.begin()+1,A.end());
	sort(B.begin(),B.end());
	for(int i=1;i<=n;++i)
		A[i]=lower_bound(B.begin(),B.end(),A[i])-B.begin()+1;
	int ans=LIS(A,1,n);
	for(int i=1;i<n;++i)
		ans=max(ans,LIS(A,1,i)+LIS(A,i+1,n));
	printf("%d\n",ans);
	return 0;
}