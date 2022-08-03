#include<bits/stdc++.h>
using namespace std;
namespace fastIO{ 
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    //fread->read 
    bool IOerror=0; 
    inline char nc(){ 
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
        if (p1==pend){ 
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
            if (pend==p1){IOerror=1;return -1;} 
            //{printf("IO error!\n");system("pause");for (;;);exit(0);} 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
    inline void read(int &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(ll &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(double &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (ch=='.'){ 
            double tmp=1; ch=nc(); 
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0'); 
        } 
        if (sign)x=-x; 
    } 
    inline void read(char *s){ 
        char ch=nc(); 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch; 
        *s=0; 
    } 
    inline void read(char &c){ 
        for (c=nc();blank(c);c=nc()); 
        if (IOerror){c=-1;return;} 
    } 
    //getchar->read 
    inline void read1(int &x){ 
        char ch;int bo=0;x=0; 
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
        if (bo)x=-x; 
    } 
    inline void read1(ll &x){ 
        char ch;int bo=0;x=0; 
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
        if (bo)x=-x; 
    } 
    inline void read1(double &x){ 
        char ch;int bo=0;x=0; 
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
        if (ch=='.'){ 
            double tmp=1; 
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar()); 
        } 
        if (bo)x=-x; 
    } 
    inline void read1(char *s){ 
        char ch=getchar(); 
        for (;blank(ch);ch=getchar()); 
        for (;!blank(ch);ch=getchar())*s++=ch; 
        *s=0; 
    } 
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());} 
    //scanf->read 
    inline void read2(int &x){scanf("%d",&x);} 
    inline void read2(ll &x){ 
        #ifdef _WIN32 
            scanf("%I64d",&x); 
        #else 
        #ifdef __linux 
            scanf("%lld",&x); 
        #else 
            puts("error:can't recognize the system!"); 
        #endif 
        #endif 
    } 
    inline void read2(double &x){scanf("%lf",&x);} 
    inline void read2(char *s){scanf("%s",s);} 
    inline void read2(char &c){scanf(" %c",&c);} 
    //inline void readln2(char *s){gets(s);} 
    //fwrite->write 
    struct Ostream_fwrite{ 
        char *buf,*p1,*pend; 
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;} 
        void out(char ch){ 
            if (p1==pend){ 
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf; 
            } 
            *p1++=ch; 
        } 
        void print(int x){ 
            static char s[15],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); 
        } 
        void println(int x){ 
            static char s[15],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); out('\n'); 
        } 
        void print(ll x){ 
            static char s[25],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); 
        } 
        void println(ll x){ 
            static char s[25],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); out('\n'); 
        } 
        void print(double x,int y){ 
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000, 
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL, 
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL}; 
            if (x<-1e-12)out('-'),x=-x;x*=mul[y]; 
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1; 
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2); 
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];++i) out('0'); print(x3);} 
        } 
        void println(double x,int y){print(x,y);out('\n');} 
        void print(char *s){while (*s)out(*s++);} 
        void println(char *s){while (*s)out(*s++);out('\n');} 
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}} 
        ~Ostream_fwrite(){flush();} 
    }Ostream; 
    inline void print(int x){Ostream.print(x);} 
    inline void println(int x){Ostream.println(x);} 
    inline void print(char x){Ostream.out(x);} 
    inline void println(char x){Ostream.out(x);Ostream.out('\n');} 
    inline void print(ll x){Ostream.print(x);} 
    inline void println(ll x){Ostream.println(x);} 
    inline void print(double x,int y){Ostream.print(x,y);} 
    inline void println(double x,int y){Ostream.println(x,y);} 
    inline void print(char *s){Ostream.print(s);} 
    inline void println(char *s){Ostream.println(s);} 
    inline void println(){Ostream.out('\n');} 
    inline void flush(){Ostream.flush();} 
    //puts->write 
    char Out[OUT_SIZE],*o=Out; 
    inline void print1(int x){ 
        static char buf[15]; 
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
        while(x)*p1++=x%10+'0',x/=10; 
        while(p1--!=buf)*o++=*p1; 
    } 
    inline void println1(int x){print1(x);*o++='\n';} 
    inline void print1(ll x){ 
        static char buf[25]; 
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
        while(x)*p1++=x%10+'0',x/=10; 
        while(p1--!=buf)*o++=*p1; 
    } 
    inline void println1(ll x){print1(x);*o++='\n';} 
    inline void print1(char c){*o++=c;} 
    inline void println1(char c){*o++=c;*o++='\n';} 
    inline void print1(char *s){while (*s)*o++=*s++;} 
    inline void println1(char *s){print1(s);*o++='\n';} 
    inline void println1(){*o++='\n';} 
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}} 
    struct puts_write{ 
        ~puts_write(){flush1();} 
    }_puts; 
    inline void print2(int x){printf("%d",x);} 
    inline void println2(int x){printf("%d\n",x);} 
    inline void print2(char x){printf("%c",x);} 
    inline void println2(char x){printf("%c\n",x);} 
    inline void print2(ll x){ 
        #ifdef _WIN32 
            printf("%I64d",x); 
        #else 
        #ifdef __linux 
            printf("%lld",x); 
        #else 
            puts("error:can't recognize the system!"); 
        #endif 
        #endif 
    } 
    inline void println2(ll x){print2(x);printf("\n");} 
    inline void println2(){printf("\n");} 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 
