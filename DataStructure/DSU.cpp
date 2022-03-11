#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

struct DSU:vector<int>{
	vector<int>&arr;
	DSU(int n):vector<int>(n),arr(*this){
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
};

int main(){
    
    return 0; 
}