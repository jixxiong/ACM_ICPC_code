#include <bits/stdc++.h>

using namespace std::string_literals;
#define all(x) x.begin(),x.end()
#define pb emplace_back
// #define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T> auto Vec(T init,int s){ return std::vector(s,init); }
template<typename T,typename...L> auto Vec(T init,int s,L...l){ return std::vector(s,Vec<T>(init,l...)); }

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

// ST for SA and static lcp => lcp(i,j) in O(1)
template<typename T>
struct SparseTable{
    std::vector<std::vector<T>>st;
    std::function<T(T,T)> merge;
    template<typename Merger>
    SparseTable(std::vector<T>const&A,Merger const& merge)
        :st(Vec<T>(0,std::__lg(A.size())+1,A.size())),merge(merge){
        int n=A.size()-1; st[0]=A;
        for(int j=1;j<=std::__lg(n);++j){
            for(int i=1;i+(1<<j)-1<=n;++i){
                st[j][i]=merge(st[j-1][i],st[j-1][i+(1<<(j-1))]);
            }
        }
    }
    T get(int l,int r){
        assert(l<=r); int s=std::__lg(r-l+1);
        return merge(st[s][l],st[s][r-(1<<s)+1]);
    }
};

// O(n) => suffix array
// str[n+1] 为最小字符
// 若对整数数组求SA应当先进行离散化
template<typename T=char,int sigma=300>
struct SA{
    int const SIZE;
    std::vector<int>sa,rk,ht;
    SA(T* str,int n):SIZE(std::max(sigma,n)+2),sa(SIZE),rk(SIZE),ht(SIZE){
        std::vector<int>s(SIZE<<1),t(SIZE<<1),p(SIZE),cr(SIZE),ct(SIZE);
        str[++n]=0,++str;
        int m=[&](){
            int m=*std::max_element(str,str+n);
            std::fill_n(&rk[0],m+1,0);
            for (int i=0;i<n;i++) rk[(int)str[i]]=1;
            for (int i=0;i<m;i++) rk[i+1]+=rk[i];
            for (int i=0;i<n;i++) s[i]=rk[(int)str[i]]-1;
            return rk[m];
        }();
        std::function<void(int,int,int*,int*,int*)>sais=[&](int n,int m,int* s,int* t,int* p) {
            int n1=t[n-1]=0,ch=rk[0]=-1,*s1=s+n;
            auto ps=[&](int x){ sa[cr[s[x]]--]=x; };
            auto pl=[&](int x){ sa[cr[s[x]]++]=x; };
            auto IS=[&](int* v){
                std::fill_n(sa.data(),n,-1); std::fill_n(ct.data(),m,0);
                for(int i=0;i<n;i++) ct[s[i]]++;
                for(int i=1;i<m;i++) ct[i]+=ct[i-1];
                for(int i=0;i<m;i++) cr[i]=ct[i]-1;
                for(int i=n1-1;~i;i--) ps(v[i]);
                for(int i=1;i<m;i++) cr[i]=ct[i-1];
                for(int i=0;i<n;i++) if(sa[i]>0&&t[sa[i]-1]) pl(sa[i]-1);
                for(int i=0;i<m;i++) cr[i]=ct[i]-1;
                for(int i=n-1;~i;i--) if(sa[i]>0&&!t[sa[i]-1]) ps(sa[i]-1);
            };
            for(int i=n-2;~i;i--) t[i]=s[i]==s[i+1]?t[i+1]:s[i]>s[i+1];
            for(int i=1;i<n;i++) rk[i]=(t[i-1]&&!t[i])?(p[n1]=i,n1++):-1;
            IS(p);
            for(int i=0,x,y;i<n;i++){
                if(~(x=rk[sa[i]])){
                    if(ch<1||p[x+1]-p[x]!=p[y+1]-p[y]){
                        ch++;
                    }else for(int j=p[x],k=p[y];j<=p[x+1];j++,k++){
                        if((s[j]<<1|t[j])!=(s[k]<<1|t[k])){
                            ch++; 
                            break; 
                        }
                    }
                    s1[y=x]=ch;
                }
            }
            if(ch+1<n1) sais(n1,ch+1,s1,t+n,p+n1);
            else for(int i=0;i<n1;i++) sa[s1[i]]=i;
            for(int i=0;i<n1;i++) s1[i]=p[sa[i]];
            IS(s1);
        };
        sais(n,m,&s[0],&t[0],&p[0]);
        for (int i=0;i<n;i++) rk[sa[i]]=i;
        for (int i=0,h=ht[0]=0;i<n-1;i++) {
            int j=sa[rk[i]-1];
            while (i+h<n&&j+h<n&&s[i+h]==s[j+h]) h++;
            if ((ht[rk[i]]=h)) h--;
        }
        for(int i=n-1;i>=1;--i) ++sa[i],rk[i]=rk[i-1];
        sa.resize(n+1),ht.resize(n+1),rk.resize(n+1);
    }
};

