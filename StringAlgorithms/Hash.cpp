#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

// 单hash; O(1) 求字串 hash; O(n) 预处理
struct Hash{
	const static int p=1123456793;
	const static int b=233;
	int n; vector<int>pw,f;
	Hash(char* s,int n):n(n),pw(n+1),f(n+1){
		pw[0]=1;
		for(int i=1;i<=n;++i){
			pw[i]=(ll)pw[i-1]*b%p;
			f[i]=((ll)f[i-1]*b+s[i])%p;
		}
	}
	int get(int l,int r){
		return (f[r]-(ll)f[l-1]*pw[r-l+1]%p+p)%p;
	}
};

// 双hash; O(1) 求子串 hash <= O(n) 预处理
struct DoubleHash{
	const static int p1=1123456969,p2=1123456793;
	const static int b1=233,b2=241;
	int n; vector<int>pw1,pw2,f1,f2;
	DoubleHash(char* s,int n):n(n),pw1(n+1),pw2(n+1),f1(n+1),f2(n+1){
		pw1[0]=pw2[0]=1;
		for(int i=1;i<=n;++i){
			pw1[i]=(ll)pw1[i-1]*b1%p1;
			pw2[i]=(ll)pw2[i-1]*b2%p2;
			f1[i]=((ll)f1[i-1]*b1+s[i])%p1;
			f2[i]=((ll)f2[i-1]*b2+s[i])%p2;
		}
	}
	int get(int l,int r,int t){
		if(t==1) return (f1[r]-(ll)f1[l-1]*pw1[r-l+1]%p1+p1)%p1;
		else return (f2[r]-(ll)f2[l-1]*pw2[r-l+1]%p2+p2)%p2;
	}
	pair<int,int>get(int l,int r){
		return {get(l,r,1),get(l,r,2)};
	}
};
