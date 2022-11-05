#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
#define ld long double
#define ll long long
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
template<class T>using vc    =std::vector<T>;
template<class T>using vvc   =vc<vc<T>>;
template<class T>using vvvc  =vc<vvc<T>>;
template<class T>using vvvvc =vc<vvvc<T>>;
template<class T>using vvvvvc=vc<vvvvc<T>>;
template<class T> auto vcc   (i32 _1=0,i32 _2=0,const T&init=T()){ return vvc<T>(_1,vc<T>(_2,init)); }
template<class T> auto vccc  (i32 _1=0,i32 _2=0,i32 _3=0,const T&init=T()){ return vvvc<T>(_1,vcc(_2,_3,init)); }
template<class T> auto vcccc (i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,const T&init=T()){ return vvvvc<T>(_1,vccc(_2,_3,_4,init)); }
template<class T> auto vccccc(i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,i32 _5=0,const T&init=T()){ return vvvvvc<T>(_1,vcccc(_2,_3,_4,_5,init)); }
template<class T> T INF() { return std::numeric_limits<T>::max(); }

ld const EPS = 1e-8;
ld const PI = std::acos((ld)-1.0);
i64 const mod = 998244353;

template<const int sigma=26>
struct ACAM{
    using Node=std::array<i32,sigma>;
    std::vector<Node>nxt;
    std::vector<i32>fail;                 // fail ָ指针
    std::vector<i32>pos;                  // pos[i]=>第i-th串的结束位置是pos[i]
    std::vector<char>end;                 // end[p]=>节点p是结尾
    std::vector<std::vector<i32>>idx;     // idx[p]=>串p的编号为idx[i]
    i32 tot,cnt;
    i32 trans(char ch){
        return ch-'A';
    }
    i32 new_node(){
        nxt.resize(++tot+1);
        return tot;
    }
    ACAM():nxt(1),tot(0),cnt(0){}
    void insert(const char* s,i32 n, i32 tp){
        i32 p=0;
        for(i32 i=1;i<=n;++i){
            auto ch=trans(s[i]);
            if(!nxt[p][ch]) nxt[p][ch]=new_node();
            p=nxt[p][ch];
        }
        end.resize(tot+1); end[p]=true;
        idx.resize(tot+1); idx[p].pb(++cnt);
        pos.resize(cnt+1); pos.back()=p;
    }
    void build(){
        std::queue<i32>q; fail.resize(tot+1);
        for(i32 i=0;i<sigma;++i)
            if(nxt[0][i])
                q.push(nxt[0][i]);
        while(!q.empty()){
            i32 u=q.front(); q.pop();
            for(i32 i=0;i<sigma;++i){
                if(nxt[u][i]){
                    fail[nxt[u][i]]=nxt[fail[u]][i];
                    end[nxt[u][i]]|=end[fail[nxt[u][i]]];
                    q.push(nxt[u][i]);
                }
                else{
                    nxt[u][i]=nxt[fail[u]][i];
                }
            }
        }
    }
};


int32_t main() {
    i32 n; std::cin >> n;
    ACAM<2> ac;
    for (i32 i = 1; i <= n; ++i) {
        std::string s;
        std::cin >> s;
        trie.insert(s.data() - 1, s.length(), 0);
        std::reverse(all(s));
        trie.insert(s.data() - 1, s.length(), 1);
    }
    ac.build();
    // std::cout << trie.dfs(0) << '\n';
    return 0;
}