// O(n) => suffix array
// str[n+1] 为最小字符
// 若对整数数组求SA应当先进行离散化
template<typename T=char,int sigma=300>
struct SA_LCP:SA<T,sigma>,SparseTable<int>{
    SA_LCP(T* str,int n):
        SA<T,sigma>(str,n),
        SparseTable<int>(SA<T,sigma>::ht,
            [](int x,int y){ return std::min(x,y); }
        ){
    }
    int lcp(int l,int r){ // lcp(l,r)
        assert(l!=r);
        if(l>r)std::swap(l,r);
        l++; int s=std::__lg(r-l+1);
        return merge(st[s][l],st[s][r-(1<<s)+1]);
    }
};

char S[1100010];
int top=1;

int32_t main(){
    int n,m,k; std::cin>>n>>m>>k;
    std::string tmp_s;
    std::cin>>tmp_s; 
    for(auto ch:tmp_s){
        S[top++]=ch;
    }
    S[top++]='$'; // I'm fucked up
    auto A=Vec<ll>(0,m+1);
    for(int i=1;i<=m;++i){
        std::cin>>A[i];
        A[i]+=A[i-1];
    }
    SparseTable<ll> st_q(A,[](ll x,ll y){ return std::max(x,y); });
    for(int i=1;i<=k;++i){
        std::cin>>tmp_s;
        for(auto ch:tmp_s){
            S[top++]=ch;
        }
    }
    SA_LCP sa(S,n+m*k+1);
    auto& rk=sa.rk;
    auto pre=Vec<int>(0,n+m*k+2);
    for(int i=1;i<=n;++i){
        pre[rk[i]]++;
    }
    auto lst=Vec<int>(0,n+m*k+3);
    auto nxt=Vec<int>(0,n+m*k+3);
    lst[0]=0; nxt[n+m*k+2]=n+m*k+2;
    for(int i=1;i<=n+m*k+1;++i){
        if(pre[i]) lst[i]=i;
        else lst[i]=lst[i-1];
    }
    for(int i=n+m*k+1;i>=1;--i){
        if(pre[i]) nxt[i]=i;
        else nxt[i]=nxt[i+1];
    }
    for(int i=1;i<=k;++i){
        ll ans=0;
        for(int ip=1;ip<=m;++ip){
            int p=n+(i-1)*m+ip+1;
            int rkp=rk[p];
            int l=0,r=rkp+1;
            int lcp=0;
            l=lst[rkp];
            if(l!=0) lcp=std::max(lcp,sa.lcp(l,rkp));
            r=nxt[rkp];
            if(r!=n+m*k+2) lcp=std::max(lcp,sa.lcp(rkp,r));
            r=std::min(m,ip+lcp-1);
            du(i,ip,r);
            if(r>=ip){
                ans=std::max(ans,st_q.get(ip,r)-A[ip-1]);
            }
        }
        std::cout<<ans<<'\n';
    }
    return 0;
}