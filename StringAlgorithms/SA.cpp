#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

// O(nlogn) Print Version with lost of blank ssspaces
struct SA {
	vector<int> sa, rk, ht;

	template<typename T>
	SA(T *s, int n):sa(n + 1), rk(n + 1), ht(n + 1) {
		vector<T> str(s+1, s + 1 + n), tmp(s+1,s+1+n);
		sort(all(tmp)); tmp.erase(unique(all(tmp)), tmp.end());
		for (auto &x: str)
			x = lower_bound(all(tmp), x) - tmp.begin()+1;
		int m = *max_element(all(str));
		vector<int> tp(n + 1), buk(n + 1);
		for (int i = 1; i <= n; ++i) rk[i] = str[i-1], tp[i] = i;
		auto radix_sort = [&]() {
			fill_n(buk.begin(), m + 1, 0);
			for (int i = 1; i <= n; ++i) buk[rk[i]]++;
			for (int i = 1; i <= m; ++i) buk[i] += buk[i - 1];
			for (int i = n; i >= 1; --i) sa[buk[rk[tp[i]]]--] = tp[i];
		};
		radix_sort();
		for (int w = 1, p = 0; p < n; m = p, w <<= 1) {
			p=0;
			for (int i = 1; i <= w; ++i) tp[++p] = n - w + i;
			for (int i = 1; i <= n; ++i)
				if (sa[i] > w) tp[++p] = sa[i] - w;
			radix_sort();
			copy(all(rk), tp.begin());
			rk[sa[1]] = p = 1;
			for (int i = 2; i <= n; ++i)
				rk[sa[i]] = tp[sa[i - 1]] == tp[sa[i]] &&
							tp[sa[i - 1] + w] == tp[sa[i] + w] ? p : ++p;
		}
		for (int i = 1, k = 0; i <= n; ++i) {
			if (k)--k;
			while (i + k <= n && sa[rk[i] - 1] + k <= n && s[i + k] == s[sa[rk[i] - 1] + k])++k;
			ht[rk[i]] = k;
		}
	}
};


// O(nlogn) template version 
struct SA {
	vector<int>sa,rk,ht;
	template<typename T>
	SA(T *s,int n):sa(n+1),rk(n+1),ht(n+1){
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


// O(nlogn) with more constants
struct SA{
	vector<int>sa,ht,rk;
	SA(int *s,int n):sa(n+1),ht(n+1),rk(2*n+1){
		int m=max(n,300ll);
		vector<int>id(n+1),cnt(m+1),f(2*n+1);
		for(int i=1;i<=n;++i) ++cnt[rk[i]=s[i]];
		for(int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;--i) sa[cnt[rk[i]]--]=i;
		for(int w=1;w<n;w<<=1){
			fill(all(cnt),0);
			for(int i=1;i<=n;++i) id[i]=sa[i];
			for(int i=1;i<=n;++i) ++cnt[rk[id[i]+w]];
			for(int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
			for(int i=n;i>=1;--i) sa[cnt[rk[id[i]+w]]--]=id[i];
			fill(all(cnt),0);
			for(int i=1;i<=n;++i) id[i]=sa[i];
			for(int i=1;i<=n;++i) ++cnt[rk[id[i]]];
			for(int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
			for(int i=n;i>=1;--i) sa[cnt[rk[id[i]]]--]=id[i];
			copy(all(rk),f.begin());
			for(int p=0,i=1;i<=n;++i){
				if(f[sa[i]]==f[sa[i-1]]&&f[sa[i]+w]==f[sa[i-1]+w])
					rk[sa[i]]=p;
				else
					rk[sa[i]]=++p;
			}
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

int A[2000010];
int B[1000010];

signed main(){
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&A[i]);
		B[i]=A[i];
	}
	sort(B+1,B+1+n);
	int m=unique(B+1,B+1+n)-B-1;
	for(int i=n+2;i<=2*n+1;++i){
		A[i]=lower_bound(B+1,B+1+m,A[i-n-1])-B+1;
	}
	A[n+1]=1;
	for(int i=1,j=2*n+1;i<=n;++i,--j)
		A[i]=A[j];
	SA sa(A,2*n+1);
	vector<int>sum(2*n+2);
	for(int i=n+2;i<=2*n+1;++i)
		sum[sa.rk[i]]++;
	for(int i=1;i<=2*n+1;++i)
		sum[i]+=sum[i-1];
	ST st(sa.ht);
	vector<int>ans(n+1);
	for(int i=1;i<=n;++i){
		int ps=sa.rk[i];
		auto find_first=[&](int l,int r,int p,int k){
			while(l+1<r){
				int mid=(l+r)/2;
				if(st.qry(mid,p)>=k)
					r=mid;
				else
					l=mid;
			}
			return r;
		};
		auto find_last=[&](int l,int r,int p,int k){
			while(l+1<r){
				int mid=(l+r)/2;
				if(st.qry(p,mid)>=k)
					l=mid;
				else
					r=mid;
			}
			return l;
		};
		int l=find_first(0,ps,ps,n-i+1);
		int r=find_last(ps,2*n+2,ps,n-i+1);
		ans[i]=sum[r]-sum[l-1];
	}
	reverse(ans.begin()+1,ans.end());
	for(int i=1;i<=n;++i){
		printf("%lld ",ans[i]);
	}
	puts("");
	return 0;
}