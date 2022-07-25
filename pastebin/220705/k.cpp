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
    //typedef pair<string,string> pr;
    string s;
    inline void main()
    {
        // ios::sync_with_stdio(0);
        // cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            int n;cin>>n;
            
            s="";

            int pre=0;
            for(int k=0;k<32;++k)
            {
                if((n>>k)&1)
                {
                    for(int i=pre+1;i<=k;++i)
                    {
                        s+='a';
                    }
                    pre=k;
                    s+='h';
                }
            }
            s+="ehhehnun";
            reverse(s.begin(),s.end());
            cout<<s<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
7
GALA Jojo
Aegis Ming
GALA Grevthar
GALA Aegis
GALA Guigo
GALA Grevthar
GALA TitaN


*/