#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

struct DSU:vector<int>{
	#define arr (*this)
	DSU(int n):vector<int>(n){
		for(int i=0;i<n;++i)
			arr[i]=i;
	}
	int find(int x){
		return arr[x]==x?x:(arr[x]=find(arr[x]));
	}
	void merge(int x,int y){
		int fx=find(x),fy=find(y);
		if(fx!=fy)
			arr[fx]=fy;
	}
	void clear(int n){
		if(size()<n) resize(n);
		for(int i=0;i<n;++i)
			arr[i]=i;
	}
	#undef arr
};
int main(){
    
    return 0; 
}