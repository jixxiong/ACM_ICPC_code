#include<vector>
#include<array>
#include<iostream>
#include<cassert>

void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
const int preallsize=32*1024*1024;

struct Trie{
    int tot;
    std::vector<std::array<int,2>>nxt;
    std::vector<int>end;
    Trie():tot(0),nxt(1){ nxt.reserve(preallsize), end.reserve(preallsize); }
    void insert(int x,int idx){
        int p=0;
        for(int i=30;i>=0;--i){
            end.resize(tot+1); end[p]=idx;
            int ch=(x>>i)&1;
            if(!nxt[p][ch]){
                nxt.resize(++tot+1);
                nxt[p][ch]=tot;
            }
            p=nxt[p][ch];
        }
        end.resize(tot+1); end[p]=idx;
    }
    int query(int s_,int k_,int bt,int p){
        if(bt<0) return end[p];
        int s=(s_>>bt)&1,k=(k_>>bt)&1;
        if(!s&&k){
            if(!nxt[p][1]) return -1;
            return query(s_,k_,bt-1,nxt[p][1]);
        }
        else if(s&&k){
            if(!nxt[p][0]) return -1;
            return query(s_,k_,bt-1,nxt[p][0]);
        }
        else if(!s&&!k){
            int mx=-1;
            if(nxt[p][1]) mx=end[nxt[p][1]];
            if(nxt[p][0]) mx=std::max(mx,query(s_,k_,bt-1,nxt[p][0]));
            return mx;
        }
        else if(s&&!k){
            int mx=-1;
            if(nxt[p][0]) mx=end[nxt[p][0]];
            if(nxt[p][1]) mx=std::max(mx,query(s_,k_,bt-1,nxt[p][1]));
            return mx;
        }
        assert(false);
    }
};

int main(){
    int T; 
    scanf("%d",&T);
    while(T--){
        int n,k; 
        scanf("%d%d",&n,&k);
        Trie trie;
        trie.insert(0,0);
        int xorsum=0;
        int lm=-1,rm=-1;
        for(int i=1;i<=n;++i){
            int x; 
            scanf("%d",&x);
            xorsum^=x;
            int ls=trie.query(xorsum,k,30,0);
            if(~ls&&(lm==-1 || i-ls<rm-lm)) lm=ls,rm=i;
            trie.insert(xorsum,i);
        }
        if(~lm) printf("%d %d\n",lm+1,rm);
        else puts("-1");
    }
    return 0;
}