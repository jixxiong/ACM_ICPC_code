#include <bits/stdc++.h>

using namespace std::string_literals;
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T,T init=T{}> auto Vec(int s){ return std::vector(s,init); }
template<typename T,T init=T{},typename...L> auto Vec(int s,L...l){ return std::vector(s,Vec<T,init>(l...)); }

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

std::string S,T; 

struct Node{
    std::string s;
    int dis,stp,lst;
    int cal_dis(std::string const& s,std::string const& t){
        int cnt=std::max(s.length(),t.length())-std::min(s.length(),t.length());
        for(int i=0;i<(int)std::min(s.length(),t.length());++i){
            cnt+=s[i]==t[i];
        }
        return -cnt;
    }
    Node(std::string const& s,int stp,int lst):s(s),dis(cal_dis(s,T)),stp(stp),lst(lst){ }
    bool operator<(Node const& o)const{
        return dis>o.dis;
    }
};

int32_t main(){
    std::cin>>S>>T;
    int k; std::cin>>k;
    std::map<char,std::vector<std::string>>mp;
    for(int i=1;i<=k;++i){
        char ch; std::string p; std::cin>>ch>>p;
        mp[ch].emplace_back(p);
    }
    std::priority_queue<Node>q;
    q.push(Node(S,0,0));
    std::map<std::string,int>st;
    while(!q.empty()){
        auto cur=q.top(); q.pop();
        auto cs=cur.s;
        if(st[cs]>cur.lst) continue;
        st[cs]=cur.lst;
        du(cs,cur.lst);
        if(cs==T){
            std::cout<<cur.stp<<'\n';
            return 0;
        }
        std::string front=cur.lst?cs.substr(0,cur.lst):"";
        for(int i=cur.lst;i<(int)cs.length();++i){
            if(mp.count(cs[i])){
                for(auto rep:mp[cs[i]]){
                    auto nxt=front+rep+(i==(int)cs.length()-1?"":cs.substr(i+1));
                    if(nxt.length()>T.length()) continue;
                    q.push(Node(nxt,cur.stp+1,i));
                }
            }
            if(cs[i]!=T[i]) break;
            front+=cs[i];
        }
        if(cur.lst<(int)cs.length()-1&&cs[cur.lst]==T[cur.lst]) q.push(Node(cs,cur.stp,cur.lst+1));   
    }
    std::cout<<"-1\n";
    return 0;
}