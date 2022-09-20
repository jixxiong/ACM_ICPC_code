#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

template<int int_len=30>
struct Trie{
    using Node=array<int,2>;
    vector<char> end; // 代表该节点是否为一个串的结尾节点
    vector<Node> nxt;
    int tot;
    Trie():end(1),nxt(1),tot(0){ }
    void insert(int x){
        int p=0;
        for(int i=int_len;i>=0;--i){
            auto ch=(x>>i)&1;
            if(!nxt[p][ch]){
                end.emplace_back(0);
                nxt.emplace_back(Node{});
                nxt[p][ch]=++tot;
            }
            p=nxt[p][ch];
        }
        end[p]=true;
    }
    bool query(int x){
        int p=0;
        for(int i=int_len;i>=0;--i){
            auto ch=(x>>i)&1;
            if(!nxt[p][ch])
                return false;
            p=nxt[p][ch];
        }
        return end[p];
    }
};

int main(){
    Trie trie;
    trie.insert(123);
    trie.insert(234);
    puts(trie.query(124)?"Yes":"No");
    puts(trie.query(123)?"Yes":"No");
    puts(trie.query(234)?"Yes":"No");
    return 0; 
}