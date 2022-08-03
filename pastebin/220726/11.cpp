#include <bits/stdc++.h>

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

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

struct node{
    int t,x,w;
    bool operator<(node o)const{
        return t<o.t;
    }
};

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,q; std::cin>>n>>q;
        auto X=std::vector<int>(n,0);
        auto Y=std::vector<int>(n,0);
        auto W=std::vector<int>(n,0);
        auto A=std::vector<std::vector<node>>(4,std::vector<node>(n,node{0,0,0}));
        for(int i=0;i<n;++i){
            std::cin>>X[i]>>Y[i]>>W[i];
            int x=X[i],y=Y[i];
            X[i]=x+y; Y[i]=x-y;
            A[0][i]=node{X[i]+W[i],X[i],W[i]};
            A[1][i]=node{X[i]-W[i],X[i],W[i]};
            A[2][i]=node{Y[i]+W[i],Y[i],W[i]};
            A[3][i]=node{Y[i]-W[i],Y[i],W[i]};
        }
        std::sort(all(A[0]));
        std::sort(all(A[1]));
        std::sort(all(A[2]));
        std::sort(all(A[3]));
        auto B=std::vector<std::vector<std::vector<int>>>(4,std::vector<std::vector<int>>(3,std::vector<int>(n,0)));
        for(int i=0;i<4;++i){
            for(int j=0;j<n;++j){
                B[i][0][j]=A[i][j].w;
                B[i][1][j]=A[i][j].x;
                B[i][2][j]=A[i][j].x;
            }
            if(i&1){
                for(int j=1;j<n;++j){
                    B[i][2][j]=std::max(B[i][2][j],B[i][2][j-1]);
                }
                for(int j=n-2;j>=0;--j){
                    B[i][0][j]=std::max(B[i][0][j],B[i][0][j+1]);
                    B[i][1][j]=std::min(B[i][1][j],B[i][1][j+1]);
                }
            }else{
                for(int j=1;j<n;++j){
                    B[i][0][j]=std::max(B[i][0][j],B[i][0][j-1]);
                    B[i][1][j]=std::max(B[i][1][j],B[i][1][j-1]);
                }
                for(int j=n-2;j>=0;--j){
                    B[i][2][j]=std::min(B[i][2][j],B[i][2][j+1]);
                }
            }
        }
        auto fuck=[&](int x,std::vector<node>&C,std::vector<node>&D,std::vector<std::vector<int>>&E,std::vector<std::vector<int>>&F)->int{
            auto p=std::upper_bound(all(C),node{x,0,0})-C.begin()-1;
            int ans=0;
            if(p!=-1){
                ans=std::max(ans,E[0][p]);
                ans=std::max(ans,E[1][p]-x);
            }
            p=std::lower_bound(all(C),node{x,0,0})-C.begin();
            if(p!=n){
                ans=std::max(ans,x-E[2][p]);
            }
            p=std::lower_bound(all(D),node{x,0,0})-D.begin();
            if(p!=n){
                ans=std::max(ans,F[0][p]);
                ans=std::max(ans,x-F[1][p]);
            }
            p=std::upper_bound(all(D),node{x,0,0})-D.begin()-1;
            if(p!=-1){
                ans=std::max(ans,F[2][p]-x);
            }
            return ans;
        };
        while(q--){
            int tx,ty; std::cin>>tx>>ty;
            int x=tx+ty,y=tx-ty;
            std::cout<<std::max(fuck(x,A[0],A[1],B[0],B[1]),fuck(y,A[2],A[3],B[2],B[3]))<<'\n';
        }
    }
    return 0;
}