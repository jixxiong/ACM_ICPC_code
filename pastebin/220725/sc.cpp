#include <bits/stdc++.h>

using namespace std::string_literals;
#define all(x) x.begin(),x.end()
#define pb emplace_back
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

// O(n) => suffix array
// str[n+1] 为最小字符
// 若对整数数组求SA应当先进行离散化
template<typename T=char,int sigma=300>
struct SA{
    std::vector<int>sa,rk,ht;
    SA(T* str,int n){
        const int SIZE=std::max(sigma,n)+2;
        sa.resize(SIZE),rk.resize(SIZE),ht.resize(SIZE);
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
                std::fill_n(&sa[0],n,-1); std::fill_n(&ct[0],m,0);
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
            for(int i=1;i<n;i++) rk[i]=t[i-1]&&!t[i]?(p[n1]=i,n1++):-1;
            IS(p);
            for(int i=0,x,y;i<n;i++) if(~(x=rk[sa[i]])){
                if(ch<1||p[x+1]-p[x]!=p[y+1]-p[y])ch++;
                else for(int j=p[x],k=p[y];j<=p[x+1];j++,k++)
                    if((s[j]<<1|t[j])!=(s[k]<<1|t[k])) { ch++; break; }
                s1[y=x]=ch;
            }
            if(ch+1<n1)sais(n1,ch+1,s1,t+n,p+n1);
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

// ST for SA and static lcp => lcp(i,j) in O(1)  
struct ST{
    std::vector<std::vector<int>>st;
    ST(std::vector<int>A):st(A.size()){ // height 
        int n=A.size()-1;
        for(int i=1;i<=n;++i){
            st[i].resize(std::__lg(n)+1);
            st[i][0]=A[i];
        }
        for(int j=1;j<=std::__lg(n);++j)
            for(int i=1;i+(1<<j)-1<=n;++i)
                st[i][j]=std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
    int qry(int l,int r){ // lcp(l,r)
        if(l==r) return -1;
        if(l>r)std::swap(l,r);
        l++;
        int s=std::__lg(r-l+1);
        return std::min(st[l][s],st[r-(1<<s)+1][s]);
    }
};

int32_t main(){
    int n; std::cin>>n;
    auto pos=Vec<int>(0,n+1);
    auto len=Vec<int>(0,n+1);
    auto ori=Vec<std::string>("",n+1);
    std::string s=" ";
    int tn=0;
    for(int i=1;i<=n;++i){
        pos[i]=(int)s.length();
        std::string t; std::cin>>t;
        s+=t;
        ori[i]=t;
        len[i]=t.length();
        tn+=len[i];
    }
    s+='$';
    SA sa(s.data(),tn);
    auto& rk=sa.rk;
    ST st(sa.ht);
    auto B=Vec<int>(0,n+1);
    std::iota(1+all(B),1);
    std::sort(1+all(B),
        [&](int i,int j){
            bool rev=false;
            if(len[i]>len[j]) std::swap(i,j),rev=true;
            int pi=pos[i],pj=pos[j];
            int k=st.qry(rk[pi],rk[pj]);
            if(k<len[i]) return rev?(s[k+pos[i]]>s[k+pos[j]]):(s[k+pos[i]]<s[k+pos[j]]);
            int lcp2=st.qry(rk[pj],rk[pj+len[i]]);
            if(len[i]+lcp2<len[j]) return rev?(s[pj+lcp2]>s[pj+len[i]+lcp2]):(s[pj+lcp2]<s[pj+len[i]+lcp2]);
            int lcp3=st.qry(rk[pj+len[j]-len[i]],rk[pi]);
            if(len[i]<=lcp3) return false;
            return rev?(s[pj+len[j]-len[i]+lcp3]>s[pi+lcp3]):(s[pj+len[j]-len[i]+lcp3]<s[pi+lcp3]);
        });
    for(int i=1;i<=n;++i){
        std::cout<<ori[B[i]];
    }
    std::cout<<"\n";
    return 0;
}