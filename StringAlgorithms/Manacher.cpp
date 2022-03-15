#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

struct Manacher:vector<int>{
	// 经过处理后字符串变成 "$#1#2#3..."
	vector<int>&p; // p[i] => 以 i 为起点的最大回文半径
	int max_len; // 最大回文子串的长度
	Manacher(const char* s,int len) 
	  :vector<int>(2*len+2),p(*this),max_len(0){
		int n=2*len+1;
		string t="$#";
		for(int i=1;i<=len;++i)
			t+=s[i]+"#"s;
		for(int k=1,r=0,mid=0;k<=n;++k){
			if(k<=r) p[k]=min(p[(mid<<1)-k],r-k+1);
			while(t[k-p[k]]==t[k+p[k]]) ++p[k];
			if(p[k]+k>r) r=p[k]+k-1,mid=k;
			if(p[k]-1>max_len) max_len=p[k]-1;
		}
		vector<int>ret(len+1);
		for(int i=1;i<=len;++i)
			ret[i]=p[i]-1;
		vector<int>::operator=(ret);
	}
};

int main(){
	int n;
	scanf("%d",&n);
	string str(n+2,0);
	scanf("%s",&str[1]);
	Manacher len(&str[0],n);
	printf("%d\n",len.max_len);
	return 0; 
}