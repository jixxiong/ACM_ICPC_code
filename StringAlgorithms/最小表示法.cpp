#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

// 最小表示法 => 求最小循环串
template<typename T>
int Solution(T* s, int n) {
	int i=1,ans;
	while(i<=n){
		int j=i,k=i+1;
		while(k<=n*2&&s[j]<=s[k]) j=s[j]==s[k++]?j+1:i;
		while(i<=j) i+=k-j,ans=i<=n?i:ans;
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int>A(n+1);
	for(int i=1;i<=n;++i) 
		scanf("%d",&A[i]);
	int p=Solution(&A[0],n);
	for(int i=p;i<=n;++i) 
		printf("%d ",A[i]);
	for(int i=1;i<p;++i) 
		printf("%d ",A[i]);
	puts("");
	return 0;
}


/*

input:

10
10 9 8 7 6 5 4 3 2 1

output:

1 10 9 8 7 6 5 4 3 2

*/