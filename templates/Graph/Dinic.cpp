#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; }
template<typename T,typename... Args>
void fo(T t,Args...args){ cerr<<t<<" "; fo(args...); }
using ll=long long;
#define all(x) (x).begin(),(x).end()
#define pb emplace_back

template<typename info=int>
struct Graph{
    int n,c; // n => number of nodes, c => number of edges
    std::vector<int>h; // h[i] => the index of the first edge starting from i
    std::vector<int>f; // f[i] => the index of the edge next to edge i
    std::vector<info>e; // e[i] => the information of the i-th edge
    Graph(int n):n(n),c(0),h(n+1,-1){}
    void add(int u,const info&i){ // adding a new edge, u => starting point, i => infomation of the edge
        f.pb(h[u]); h[u]=c++; e.pb(i);
    }
};

template<typename Fint>
struct flow_edge{
    int v; Fint w;
    flow_edge(int v,int w):v(v),w(w){ }
};

// dinic O(n^2m) => maxflow
template<typename Fint>
Fint dinic(Graph<flow_edge<Fint>>&G,int s,int t){
    const Fint INF=numeric_limits<Fint>::max();
    int n=G.n; Fint ret=0;
    vector<int>cur,ht(n+1);
    auto bfs=[&](){
        fill(all(ht),0); ht[s]=1;
        queue<int>q; q.push(s);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int idx=G.h[u];~idx;idx=G.f[idx]){
                auto e=G.e[idx];
                if(e.w&&!ht[e.v]){
                    ht[e.v]=ht[u]+1;
                    q.push(e.v);
                    if(e.v==t)
                        return 1;
                }
            }
        }
        return ht[t];
    };
    function<Fint(int,Fint)>dfs=[&](int u,Fint flow){
        if(u==t)
            return flow;
        Fint x=0;
        for(int& idx=cur[u];~idx;idx=G.f[idx]){
            auto e=G.e[idx];
            if(e.w&&ht[e.v]==ht[u]+1){
                Fint f=dfs(e.v,min(flow,e.w));
                G.to[idx].w-=f; flow-=f;
                G.to[idx^1].w+=f; x+=f; 
                if(flow<=0)
                    break;
            }
        }
        return x;
    };
    while(bfs()){
        cur=G.head;
        ret+=dfs(s,INF);
    }
    return ret;
}



int32_t main(){
    
    return 0;
}