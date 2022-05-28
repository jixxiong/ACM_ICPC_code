#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define er(args...) void()
#else
    #define vwn(x) #x"=",x,"\n"
    void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
    #define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

template<int int_len=20>
struct Trie{
    using Node=std::array<int,2>;
    std::vector<Node> nxt;
    int tot;
    Trie():nxt(1),tot(0){ nxt.reserve(2000000); }
    void insert(int x){
        int p=0;
        for(int i=int_len;i>=0;--i){
            auto ch=(x>>i)&1;
            if(!nxt[p][ch]){
                nxt.emplace_back(Node{});
                nxt[p][ch]=++tot;
            }
            p=nxt[p][ch];
        }
    }
    int query(int p,int x,int bit=int_len){
        if(bit<0) return 0;
        auto ch=(x>>bit)&1;
        if(ch==0){
            if(nxt[p][1]) return (1<<bit)|query(nxt[p][1],x,bit-1);
            else return query(nxt[p][1],x,bit-1);
        }else return std::max(nxt[p][1]?query(nxt[p][1],x,bit-1):0,nxt[p][0]?query(nxt[p][0],x,bit-1):0);
    }
};


int32_t main(){
    int q; std::cin>>q;
    Trie trie;
    int s=0;
    while(q--){
        int op; std::cin>>op;
        if(op==1){
            int x; std::cin>>x;
            s^=x;
            trie.insert(s);
        }else{
            std::cout<<trie.query(0,s)<<'\n';
        }
    }
    return 0;
}