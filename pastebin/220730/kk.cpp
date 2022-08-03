#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=5e5+10,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,k,x,y;
    int pw[11];
    inline int exgcd(int &x,int &y,int a,int b)
    {
        if(!b){x=1,y=0;return a;}
        int g=exgcd(y,x,b,a%b);
        y-=a/b*x;
        return g;
    }
    inline int check(int x,int y,int len)
    {
        int num=x*pw[len];
        int tmp=num+((y-num%n)%n+n)%n;
        //tmp/=pw[len];
        //if(x==1) cout<<y<<' '<<tmp<<"!!"<<endl;
        if(tmp/pw[len]==x)
        {
            //cout<<x<<' '<<y<<' '<<tmp<<"!!"<<endl;
            return 1;
        }
        return 0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        int sum=1;k=1;
        pw[0]=1;
        for(int i=1;i<=10;++i) pw[i]=pw[i-1]*10;
        for(int i=2;i<=n;++i)
        {
            for(int j=1;j<=10;++j)
            {
                if(check(i-1,i,j))
                {
                    sum+=j;
                    break;
                }
            }
        }
        cout<<sum<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
aab

*/
