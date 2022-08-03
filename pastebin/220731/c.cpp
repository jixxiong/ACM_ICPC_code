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
        vc<int>A(m);
        for(int i=0;i<m;++i){
            std::cin>>A[i];
        }
        std::sort(all(A));
        vc<int>B;
        int s=0;
        for(int i=1;i<m;++i){
            if(A[i]-A[i-1]-1) B.pb(A[i]-A[i-1]-1);
            s+=A[i]-A[i-1]-1;
        }
        if((n-A.back())+(A[0]-1)) s+=(n-A.back())+(A[0]-1),B.pb((n-A.back())+(A[0]-1));
        std::sort(all(B),std::greater<int>());
        int day=0;
        int loss=0;
        vc<std::pair<int,int>>C;
        for(int l:B){
            if(2*day>=l){
                loss+=l;
                continue;
            }
            l-=2*day;
            loss+=2*day;
            if(l==1){
                day+=1;
            }else if(l==2){
                day+=1;
                loss+=1;
            }else{
                loss+=1;
                day+=2;
            }
        }
        std::cout<<loss+m<<'\n';
    }
    return 0;
}