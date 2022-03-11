#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

struct Manacher{
	int n; vector<int>p; string t; // p[i] => 以 i 为起点的最大回文半径
	int max_len; // 最大回文子串的长度
	Manacher(const char* s,int len):n(2*len+1),p(n+1),t("$#"),max_len(0){
		for(int i=1;i<=len;++i)
			t+=s[i]+"#"s;
		for(int k=1,r=0,mid=0;k<=n;++k){
			if(k<=r) p[k]=min(p[(mid<<1)-k],r-k+1);
			while(t[k-p[k]]==t[k+p[k]]) ++p[k];
			if(p[k]+k>r) r=p[k]+k-1,mid=k;
			if(p[k]>max_len) max_len=p[k];
		}
		--max_len;
	}
};

int main(){
    string str;
    cin>>str;
	printf("%d\n",Manacher(str.c_str(),str.length()).max_len);
	return 0; 
}