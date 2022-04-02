#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

template<const int sigma=26>
struct ACAM{
    using Node=std::array<int,sigma>;
    std::vector<Node>nxt;
    std::vector<int>fail;                 // fail ָ指针
    std::vector<int>pos;                  // pos[i]=>第i-th串的结束位置是pos[i]
    std::vector<std::vector<int>>idx;     // idx[p]=>串p的编号为idx[i]
    std::vector<int>ht;
    int tot,cnt;
    int trans(char ch){
        return ch-'a'; 
    }
    int new_node(){
        ++tot;
        nxt.resize(tot+1);
        idx.resize(tot+1);
        ht.resize(tot+1);
        return tot;
    }
    ACAM():nxt(1),tot(0),cnt(0){}
    void insert(const char* s,int n){
        int p=0;
        for(int i=1;i<=n;++i){
            auto ch=trans(s[i]);
            if(!nxt[p][ch]) nxt[p][ch]=new_node();
            p=nxt[p][ch];
        }
        ht[p]=n;
        idx[p].pb(++cnt);
        pos.resize(cnt+1);
        pos.back()=p;
    }
    void build(){
        std::queue<int>q; fail.resize(tot+1);
        for(int i=0;i<sigma;++i)
            if(nxt[0][i])
                q.push(nxt[0][i]);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int i=0;i<sigma;++i)
                if(nxt[u][i])
                    fail[nxt[u][i]]=nxt[fail[u]][i], q.push(nxt[u][i]);
                else
                    nxt[u][i]=nxt[fail[u]][i];
        }
    }
};

struct SegTree{
    std::vector<int>arr;
    SegTree(int n):arr((n+1)<<2,0x3f3f3f3f){ }
    void update(int ni,int nl,int nr,int x,int v){
        if(nl==nr){ arr[ni]=v; return ;}
        int mid=(nl+nr)>>1;
        if(x<=mid) update(ni<<1,nl,mid,x,v);
        else update(ni<<1|1,mid+1,nr,x,v);
        arr[ni]=std::min(arr[ni<<1],arr[ni<<1|1]);
    }
    int query(int ni,int nl,int nr,int l,int r){
        if(l<=nl&&nr<=r){ return arr[ni]; }
        int mid=(nl+nr)>>1, res=0x3f3f3f3f;
        if(l<=mid) res=std::min(query(ni<<1,nl,mid,l,r),res);
        if(r> mid) res=std::min(query(ni<<1|1,mid+1,nr,l,r),res);
        return res;
    }
};

struct Solution:ACAM<26>{
    Solution():ACAM<26>(){
        int n; std::cin>>n;
        std::string s; std::cin>>s;
        for(int i=1;i<=n;++i){
            std::string t; std::cin>>t;
            insert(&t[0]-1,t.length());
        }
        build();
        std::vector<std::vector<int>>G(tot+1);
        for(int i=1;i<=tot;++i) G[fail[i]].pb(i);
        std::function<void(int)>dfs=[&](int u){
            for(auto v:G[u]){
                ht[v]=std::max(ht[u],ht[v]);
                dfs(v);
            }
        };
        dfs(0);
        int len=s.length();
        SegTree seg(len+2);
        seg.update(1,1,len+1,1,0);
        for(int i=0,p=0;i<len;++i){
            int j=i+2;
            p=nxt[p][trans(s[i])];
            int min=seg.query(1,1,len+1,j-ht[p],j-1);
            if(min<0x3f3f3f3f)
                seg.update(1,1,len+1,j,min+1);
        }
        int res=seg.query(1,1,len+1,len+1,len+1);
        std::cout<<(res>=0x3f3f3f3f?-1:res)<<std::endl;
    }
};

int main(){
    Solution();
    return 0;
}