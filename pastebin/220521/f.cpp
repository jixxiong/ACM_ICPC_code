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
    const int N=2e6+10,mod=1e9+7,inf=2e9;
    int n;
    string s;
    map<string,int> q;
    int pos[N];
    bool vis[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;cin>>skx;
        int maxn=0;
        while(skx--)
        {
        	int opt;
            cin>>opt>>s;
            if(opt==1)
            {
                ++q[s];
                maxn=max(maxn,(int)s.length());
            }
            if(opt==2) --q[s];
            if(opt==3)
            {
                int len=s.length();
                for(int i=0;i<len;++i) pos[i]=0,vis[i]=1;
                for(int i=0;i<len;++i)
                {
                    for(int k=1;k<=maxn;++k)
                    {
                        int l=i-k+1;
                        if(l<0) break;
                        string txt="";
                        for(int j=l;j<=i;++j) txt=txt+s[j];
                        if(q[txt]>0)
                        {
                            ++pos[i];
                            for(int j=l;j<=i;++j) vis[j]=0;
                        }
                    }
                }
                for(int i=0;i<len;++i)
                {
                    if(vis[i]==1) cout<<s[i];
                    while(pos[i]--)
                    {
                        cout<<"junimos";
                    }
                }
                cout<<'\n';
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

6
1 a
1 b
1 aa
1 ab
1 bb
3 aabb

*/
