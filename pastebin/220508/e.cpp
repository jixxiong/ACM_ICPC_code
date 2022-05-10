#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=1e6,mod=1e9+7,inf=2e9;
    int n;
    struct node
    {
        int x,y;
        inline bool operator < (const node &t) const
        {
            return y*t.x<x*t.y;
        }
    }a[N],b[N],t1,t2;
    int num1=0,num2=0;
    inline bool cmp1(node a,node b)
    {
        int t1=a.y*b.x,t2=a.x*b.y;
        if(t1!=t2) return t1<t2;
        return a.x>b.x;
    }
    inline bool cmp2(node a,node b)
    {
        int t1=a.y*b.x,t2=a.x*b.y;
        if(t1!=t2) return t1>t2;
        return a.x<b.x;
    }
    inline bool check(node a,node b)
    {
        if(abs(a.y-b.y)<abs(a.x-b.x)) return 1;
        return 0;
    }
    bool check2(node a,node b){
        if(a.y>b.y)std::swap(a,b);
        int tp=std::max(std::abs(a.x),std::abs(a.y));
        b.y-=tp;
        return b.y-a.y<std::abs(b.x-a.x);
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            bool flag=0;
            num1=num2=0;
            for(int i=1;i<=n;++i)
            {
                int x,y;cin>>x>>y;
                if(y<=0){flag=1;continue;}
                if(x>0)
                {
                    if(y<x) flag=1;
                    a[++num1].x=x,a[num1].y=y;
                }
                else
                {
                    if(y>x&&x<0) flag=1;
                    b[++num2].x=x,b[num2].y=y;
                }
            }
            sort(a+1,a+num1+1);
            sort(b+1,b+num2+1);
            if(num1) t1=a[1];
            else t1=b[num2];
            if(num2) t2=b[1];
            else t2=a[num1];
            // flag|=check(t1,t2)|check(t2,t1);
            flag|=check2(t1,t2)|check2(t2,t1);
            if(flag) cout<<n-1<<'\n';
            else cout<<n<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
3
2
1 1
2 4
3
1 1
2 4
-1 -1
2
5 6
-5 6

*/
