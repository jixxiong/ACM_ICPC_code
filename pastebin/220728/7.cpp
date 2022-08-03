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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n,a0,k;
    char a[N],s[N];
    typedef pair<int,int> pr;
    struct seg
    {
        int ans[N<<2],sum[N<<2];
        inline void build(int l,int r,int p)
        {
            if(l==r)
            {
                ans[p]=sum[p]=a[l];
                cout<<l<<' '<<sum[p]<<' '<<a[l]<<' '<<p<<"!!"<<endl;
                sum[p]=a[l];
                cout<<sum[p]<<endl;
                return;
            }
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
            sum[p]=sum[ls(p)]+sum[rs(p)];
            ans[p]=max(ans[ls(p)]-sum[rs(p)],ans[rs(p)]);
            cout<<l<<' '<<r<<' '<<sum[ls(p)]<<' '<<sum[rs(p)]<<' '<<sum[p]<<' '<<ans[p]<<"!!"<<endl;
        }
        inline pr query(int tl,int tr,int l,int r,int p)
        {
            if(tl<=l&&r<=tr) return pr(ans[p],sum[p]);
            if(tr<=mid) return query(tl,tr,l,mid,ls(p));
            if(tl>mid) return query(tl,tr,mid+1,r,rs(p));
            pr t1=query(tl,tr,l,mid,ls(p)),t2=query(tl,tr,mid+1,r,rs(p));
            pr t;
            t.first=max(t1.first-t2.second,t2.first);
            t.second=t1.second+t2.second;
            return t;
        }
    }T;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>a0>>k;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                s[i]=s[i-1]+a[i];
            }
            T.build(1,n,1);
            int now=0,pre=1;
            bool flag=1;
            for(int i=1;i<=n;++i)
            {
                int pos=0;
                for(int j=min(now+k,n);j>=pre;--j)
                {
                    pr tmp=T.query(pre,j,1,n,1);
                    cout<<pre<<' '<<j<<' '<<tmp.first<<' '<<tmp.second<<'\n';
                    if(tmp.first<=a0)
                    {
                        pos=j;break;
                    }
                }
                if(pos==0)
                {
                    flag=0;
                    break;
                }
                a0+=s[pos]-s[pre-1];
                now=pre;
                pre=pos+1;
                if(pre>n) break;
            }
            if(!flag||pre<=n)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
6 1 4
2 2 1 1 9 3

*/
