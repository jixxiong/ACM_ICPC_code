#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

// 求前缀子串的最大 border
struct Next:vector<int>{
	// 构建 next 数组 O(n)
	Next(const char* s,int n):vector<int>(n+1){
		auto&p=*this;
		for(int i=2,j=0;i<=n;++i){
			while(j&&s[i]!=s[j+1]) j=p[j];
			if(s[i]==s[j+1]) j++;
			p[i]=j;
		}
	}
};

// 输出匹配的位置 s => 文本串; t => 模式串
void kmp(const char* s,int n,const char* t,int m){
	Next nxt(t,m);
	for(int i=1,j=0;i<=n;++i){
		while(j&&s[i]!=t[j+1]) j=nxt[j];
		if(s[i]==t[j+1]) j++;
		if(j==m) { j=nxt[j]; printf("%d\n",i-m+1); }
	}
}

char s[1000010],t[1000010];

int main(){
	scanf("%s%s",s+1,t+1);
	kmp(s,strlen(s+1),t,strlen(t+1));
	return 0; 
}