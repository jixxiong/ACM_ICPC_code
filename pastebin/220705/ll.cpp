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
    const int N=1e6+10,inf=2e9;
    char s[N];
    int n;
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        int sum=0,tot=0;
        for(int i=1;i<=n;++i)
        {
            if(s[i]=='B')
            {
                int len=0;
                while(s[i-len-1]=='A'&&s[i+len+1]=='C') ++len;
                int tmp=len;
                if(i&1)
                {
                    sum+=min(tot+1,tmp);
                    if(len>tot) ++tot;
                }
                else
                {
                    sum+=min(tot+2,tmp);
                    if(len>tot+1) ++tot;
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
ABABCABCA


*/