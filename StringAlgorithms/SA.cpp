#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

// O(nlogn) 
struct SA {
	vector<int>sa,rk,ht;
	template<typename T>
	SA(T *s,int n):sa(n+1),rk(n+1),ht(n+1){ // 传入离散化后的数组
		int m=*max_element(s+1,s+1+n);
		vector<int>tp(n+1),buk(n+1);
		for(int i=1;i<=n;++i) rk[i]=s[i],tp[i]=i;
		auto radix_sort=[&](int m){
			fill_n(buk.begin(),m+1,0);
			for(int i=1;i<=n;++i) buk[rk[i]]++;
			for(int i=1;i<=m;++i) buk[i]+=buk[i-1];
			for(int i=n;i>=1;--i) sa[buk[rk[tp[i]]]--]=tp[i];
		};
		radix_sort(m);
		for(int w=1,p=0;p<n;m=p,w<<=1,p=0) {
			for (int i=1;i<=w;++i) tp[++p]=n-w+i;
			for (int i=1;i<=n;++i) 
				if(sa[i]>w) tp[++p]=sa[i]-w;
			radix_sort(m);
			copy(all(rk),tp.begin());
			rk[sa[1]]=p=1;
			for(int i=2;i<=n;++i)
				rk[sa[i]]=tp[sa[i-1]]==tp[sa[i]]&&tp[sa[i-1]+w]==tp[sa[i]+w]?p:++p;
		}
		for (int i=1,k=0;i<=n;++i) {
			if(k)--k;
			while(i+k<=n&&sa[rk[i]-1]+k<=n&&s[i+k]==s[sa[rk[i]-1]+k])++k;
			ht[rk[i]]=k;
		}
	}
};


// ST for SA and lcp
struct ST{
	vector<vector<int>>st;
	ST(vector<int>A):st(A.size()){ // height 
		int n=A.size()-1;
		for(int i=1;i<=n;++i){
			st[i].resize(__lg(n)+1);
			st[i][0]=A[i];
		}
		for(int j=1;j<=__lg(n);++j)
			for(int i=1;i+(1<<j)-1<=n;++i)
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int qry(int l,int r){ // lcp(l,r)
		if(l>r)swap(l,r);
		l++;
		int s=__lg(r-l+1);
		return min(st[l][s],st[r-(1<<s)+1][s]);
	}
};

signed main(){
	
	return 0;
}