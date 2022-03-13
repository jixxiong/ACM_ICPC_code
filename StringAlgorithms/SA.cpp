#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

template<size_t size>
struct SuffixArray {
    bool type[size << 1];
    int bucket[size], bucket1[size];
    int sa[size], rk[size], ht[size];
    inline bool isLMS(const int i, const bool *type) { return i > 0 && type[i] && !type[i - 1]; }
    template<class T>

    inline void inducedSort(T s, int *sa, const int len, const int sigma, const int bucketSize, bool *type, int *bucket, int *cntbuf, int *p) {
        memset(bucket, 0, sizeof(int) * sigma);
        memset(sa, -1, sizeof(int) * len);
        for (register int i = 0; i < len; i++) bucket[s[i]]++;
        cntbuf[0] = bucket[0];
        for (register int i = 1; i < sigma; i++) cntbuf[i] = cntbuf[i - 1] + bucket[i];
        for (register int i = bucketSize - 1; i >= 0; i--) sa[--cntbuf[s[p[i]]]] = p[i];
        for (register int i = 1; i < sigma; i++) cntbuf[i] = cntbuf[i - 1] + bucket[i - 1];
        for (register int i = 0; i < len; i++) if (sa[i] > 0 && !type[sa[i] - 1]) sa[cntbuf[s[sa[i] - 1]]++] = sa[i] - 1;
        cntbuf[0] = bucket[0];
        for (register int i = 1; i < sigma; i++) cntbuf[i] = cntbuf[i - 1] + bucket[i];
        for (register int i = len - 1; i >= 0; i--) if (sa[i] > 0 && type[sa[i] - 1]) sa[--cntbuf[s[sa[i] - 1]]] = sa[i] - 1;
    }
    template<typename T>
    inline void sais(T s, int *sa, int len, bool *type, int *bucket, int *bucket1, int sigma) {
        int i, j, bucketSize = 0, cnt = 0, p = -1, x, *cntbuf = bucket + sigma;
        type[len - 1] = 1;
        for (i = len - 2; i >= 0; i--) type[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && type[i + 1]);
        for (i = 1; i < len; i++) if (type[i] && !type[i - 1]) bucket1[bucketSize++] = i;
        inducedSort(s, sa, len, sigma, bucketSize, type, bucket, cntbuf, bucket1);
        for (i = bucketSize = 0; i < len; i++) if (isLMS(sa[i], type)) sa[bucketSize++] = sa[i];
        for (i = bucketSize; i < len; i++) sa[i] = -1;
        for (i = 0; i < bucketSize; i++) {
            x = sa[i];
            for (j = 0; j < len; j++) {
                if (p == -1 || s[x + j] != s[p + j] || type[x + j] != type[p + j]) { cnt++, p = x; break; }
                else if (j > 0 && (isLMS(x + j, type) || isLMS(p + j, type))) break;
            }
            x = (~x & 1 ? x >> 1 : x - 1 >> 1), sa[bucketSize + x] = cnt - 1;
        }
        for (i = j = len - 1; i >= bucketSize; i--) if (sa[i] >= 0) sa[j--] = sa[i];
        int *s1 = sa + len - bucketSize, *bucket2 = bucket1 + bucketSize;
        if (cnt < bucketSize) sais(s1, sa, bucketSize, type + len, bucket, bucket1 + bucketSize, cnt);
        else for (i = 0; i < bucketSize; i++) sa[s1[i]] = i;
        for (i = 0; i < bucketSize; i++) bucket2[i] = bucket1[sa[i]];
        inducedSort(s, sa, len, sigma, bucketSize, type, bucket, cntbuf, bucket2);
    }
    inline void getHeight(const char *s, const int len, const int *sa) {
        for (int i = 0, k = 0; i < len; i++) {
            if (rk[i] == 0) k = 0;
            else {
                if (k > 0) k--;
                int j = sa[rk[i] - 1];
                while (i + k < len && j + k < len && s[i + k] == s[j + k]) k++;
            }
            ht[rk[i]] = k;
        }
    }
    template<class T>
    inline void init(T s, const int len, const int sigma) {
        sais(s, sa, len, type, bucket, bucket1, sigma);
        for (register int i = 1; i < len; i++) rk[sa[i]] = i;
        getHeight(s, len, sa);
    }
};

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

signed main(){
	
	return 0;
}