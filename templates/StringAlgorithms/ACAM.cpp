#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fo(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fo(fst F, lst... L) { std::cerr<<F<<' '; fo(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

template<const int sigma=26>
struct ACAM{
    using Node=std::array<int,sigma>;
    std::vector<Node>nxt;
    std::vector<int>fail;                 // fail ָ指针
    std::vector<int>pos;                  // pos[i]=>第i-th串的结束位置是pos[i]
    std::vector<char>end;                 // end[p]=>节点p是结尾
    std::vector<std::vector<int>>idx;     // idx[p]=>串p的编号为idx[i]
    int tot,cnt;
    int trans(char ch){
        return ch-'A'; 
    }
    int new_node(){
        nxt.resize(++tot+1);
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
        end.resize(tot+1); end[p]=true;
        idx.resize(tot+1); idx[p].pb(++cnt);
        pos.resize(cnt+1); pos.back()=p;
    }
    void build(){
        std::queue<int>q; fail.resize(tot+1);
        for(int i=0;i<sigma;++i)
            if(nxt[0][i])
                q.push(nxt[0][i]);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int i=0;i<sigma;++i){
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

int main(){

	return 0;
}