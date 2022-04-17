#include<bits/stdc++.h>
using namespace std;
#define int long long
#define eps (1e-8)
#define y1 kunmingqaq
const int N=1e5+10,mod=998244353;
int n,m,k;
struct node
{
    int x1,y1,x2,y2;
}q[N];
int c1[N],num1,c2[N],num2;
int tmp1,tmp2;
int st[N],top;
int dp[N];
bool vis[N];
inline int fast(int x,int k)
{
    int ret=1;
    while(k)
    {
        if(k&1) ret=ret*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return ret;
}
int b[N];
inline bool check(int s)
{
    for(int i=0;i<tmp1;++i) b[i]=0;
    for(int d=1;d<=k;++d) if((s>>(d-1))&1)
    {
        int tmp=0;
        for(int p=0;p<tmp2;++p)if(q[d].y1<=p+1&&p+1<=q[d].y2)
        {
            tmp|=(1<<p);
        }
        for(int i=q[d].x1-1;i<min(q[d].x2,tmp1);++i) b[i]|=tmp;
    }
    for(int i=0;i<tmp1;++i)
    {
        if(b[i]!=((1<<tmp2)-1)) return 0;
    }
    //cout<<s<<"!"<<endl;
    return 1;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)
    {
        cin>>k;
        cin>>n>>m;num1=num2=top=0;
        n=n*2+1;m=m*2+1;
        for(int i=1;i<=k;++i)
        {
            cin>>q[i].x1>>q[i].y1>>q[i].x2>>q[i].y2;
            q[i].x1=q[i].x1*2+1,q[i].y1=q[i].y1*2+1;
            if(q[i].x1-1>0)c1[++num1]=q[i].x1-1;
            if(q[i].y1-1>0)c2[++num2]=q[i].y1-1;
            if(q[i].x1+1<=n)c1[++num1]=q[i].x2+1;
            if(q[i].y2+1<=m)c2[++num2]=q[i].y2+1;
            c1[++num1]=q[i].x1,c1[++num1]=q[i].x2;
            c2[++num2]=q[i].y1,c2[++num2]=q[i].y2;
        }
        sort(c1+1,c1+num1+1);sort(c2+1,c2+num2+1);
        num1=unique(c1+1,c1+num1+1)-c1-1;
        num2=unique(c2+1,c2+num2+1)-c2-1;
        for(int i=1;i<=k;++i)
        {
            q[i].x1=lower_bound(c1+1,c1+num1+1,q[i].x1)-c1;
            q[i].x2=lower_bound(c1+1,c1+num1+1,q[i].x2)-c1;
            q[i].y1=lower_bound(c2+1,c2+num2+1,q[i].y1)-c2;
            q[i].y2=lower_bound(c2+1,c2+num2+1,q[i].y2)-c2;
        }
        tmp1=lower_bound(c1+1,c1+num1+1,n)-c1;
        tmp2=lower_bound(c2+1,c2+num2+1,m)-c2;
        int S=(1<<k);
        for(int s=0;s<S;++s)
        {
            vis[s]=0;
            dp[s]=0;
        }
        for(int s=0;s<S;++s)
        {
            if(check(s)) st[++top]=s,vis[s]=1;
        }
        if(!top)
        {
            cout<<"-1\n";continue;
        }
        
        //dp[s] 从状态s到覆盖完期望还差多少步
        for(int s=S-1;s>=0;--s)
        {
            if(vis[s]) continue;
            int tot=0;
            for(int i=0;i<k;++i) 
            {
                if(((s>>i)&1)==0)
                {
                    dp[s]+=dp[s^(1<<i)];
                    dp[s]%=mod;
                }
                else ++tot;
            }
            (dp[s]+=k)%=mod;
            dp[s]=dp[s]*fast(k-tot,mod-2)%mod;
        }
        cout<<(dp[0]%mod+mod)%mod<<'\n';
    }
    return 0;
}
/*
1
3
2 2
0 0 2 1
0 0 1 2
1 1 2 2

8
5 5
0 0 2 2
2 2 5 5
0 2 2 5
2 0 5 2
0 0 1 1
1 1 5 5
0 1 1 5
1 0 5 1

*/