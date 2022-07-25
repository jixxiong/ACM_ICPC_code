#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=2e6+10,inf=2e9,mod=998244353;
    int n,m;
    string s[N];
    inline bool cmp(string a,string b)
    {
        return a+b<b+a;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>s[i];
        }
        sort(s+1,s+n+1,cmp);
        for(int i=1;i<=n;++i) cout<<s[i];
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
5
1010
11
*/
