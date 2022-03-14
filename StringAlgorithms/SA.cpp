#include <bits/stdc++.h>
using namespace std;

template<typename T,int sigma=300>
struct SA{
	vector<int>sa,rk,ht;
	// Ensure that str[n] is the unique lexicographically smallest character in str.
	// Moreover, the max element should not be larger than the size of the array
	// this means you should discretize the array before
	SA(T* str,int n){
		const int size=max(sigma,n)+2;
		sa.resize(size),rk.resize(size),ht.resize(size);
		vector<int>s(size<<1),t(size<<1),p(size),cur(size),cnt(size);
		str[++n]=0,++str;
		int m=[&](){
			int m=*max_element(str,str+n);
			fill_n(&rk[0],m+1,0);
			for (int i=0;i<n;i++) rk[(int)str[i]]=1;
			for (int i=0;i<m;i++) rk[i+1]+=rk[i];
			for (int i=0;i<n;i++) s[i]=rk[(int)str[i]]-1;
			return rk[m];
		}();
		function<void(int,int,int*,int*,int*)>sais=[&](int n,int m,int* s,int* t,int* p) {
			int n1=t[n-1]=0,ch=rk[0]=-1,*s1=s+n;
			auto pushS=[&](int x){ sa[cur[s[x]]--]=x; };
			auto pushL=[&](int x){ sa[cur[s[x]]++]=x; };
			auto IS=[&](int* v){
				fill_n(&sa[0],n,-1);fill_n(&cnt[0],m,0);
				for(int i=0;i<n;i++) cnt[s[i]]++;
				for(int i=1;i<m;i++) cnt[i]+=cnt[i-1];
				for(int i=0;i<m;i++) cur[i]=cnt[i]-1;
				for(int i=n1-1;~i;i--) pushS(v[i]);
				for(int i=1;i<m;i++) cur[i]=cnt[i-1];
				for(int i=0;i<n;i++) if(sa[i]>0&&t[sa[i]-1]) pushL(sa[i]-1);
				for(int i=0;i<m;i++) cur[i]=cnt[i]-1;
				for(int i=n-1;~i;i--) if(sa[i]>0&&!t[sa[i]-1]) pushS(sa[i]-1);
			};
			for(int i=n-2;~i;i--) t[i]=s[i]==s[i+1]?t[i+1]:s[i]>s[i+1];
			for(int i=1;i<n;i++) rk[i]=t[i-1]&&!t[i]?(p[n1]=i,n1++):-1;
			IS(p);
			for(int i=0,x,y;i<n;i++) if(~(x=rk[sa[i]])){
				if(ch<1||p[x+1]-p[x]!=p[y+1]-p[y])ch++;
				else for(int j=p[x],k=p[y];j<=p[x+1];j++,k++)
					if((s[j]<<1|t[j])!=(s[k]<<1|t[k])) { ch++; break; }
				s1[y=x]=ch;
			}
			if(ch+1<n1)sais(n1,ch+1,s1,t+n,p+n1);
			else for(int i=0;i<n1;i++) sa[s1[i]]=i;
			for(int i=0;i<n1;i++) s1[i]=p[sa[i]];
			IS(s1);
		};
		sais(n,m,&s[0],&t[0],&p[0]);
		for (int i=0;i<n;i++) rk[sa[i]]=i;
		for (int i=0,h=ht[0]=0;i<n-1;i++) {
			int j=sa[rk[i]-1];
			while (i+h<n&&j+h<n&&s[i+h]==s[j+h]) h++;
			if ((ht[rk[i]]=h)) h--;
		}
		for(int i=n-1;i>=1;--i) {
			rk[i]=rk[i-1];
			sa[i]++;
		}
	}
};

char s[1000010];

// ST for SA and static lcp => lcp(i,j) in O(1)
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
		if(l==r) return -1;
		if(l>r)swap(l,r);
		l++;
		int s=__lg(r-l+1);
		return min(st[l][s],st[r-(1<<s)+1][s]);
	}
};


int main() {
	scanf("%s", s+1);
	int n=strlen(s+1);
	SA sa(s,n);
	for (int i=1;i<=n;++i)
		printf("%d ",sa.sa[i]);
	puts("");
	return 0;
}

// O(nlogn) => SA 
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



signed main(){
	
	return 0;
}