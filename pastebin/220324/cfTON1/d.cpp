#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); }
#endif
void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
#define int long long
#define LD long double
#define ull unsigned long long
using namespace std;
int T,n,ans=0x3f3f3f3f3f3f3f3f;
int MUL(int a,int b,int p) //a*b%p
{
	int x=(LD)a/p*b;
	return ((ull)a*b-(ull)x*p+p)%p;
}
int POW(int a,int b,int p) //a^b%p
{
	if(!b) return 1;
	if(b==1) return a;
	int sum=POW(a,b/2,p);
	if(b%2) return MUL(MUL(sum,sum,p),a,p);
	return MUL(sum,sum,p);
}
int MIN(int x,int y)
{
	return x<y?x:y;
}
int ABS(int x)
{
	return x>0?x:-x;
}
//__builtin_ctzll(x) 函数用于求x在二进制中末尾0的个数
int gcd(int x,int y)
{
	if(!x) return y;
	if(!y) return x;
	int t=__builtin_ctzll(x|y);
	x>>=__builtin_ctzll(x);
	do
	{
		y>>=__builtin_ctzll(y);
		if(x>y) swap(x,y);
		y-=x;
	}while(y);
	return x<<t;
}
int f(int x,int c,int p)
{
	return (MUL(x,x,p)+c)%p;
}
bool MR(int x)
{
	if(x==0||x==1) return false;
	if(x==2) return true;
	if(x%2==0) return false;
	int p=x-1,q=0;
	while(p%2==0) q++,p/=2;
	for(int i=1;i<=10;i++)
	{
		int a=rand()%(x-1)+1;
		if(POW(a,x-1,x)!=1) return false;
		int lst=1;
		for(int j=0;j<q;j++)
		{
			int t=POW(a,(1ll<<j)*p,x);
			if(t==1&&lst!=1&&lst!=x-1) return false;
			lst=t;
		}
		if(lst!=1&&lst!=x-1) return false;
	}
	return true;
}
int find(int x)
{
	if(x%2==0) return 2;
	if(MR(x)) return x;
	int t=rand()%(x+1);
	int a=t,b=t;
	int c=rand()%(x+1);
	while(1)
	{
		a=f(a,c,x),b=f(f(b,c,x),c,x);
		int d=gcd(ABS(a-b),x);
		if(d>1&&d<x) return d;
		if(a==b) return find(x);
	}
}
void PR(int x)
{
	if(x<=1) return;
	if(MR(x))
	{
		ans=MIN(ans,x);
		return;
	}
	int y=find(x);
	PR(y),PR(x/y);
}

signed main(){
    srand(time(0));
    int T; cin>>T;
    while(T--){
        ll n; cin>>n;
        auto check=[&](ll k){
            return 2*n/k-k+1>=0;
        };
        if(n&1){
            cout<<"2\n";
            continue;
        }
        ll nn=n,pw=1;
        while(nn%2==0) nn>>=1,pw<<=1;
        if(pw!=1&&check(pw*2)){
            cout<<pw*2<<'\n';
            continue;
        }
        if(nn==1){
            cout<<"-1\n";
            continue;
        }else{
            cout<<nn<<endl;
            // ans=0x3f3f3f3f3f3f3f3f,PR(nn);
            // if(check(ans))
            //     cout<<ans<<'\n';
            // else
            //     cout<<"-1\n";
        }
    }
    return 0; 
}