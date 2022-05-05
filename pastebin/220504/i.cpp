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
    const int N=5000+10,mod=1e9+7,inf=2e9;
    int n,m,ans;
    int a[N];
    int sum[N][N],ret[N];
    set<int> q[N],t[N];
    set<int>::iterator it,it2;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            t[i].insert(0);
            t[i].insert(n+1);
            ret[i]=n*(n+1)/2;
            //cout<<t[i].size()<<"!!!!!!!!!!!!!!!!!!"<<endl;
        }
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            q[x].insert(y);
        }
        for(int i=1;i<=n;++i)
        {
            if(i!=1) t[i]=t[i-1],ret[i]=ret[i-1];
            it=q[i].begin();
            while(it!=q[i].end())
            {
                int x=*it;
                if(!sum[i][x])
                {
                    it2=t[i].lower_bound(x);
                    if((*it2)==x)
                    {
                        ++it;continue;
                    }
                    --it2;
                    int t1=*it2;
                    it2=t[i].upper_bound(x);
                    int t2=*it2;
                    ret[i]-=(x-t1)*(t2-x);
                    t[i].insert(x);
                }
                ++sum[i][x];
                ++it;
            }
            //cout<<ret[i]<<"-----"<<'\n';
            ans+=ret[i];
        }
        for(int l=1;l<n;++l)
        {
            for(int r=l+1;r<=n;++r)
            {
                it=q[l].begin();
                while(it!=q[l].end())
                {
                    int x=*it;
                    --sum[r][x];
                    
                    if(!sum[r][x])
                    {
                        //cout<<l+1<<' '<<r<<' '<<x<<"!!"<<endl;
                        it2=t[r].lower_bound(x);
                        --it2;
                        int t1=*it2;
                        it2=t[r].upper_bound(x);
                        int t2=*it2;
                        //cout<<x<<' '<<t1<<' '<<t2<<"!!"<<endl;
                        ret[r]+=(x-t1)*(t2-x);
                        t[r].erase(x);
                    }
                    ++it;
                }
                //cout<<ret[r]<<"!!"<<endl;
                ans+=ret[r];
            }
        }
        cout<<ans<<'\n';
    }   
}
signed main()
{
    red::main();
    return 0;
}
/*
3 9
1 1
2 1
3 1
3 2
3 3
1 2
1 3
2 3
2 2


*/