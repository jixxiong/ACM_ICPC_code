#include<bits/stdc++.h>
#define ll long long
#define il inline
#define ret return
using namespace std;
bool smoke_alarm1;
const int N=3e3+7;
const int Pa=998244353;
il ll read(){
	char c;
	ll x=0,f=1;
	while(!isdigit(c=getchar())){
		if(c==EOF)
			return -1321321327;
		f-=(c=='-')<<1;
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+f*(c^48);
		c=getchar();
	}
	ret x;
}
il void write(ll x,char ch='\n'){
	if(x<0)
		putchar('-');
	static char r[55];
	int cnt=0;
	do{
		int y=x%10;
		y=abs(y);
		r[++cnt]=y|48;
		x/=10;
	}while(x);
	for(int i=cnt;i;--i)
		putchar(r[i]);
	if(ch)
		putchar(ch);
}
template<class T,class T2>il void add(T& x,T2 y,int p=Pa){
	x+=y;
	if(x>=p)
		x-=p;
}
ll n,p,res,f[N][N];
struct BIT{
	ll c[N];
	BIT(){
		memset(c,0,sizeof(c));
	}
	void Add(int x,ll k){
		++x;
		for(;x<=n+1;x+=x&-x)
			add(c[x],k,p);
	}
	ll Ask(int x){
		++x;
		ll k=0;
		for(;x;x-=x&-x)
			add(k,c[x],p);
		ret k;
	}
}g[N];
int main(){
	n=read();
	p=read();
	g[2].Add(1,26);
	g[2].Add(10,p-26);
	g[3].Add(10,26);
	g[3].Add(100,p-26);
	g[4].Add(100,26);
	g[4].Add(1000,p-26);
	g[5].Add(1000,26);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j){
		f[i][j]=g[j].Ask(i);
		if(!f[i][j])
			continue;
		g[j+2].Add(i+1,25*f[i][j]%p);
		g[j+2].Add(i+10,p-25*f[i][j]%p);
		g[j+3].Add(i+10,25*f[i][j]%p);
		g[j+3].Add(i+100,p-25*f[i][j]%p);
		g[j+4].Add(i+100,25*f[i][j]%p);
		g[j+4].Add(i+1000,p-25*f[i][j]%p);
		g[j+5].Add(i+1000,25*f[i][j]%p);
	}
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            std::cout<<f[j][i]<<" \n"[j==n];
        }
    }
	for(int i=1;i<n;++i)
		add(res,f[n][i],p);
	write(res);
	ret 0;
}