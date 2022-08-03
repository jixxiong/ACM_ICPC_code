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
#define eps (1e-15)
    const int N=5e5+50+10,mod=998244353,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m,num;
    int fac[N],inv[N];
    int f[N],str[N];
    vector<int> g[N];
    inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
    inline void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y) return;
        str[y]+=str[x];
        f[x]=y;
    }
    inline int fast(int x,int k)
    {
        int ret=1;
        while(k)
        {
            if(k&1) ret=1ll*ret*x%mod;
            x=1ll*x*x%mod;
            k>>=1;
        }
        return ret;
    }
    namespace NTT
    {
        const int g=3,gi=332748118;
        int limit=1,len;
        int pos[N*4];
        inline vector<int> ntt(vector<int> a,int inv)
        {
            for(int i=0;i<limit;++i)
                if(i<pos[i]) swap(a[i],a[pos[i]]);
            for(int mid=1;mid<limit;mid<<=1)
            {
                int Wn=fast(inv?g:gi,(mod-1)/(mid<<1));
                for(int r=mid<<1,j=0;j<limit;j+=r)
                {
                    int w=1;
                    for(int k=0;k<mid;++k,w=1ll*w*Wn%mod)
                    {
                        int x=a[j+k],y=1ll*w*a[j+k+mid]%mod;
                        a[j+k]=(x+y)%mod;
                        a[j+k+mid]=(x-y+mod)%mod;
                    }
                }
            }
            if(inv) return a;
            inv=fast(limit,mod-2);
            for(int i=0;i<limit;++i) a[i]=1ll*a[i]*inv%mod;
            return a;
        }
        inline vector<int> mul(vector<int> a,vector<int> b,int n=-1,int m=-1)
        {
            if(n==-1) n=a.size();
            if(m==-1) m=b.size();
            limit=1,len=0;
            while(limit<n+m) limit<<=1,++len;
            a.resize(limit,0),b.resize(limit,0);
            for(int i=0;i<limit;++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
            a=ntt(a,1),b=ntt(b,1);
            for(int i=0;i<limit;++i) a[i]=1ll*a[i]*b[i]%mod;
            vector<int> c=ntt(a,0);
            c.resize(n+m-1);
            return c;
        }
    }
    inline void init(int n=5e5+50)
    {
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
        inv[n]=fast(fac[n],mod-2);
        for(int i=n-1;i>=1;--i) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    }
    inline int C(int n,int m)
    {
        if(n<m||m<0) return 0;
        return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
    }
    inline vector<int> solve(int l,int r)
    {
        if(l>r) return vector<int>();
        if(l==r) return g[l];
        int mid=(l+r)>>1;
        return NTT::mul(solve(l,mid),solve(mid+1,r));
    }
    inline void main()
    {
        int qwq;
        // qwq=10;
        read(qwq);
        init();
        while(qwq--)
        {
            // n=500000,m=10;
            read(n);read(m);
            for(int i=1;i<=n;++i) f[i]=i,str[i]=1;
            for(int i=1;i<=n;++i)
            {
                int x;
                // x=i;
                read(x);
                merge(i,x);
            }
            // if(m>n/2) {
            //     println(0);
            //     continue;
            // }
            num=0;
            for(int i=1;i<=n;++i) if(find(i)==i)
            {
                if(str[i]==1) continue;
                int sum=str[i];
                ++num;
                g[num].resize(sum+1);
                g[num][0]=1;
                for(int k=1;k<=str[i];++k)
                {
                    g[num][k]=((C(sum-k-1,k-1)+C(sum-k,k))%mod);
                }
            }
            vector<int> h=solve(1,num);
            if((int)h.size()>=m+1) println(h[m]);
            else println(0);
        }
        // cout<<clock()-st<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
第二次被卡常

6
5 1
5 3 2 1 4
5 3
2 5 1 3 4
10 3
10 9 3 8 6 4 5 7 2 1
5 1
5 3 2 1 4
5 2
2 5 1 3 4
10 3
10 9 3 8 6 4 5 7 2 1

*/

// #include <bits/stdc++.h>

// #define all(x) x.begin(),x.end()
// #define pb emplace_back
// #define int long long
// using ld=long double;
// using ll=long long;

// #ifndef LOCAL_DEBUG
// __attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
// #define du(...) 4933
// #else
// void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
// #define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
// #endif

// template<typename T>using vc=std::vector<T>;
// template<typename T>using vvc=std::vector<vc<T>>;
// template<typename T>using vvvc=std::vector<vvc<T>>;
// template<typename T>using vvvvc=std::vector<vvvc<T>>;

// using i32=int32_t;
// using i64=int64_t;
// using i128=__int128;
// ld const EPS=1e-8;
// ld const PI=std::acos((ld)-1.0);
// ll const mod=998244353;

// namespace MathBase{
//     i32 qpow(i32 x,i32 y,i32 p=mod){
//         if(y==0) return 1;
//         i32 ret=1;
//         while(y){
//             if(y&1) ret=(i64)ret*x%p;
//             x=(i64)x*x%p;
//             y>>=1;
//         }
//         return ret;
//     }
// };
// using MathBase::qpow;

// struct Conbi{
//     vc<i32>fac,inv;
//     Conbi(i32 n):fac(n+1),inv(n+1){
//         fac[0]=1;
//         for(i32 i=1;i<=n;++i) fac[i]=(i64)fac[i-1]*i%mod;
//         inv[n]=qpow(fac[n],mod-2);
//         for(i32 i=n-1;i>=0;--i) inv[i]=(i64)inv[i+1]*(i+1)%mod;
//     }
//     i32 operator()(i32 x,i32 y){
//         if(y<0||x<0||y>x) return 0;
//         return (i64)fac[x]*inv[y]%mod*inv[x-y]%mod;
//     }
// };

// i32 fac[500100],inv[500100];

// void init(i32 n=5e5+50){
//     fac[0]=inv[0]=1;
//     for(i32 i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
//     inv[n]=qpow(fac[n],mod-2);
//     for(i32 i=n-1;i>=1;--i) inv[i]=1ll*inv[i+1]*(i+1)%mod;
// }

// i32 C(i32 n,i32 m)
// {
//     if(n<m||m<0) return 0;
//     return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
// }

// std::mt19937 rng(4933);

// int32_t main(){
//     init();
//     i32 T=1000;
//     Conbi conbi(500000);
//     while(true){
//         i32 x=rng()%500000,y=rng()%500000;
//         std::cout<<C(x,y)<<' '<<conbi(x,y)<<'\n';
//         assert(C(x,y)==conbi(x,y));
//     }
//     return 0;
// }