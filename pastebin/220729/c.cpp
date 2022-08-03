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

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int32_t main(){
    int n; std::cin>>n;
    vc<int>A(n);
    int mx=0;
    for(int i=0;i<n;++i){
        std::cin>>A[i];
        mx=std::max(mx,A[i]);
    }
    int st=-1;
    bool fail=false;
    for(int i=1;i<n;++i){
        int dif=std::abs(A[i]-A[i-1]);
        if(A[i]==A[i-1]||(st!=-1&&dif!=1&&dif!=st)){
            fail=true;
            break;
        }
        if(dif!=1) st=dif;
    }
    if(fail){
        std::cout<<"NO"<<'\n';
    }else{
        if(st==-1){
            std::cout<<"YES"<<'\n';
            std::cout<<1000000000<<' '<<1<<'\n';
            return 0;
        }
        for(int i=1;i<n;++i){
            if(std::abs(A[i]-A[i-1])==1&&std::min(A[i],A[i-1])%st==0){
                fail=true;
            }
        }
        if(fail){
            std::cout<<"NO"<<'\n';
        }else{
            std::cout<<"YES"<<'\n';
            std::cout<<(mx+st-1)/st<<' '<<st<<'\n';
        }
    }
    return 0;
}