#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct Heap{
    std::vector<int>arr;
    void up(int idx){
        while(idx>1&&arr[idx]<arr[idx>>1]){
            std::swap(arr[idx],arr[idx>>1]);
            idx>>=1;
        }
    }
    void down(int idx){
        while(idx<<1<=(int)arr.size()-1){
            int son=-1;
            if(arr[idx<<1]<arr[idx])son=idx<<1;
            if((idx<<1|1)<=(int)arr.size()-1&&
                ((son==-1&&arr[idx<<1|1]<arr[idx])||
                    arr[idx<<1|1]<arr[son])) son=idx<<1|1;
            if(son==-1) break;
            std::swap(arr[idx],arr[son]);
            idx=son;
        }
    }
    void push(int x){
        arr.pb(x);
        up((int)arr.size()-1);
    }
    int top(){
        return arr[1];
    }
    void pop(){
        int x=arr.back(); arr.pop_back();
        arr[1]=x;
        down(1);
    }
    friend std::ostream& operator<<(std::ostream& os,Heap const& heap){
        int m=(int)heap.arr.size()-1;
        int n=(1<<(std::__lg(m)+1))-1;
        int w=n/2*4+2;
        std::vector<std::vector<char>>mp(n,std::vector<char>(w,'*'));
        std::function<void(int,int,int,int)>dfs=[&](int x,int y,int i,int c){
            if(i>m){
                mp[x][y]=mp[x][y+1]='-';
            }else{
                mp[x][y]=heap.arr[i]/10+'0';
                mp[x][y+1]=heap.arr[i]%10+'0';
            }
            if(c==0){
                return ;
            }
            for(int i=1;i<=c;++i){
                mp[x+i][y-i]='/';
                mp[x+i][y+i+1]='\\';
            }
            dfs(x+c+1,y-c-1,i<<1,c>>1);
            dfs(x+c+1,y+c+1,i<<1|1,c>>1);
        };
        dfs(0,w/2-1,1,n/2);
        for(int i=0;i<n;++i){
            for(int j=0;j<w;++j){
                os<<mp[i][j];
            }
            os<<'\n';
        }
        return os;
    }
    Heap(std::vector<int>const &A):arr(A){
        for(int i=(int)(A.size()-1)/2;i>=1;--i){
            down(i);
        }
    }
};

int main(){
    int n,q; std::cin>>n>>q;
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i) std::cin>>A[i];
    Heap heap(A);
    bool first=true;
    auto fuk=[&](){
        if(first) first=false;
        else std::cout<<'\n';
    };
    while(q--){
        std::string s; std::cin>>s;
        if(s=="top"){
            fuk();
            std::cout<<heap.top()<<'\n';
        }
        if(s=="pop"){
            heap.pop();
        }
        if(s=="push"){
            int x; std::cin>>x;
            heap.push(x);
        }
        if(s=="draw"){
            fuk();
            std::cout<<heap;
        }
    }
    return 0;
}

/*



7 0
99 5 36 7 22 17 46

*/