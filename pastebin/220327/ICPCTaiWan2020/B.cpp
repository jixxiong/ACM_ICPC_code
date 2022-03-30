#include<bits/stdc++.h>
using namespace std;

int a[4];
int p[4];
int b[4];
set<int>st;

int jia(int a,int b){
	return a+b;
}
int cha(int a,int b){
	return a-b;
}
int che(int a,int b){
	return a*b;
}
auto f={&jia,&cha,&che};

void f1(int a,int b,int c,int d){
	st.insert(a+b+c+d);
	st.insert(a+b+c-d);
	st.insert(a+b+c*d);
	st.insert(a+b-c+d);
	st.insert(a+b-c-d);
	st.insert(a+b-c*d);
	st.insert(a+b*c+d);
	st.insert(a+b*c-d);
	st.insert(a+b*c*d);
	st.insert(a-b+c+d);
	st.insert(a-b+c-d);
	st.insert(a-b+c*d);
	st.insert(a-b-c+d);
	st.insert(a-b-c-d);
	st.insert(a-b-c*d);
	st.insert(a-b*c+d);
	st.insert(a-b*c-d);
	st.insert(a-b*c*d);
	st.insert(a*b+c+d);
	st.insert(a*b+c-d);
	st.insert(a*b+c*d);
	st.insert(a*b-c+d);
	st.insert(a*b-c-d);
	st.insert(a*b-c*d);
	st.insert(a*b*c+d);
	st.insert(a*b*c-d);
	st.insert(a*b*c*d);
}

void f2(int d,int b,int c){
	st.insert(b+c+d);
	st.insert(b+c-d);
	st.insert(b+c*d);
	st.insert(b-c+d);
	st.insert(b-c-d);
	st.insert(b-c*d);
	st.insert(b*c+d);
	st.insert(b*c-d);
	st.insert(b*c*d);
}

void f3(int d,int c){
	st.insert(c+d);
	st.insert(c-d);
	st.insert(c*d);
}

int main(){
	for(int i=0;i<4;++i) scanf("%d",&a[i]),p[i]=i+1;
	do{
		for(int i=0;i<4;++i) b[i]=a[p[i]-1];
		for(int i=0;i<3;++i){
			int l=0,r=0;
			for(int j=0;j<=i;++j){
				l=l*10+b[j];
			}
			for(int j=i+1;j<4;++j){
				r=r*10+b[j];
			}
			if(!(l&&r))
				continue;
			assert(l&&r);
			f3(l,r);
		}
		for(int i=0;i<4;++i){
			for(int j=i+1;j<4;++j){
				int x=0,y=0,z=0;
				for(int k=0;k<=i;++k)
					x=x*10+b[k];
				for(int k=i+1;k<=j;++k)
					y=y*10+b[k];
				for(int k=j+1;k<4;++k)
					z=z*10+b[k];
				if(!(x&&y&&z))
					continue;
				assert(x&&y&&z);
				f2(x,y,z);
			}
		}
		f1(b[0],b[1],b[2],b[3]);
	}while(next_permutation(p,p+4));
	while(*st.begin()<0) st.erase(st.begin());
	printf("%d\n",(int)st.size());
	return 0;
}