using namespace fastIO; 
namespace red{
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=2e6+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m;
    int k,p;
    int st,ed;
    typedef pair<long long,int> pr;
    vector<pr> eg[N],gg[N];
    int dep[N];
    inline void dfs(int now,int fa)
    {
        dep[now]=dep[fa]+1;
        if(dep[now]-k>0) gg[now].emplace_back(pr(n+dep[now]-k,p));
        if(dep[now]+k<=n) gg[now].emplace_back(pr(n+dep[now]+k,p));
        gg[n+dep[now]].emplace_back(now,0);
        for(auto tmp:eg[now])
        {
            int t=tmp.first,v=tmp.second;
            if(t==fa) continue;
            dfs(t,now);
        }
    }
    long long dis[N];
    bool vis[N];
    priority_queue<pr,vector<pr>,greater<pr> > qq;
    inline void spfa()
    {
        dis[st]=0;
        qq.push(pr(0,st));
        while(!qq.empty())
        {
            int now=qq.top().second;
            qq.pop();
            if(vis[now]) continue;
            vis[now]=1;
            for(auto tmp:gg[now])
            {
                int t=tmp.first,v=tmp.second;
                if(dis[t]>dis[now]+v)
                {
                    dis[t]=dis[now]+v;
                    qq.push(pr(dis[t],t));
                }
            }
        }
    }
    inline void init()
    {
        for(int i=1;i<=n*2;++i)
        {
            eg[i].clear(); eg[i].shrink_to_fit();
            gg[i].clear(); gg[i].shrink_to_fit();
            vis[i]=0;
            dis[i]=1e18;
        }
    }
    inline void main()
    {
        // ios::sync_with_stdio(false);
        // cin.tie(0);cout.tie(0);
        int qwq;
        read(qwq);
        while(qwq--)
        {
            read(n);
            init();
            for(int i=1;i<n;++i)
            {
                int x,y,z;
                read(x);read(y);read(z);
                eg[x].emplace_back(pr(y,z));
                eg[y].emplace_back(pr(x,z));
                gg[x].emplace_back(pr(y,z));
                gg[y].emplace_back(pr(x,z));
            }
            read(k);read(p);
            read(st);read(ed);
            dfs(1,0);
            spfa();
            println(dis[ed]);
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
6
6 1 2
3 5 2
2 4 6
5 2 2
5 6 20
3 8
6 5
6
6 1 2
3 5 2
2 4 6
5 2 2
5 6 20
3 8
6 5
6
6 1 2
3 5 2
2 4 6
5 2 2
5 6 20
3 8
4 3

*/