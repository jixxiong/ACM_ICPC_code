#include <bits/stdc++.h>
using namespace std;

struct ST{
	vector<vector<int>>st;
	ST(vector<int>A):st(A.size()){
		assert((int)A.size()>1);
		int n=A.size()-1;
		for(int i=1;i<=n;++i){
			st[i].resize(__lg(n)+1);
			st[i][0]=A[i];
		}
		for(int j=1;j<=__lg(n);++j)
			for(int i=1;i+(1<<j)-1<=n;++i)
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int qry(int l,int r){
		assert(l<=r);
		int s=__lg(r-l+1);
		return min(st[l][s],st[r-(1<<s)+1][s]);
	}
};