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

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,m; std::cin>>n>>m;
        vvc<int>A(n+1,vc<int>(m+1));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                std::cin>>A[i][j];
            }
        }
        auto check=[&](int id)->std::pair<bool,int>{
            int cnt=0,pos=0;
            for(int i=1;i<=n;++i){
                if(i==id) continue;
                vc<int>dif(m+2);
                for(int j=1;j<=m;++j){
                    dif[j]=A[i][j]-A[id][j];
                }
                int a=0,b=0;
                for(int j=1;j<=m;++j){
                    if(dif[j]<0) a-=dif[j];
                    if(dif[j]>0) b+=dif[j];
                    dif[j+1]+=dif[j];
                }
                if(a!=b){
                    cnt++;
                    pos=i;
                }
            }
            return {cnt==1,pos};
        };
        auto get_ans=[&](int pi,int pj){
            vc<int>dif(m+2);
            for(int j=1;j<=m;++j){
                dif[j]=A[pi][j]-A[pj][j];
            }
            int a=0,b=0;
            for(int j=1;j<=m;++j){
                if(dif[j]<0) a-=dif[j];
                if(dif[j]>0) b+=dif[j];
                dif[j+1]+=dif[j];
            }
            return std::abs(a-b);
        };
        int ordinary=-1;
        for(int i=1;i<=2;++i){
            if(check(i).first) ordinary=i;
        }
        int pos=check(ordinary).second;
        std::cout<<pos<<' '<<get_ans(pos,ordinary)<<'\n';
    }
    return 0;
}