#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
    #define de(...) 4933
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

struct SegTree{
    std::vector<char>tr[2];
    std::vector<char>ls[2],rs[2];
    std::vector<char>tg;
    void pushup(int ni,int nl,int mid,int nr){
        tr[0][ni]=tr[0][ni<<1]|tr[0][ni<<1|1];
        tr[1][ni]=tr[1][ni<<1]|tr[1][ni<<1|1];
        char ok=(rs[0][ni<<1]&ls[1][ni<<1|1])|(rs[1][ni<<1]&ls[0][ni<<1|1]);
        ls[0][ni]=ls[0][ni<<1]&(ok);
        ls[1][ni]=ls[1][ni<<1]&(ok);
        rs[0][ni]=rs[0][ni<<1|1]&(ok);
        rs[1][ni]=rs[1][ni<<1|1]&(ok);
    }
    void pushdown(int ni){
        if(tg[ni]){
            tg[ni<<1]^=1;tg[ni<<1|1]^=1;
            std::swap(tr[0][ni<<1],tr[1][ni<<1]);
            std::swap(tr[0][ni<<1|1],tr[1][ni<<1|1]);
            std::swap(ls[0][ni<<1],ls[1][ni<<1]);
            std::swap(ls[0][ni<<1|1],ls[1][ni<<1|1]);
            std::swap(rs[0][ni<<1],rs[1][ni<<1]);
            std::swap(rs[0][ni<<1|1],rs[1][ni<<1|1]);
            tg[ni]=0;
        }
    }
    void build(int ni,int nl,int nr,std::string& s){
        if(nl==nr){
            tr[s[nl]-'0'][ni]=true;
            rs[s[nl]-'0'][ni]=ls[s[nl]-'0'][ni]=true;
            return ;
        }
        int mid=(nl+nr)>>1;
        build(ni<<1,nl,mid,s);
        build(ni<<1|1,mid+1,nr,s);
        pushup(ni,nl,mid,nr);
    }
    SegTree(std::string& s){
        int n=(int)s.length()-1;
        tr[0].resize(n<<2|3); tr[1].resize(n<<2|3); tg.resize(n<<2|3);
        ls[0].resize(n<<2|3); ls[1].resize(n<<2|3);
        rs[0].resize(n<<2|3); rs[1].resize(n<<2|3);
        build(1,1,n,s);
    }
    void merge(std::array<char,2>&x,std::array<char,2>const&y){
        x[0]|=y[0],x[1]|=y[1];
    }
    void merge_seq(std::array<std::array<char,2>,2>&x,std::array<std::array<char,2>,2>const&y){
        char ok=(x[1][0]&y[0][1])|(x[1][1]&y[0][0]);
        x[0][0]&=ok;
        x[0][1]&=ok;
        x[1][0]=(y[1][0]&ok);
        x[1][1]=(y[1][1]&ok);
    }
    std::array<char,2> get(int ni,int nl,int nr,int l,int r){
        if(l<=nl&&nr<=r){
            return std::array<char,2>{tr[0][ni],tr[1][ni]};
        }
        pushdown(ni);
        int mid=(nl+nr)>>1;
        std::array<char,2>ret{0,0};
        if(l<=mid) merge(ret,get(ni<<1,nl,mid,l,r));
        if(r> mid) merge(ret,get(ni<<1|1,mid+1,nr,l,r));
        return ret;
    }
    std::array<std::array<char,2>,2> is_seq(int ni,int nl,int nr,int l,int r){
        if(l<=nl&&nr<=r){
            return std::array<std::array<char,2>,2>{std::array<char,2>{ls[0][ni],ls[1][ni]},std::array<char,2>{rs[0][ni],rs[1][ni]}};
        }
        pushdown(ni);
        int mid=(nl+nr)>>1;
        if(l<=mid){
            auto ret=is_seq(ni<<1,nl,mid,l,r);
            if(r>mid) merge_seq(ret,is_seq(ni<<1|1,mid+1,nr,l,r));
            return ret;
        } else return is_seq(ni<<1|1,mid+1,nr,l,r);
    }
    void update(int ni,int nl,int nr,int l,int r){
        if(l<=nl&&nr<=r){
            tg[ni]^=1;
            std::swap(tr[0][ni],tr[1][ni]);
            std::swap(ls[0][ni],ls[1][ni]);
            std::swap(rs[0][ni],rs[1][ni]);
            return ;
        }
        pushdown(ni);
        int mid=(nl+nr)>>1;
        if(l<=mid) update(ni<<1,nl,mid,l,r);
        if(r> mid) update(ni<<1|1,mid+1,nr,l,r);
        pushup(ni,nl,mid,nr);
    }

};

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::string s,t; std::cin>>s>>t; s=' '+s; t=' '+t;
        bool fail=false;
        SegTree seg(s);
        int cnt=0;
        auto get=[&](int i){
            return seg.get(1,1,n,i,i)[0]?0:1;
        };
        std::function<bool(int)> fuk=[&](int i){
            if(!(i>=2&&i<=n-1)) return false;
            if(get(i-1)!=get(i+1)){
                seg.update(1,1,n,i,i);
                cnt++;
                return true;
            }
            int tar=get(i);
            if(get(i-1)==tar){
                tar^=1;
                int l=i,r=n+1;
                while(l+1<r){
                    int mid=(l+r)>>1;
                    if(seg.get(1,1,n,i+1,mid)[tar]) r=mid;
                    else l=mid;
                }
                if(r==n+1) return false;
                seg.update(1,1,n,i,r-1);
                cnt+=r-i;
            }else{
                int l=i,r=n+1;
                while(l+1<r){
                    int mid=(l+r)>>1;
                    if(seg.is_seq(1,1,n,i,mid)[0][tar]) l=mid;
                    else r=mid;
                }
                de(i,l);
                if(l==n||l==i) return false;
                seg.update(1,1,n,i,l);
                cnt+=l-i+1;
            }
            return true;
        };
        for(int i=1;i<=n;++i){
            if(get(i)+'0'!=t[i]){
                if(!fuk(i)){
                    fail=true;
                    break;
                }
            }
        }
        if(fail){
            std::cout<<"-1\n";
        }else{
            std::cout<<cnt<<'\n';
        }
    }
    return 0;
}