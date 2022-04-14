#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

// 可持久化 Trie 树
// luogu P4735
template<int int_len=30>
struct Trie{
    using Node=array<int,2>;
    vector<Node> nxt; // 儿子指针
    vector<int> val;  // 节点出现次数
    vector<int> root; // 各个版本的根节点编号
    int tot;
    Trie():nxt(1),val(1),root(1),tot(0){ }
    inline int new_node(){
        val.emplace_back(0);
        nxt.emplace_back(Node{});
        return ++tot;
    }
    void insert(int x){
        int lst=root.back();
        int cur=new_node();
        root.emplace_back(cur);
        for(int i=int_len;i>=0;--i){
            auto ch=(x>>i)&1;
            if(!nxt[cur][ch])
                nxt[cur][ch]=new_node();
            nxt[cur][!ch]=nxt[lst][!ch];
            cur=nxt[cur][ch];
            lst=nxt[lst][ch];
            val[cur]=val[lst]+1;
        }
    }
    int query(int l,int r,int x){
        int ret=0;
         l=root[l],r=root[r];
        for(int i=int_len;i>=0;--i){
            auto ch=(x>>i)&1;
            if(val[nxt[r][!ch]]>val[nxt[l][!ch]]){
                ret|=1<<i;
                l=nxt[l][!ch];
                r=nxt[r][!ch];
            }else{
                l=nxt[l][ch];
                r=nxt[r][ch];
            }
        }
        return ret;
    }
};

int main(){
    Trie trie;
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int>s(n+1);
    trie.insert(0); // 先插入一个 0 方便操作
    for(int i=1;i<=n;++i){
        scanf("%d",&s[i]);
        s[i]^=s[i-1];
        trie.insert(s[i]);
    }
    while(q--){
        char op[5];
        scanf("%s",op);
        if(*op=='A'){
            int x;
            scanf("%d",&x);
            x^=s.back();
            s.emplace_back(x);
            trie.insert(x);
        }else{
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",trie.query(l-1,r,x^s.back()));
        }
    }
    return 0; 
}