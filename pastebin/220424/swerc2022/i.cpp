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
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n,m;
    int a[N],s[N];
    int p[N],c[N],num;
    int cf[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T=1;
        while(T--)
        {
            int n,m;cin>>n>>m;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                c[++num]=(i-1)*100;
            }
            for(int i=1;i<=m;++i)
            {
                cin>>p[i];
                c[++num]=p[i];
            }
            sort(p+1,p+m+1);
            sort(c+1,c+num+1);
            num=unique(c+1,c+num+1)-c-1;
            p[m+1]=inf;
            for(int i=1;i<=n;++i)
            {
                int pos=(i-1)*100;
                int t=lower_bound(p+1,p+m+1,pos)-p;
                int len=p[t]-pos;
                if(t>1) len=min(len,pos-p[t-1]);
                int l=lower_bound(c+1,c+num+1,pos-len)-c;
                if(pos-c[l]+1>len) ++l;
                int r=lower_bound(c+1,c+num+1,pos+len)-c;
                if(l<=r) cf[l]+=a[i],cf[r+1]-=a[i];
            }
            int ans=0;
            for(int i=1;i<=num;++i)
            {
                cf[i]+=cf[i-1];
                ans=max(ans,cf[i]);
            }
            cout<<ans<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
3 3
5 10 12
300 50 50

*/