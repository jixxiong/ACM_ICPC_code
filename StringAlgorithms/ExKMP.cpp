#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

// z 函数 => s 和 s 的每一个后缀的 lcp 
struct Z:vector<int>{
	// O(n) 计算 z 函数
	Z(const char* s,int n):vector<int>(n+1){
		auto& z=(vector<int>&)*this;
		z[1]=n;
		for(int i=2,l=0,r=0;i<=n;++i){
			if(i<=r) z[i]=min(z[i-l+1],r-i+1);
			while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1]) ++z[i];
			if(i+z[i]-1>r) l=i,r=i+z[i]-1;
		}
	}
};

// ExKMP => s 的每一个后缀和 t 的 lcp
struct ExKMP:vector<int>{
	// O(n) => ExKMP
	ExKMP(const char* s,int n,const char* t,int m):vector<int>(n+1){
		auto& p=(vector<int>&)*this;
		Z z(t,m);
		for(int i=1,l=0,r=0;i<=n;++i){
			if(i<=r) p[i]=min(z[i-l+1],r-i+1);
			while(i+p[i]<=n&&s[i+p[i]]==t[p[i]+1]) ++p[i];
			if(i+p[i]-1>r) l=i,r=i+p[i]-1;
		}
	}
};

char s[20000010],t[20000010];

int main(){
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	Z z(t,m);
	ExKMP p(s,n,t,m);
	return 0; 
}