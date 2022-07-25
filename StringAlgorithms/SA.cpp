#include <bits/stdc++.h>

using ll=long long;

template<typename T> auto Vec(T init,int s){ return std::vector(s,init); }
template<typename T,typename...L> auto Vec(T init,int s,L...l){ return std::vector(s,Vec<T>(init,l...)); }

template<typename T=int>
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
        assert(l<=r); 
        int s=std::__lg(r-l+1);
        return merge(st[s][l],st[s][r-(1<<s)+1]);
    }
};

// O(n) => suffix array
// 下标从 1 开始 str[0] 空出来，str[n+1] 会被赋值成 0, 要确保已经申请了这个内存单元否则 RE
// 若对整数数组求SA应当先进行离散化
template<typename T=char,int sigma=300>
struct SuffixArray{
    int const SIZE;
    std::vector<int>sa,rk,ht;
    SuffixArray(T* str,int n):SIZE(std::max(sigma,n)+2),sa(SIZE),rk(SIZE),ht(SIZE){
        std::vector<int>s(SIZE<<1),t(SIZE<<1),p(SIZE),cr(SIZE),ct(SIZE);
        str[++n]=0,++str;
        auto pre_work=[&](){
            int m=*std::max_element(str,str+n);
            std::fill_n(&rk[0],m+1,0);
            for(int i=0;i<n;i++) rk[(int)str[i]]=1;
            for(int i=0;i<m;i++) rk[i+1]+=rk[i];
            for(int i=0;i<n;i++) s[i]=rk[(int)str[i]]-1;
            return rk[m];
        };
        int m=pre_work();
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
        sais(n,m,s.data(),t.data(),p.data());
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
// 下标从 1 开始 str[0] 空出来，str[n+1] 会被赋值成 0, 要确保已经申请了这个内存单元否则 RE
// O(nlogn) => ST 表预处理 SA 的 ht 数组的区间最小值 => 求 lcp 
// 若对整数数组求SA应当先进行离散化
template<typename T=char,int sigma=300>
struct SA_LCP:SuffixArray<T,sigma>,SparseTable<int>{
    SA_LCP(T* str,int n):
        SuffixArray<T,sigma>(str,n),
        SparseTable<int>(SuffixArray<T,sigma>::ht,
            [](int x,int y){ return std::min(x,y); }
        ){
    }
    // 求排名第 l 的后缀和第 r 的后缀的 lcp
    int lcp(int l,int r){
        assert(l!=r);
        if(l>r)std::swap(l,r);
        return get(l+1,r);
    }
};

int32_t main(){
    // 串长为 n
    int n; std::cin>>n;
    // 读入串 s
    std::string s; std::cin>>s; 
    // 调整一下 s，下标从 1 开始
    // 并确保 s[n+1] 的空间申请了
    s=" "+s+" ";
    // 构建 SA
    SA_LCP sa(s.data(),n);
    // q 次询问
    int q; std::cin>>q;
    while(q--){
        // 求后缀 l 和后缀 r 的 lcp
        int l,r; std::cin>>l>>r;
        std::cout<<sa.lcp(sa.rk[l],sa.rk[r])<<'\n';
    }
    return 0;
}
