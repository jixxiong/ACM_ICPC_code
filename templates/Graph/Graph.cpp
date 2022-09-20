#include<bits/stdc++.h>
using namespace std;

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

int main(){
    
    return 0;
}