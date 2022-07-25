#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor))void before_main(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
    #define de(...) 4933
#else
    void _de(){std::cerr<<'\n';}template<class F,class...L>void _de(F f,L...l){std::cerr<<f<<' ';_de(l...);}
    #define de(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_de(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ll=long long;
using ld=long double;
const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<int>A(n);
        for(int i=0;i<n;++i){
            std::cin>>A[i];
        }
        auto fuk=[&](std::vector<int>&vec)->std::vector<int>{
            int cnt=0;
            int len=(int)vec.size();
            for(int x:vec){
                if(x==0) cnt++;
            }
            if(cnt&&len-cnt==1){
                return std::vector<int>{vec.back()};
            }
            if(cnt&&len-cnt==2){
                int x=*next(vec.rbegin());
                int y=vec.back();
                int k=y/x;
                if(cnt>k){
                    y=y-k*x;
                    std::vector<int>ret;
                    for(int i=1;i<=(cnt-k);++i) ret.pb(0);
                    ret.pb(y); ret.pb(x);
                    return ret;
                }else{
                    y=y-cnt*x;
                    if(x>y) std::swap(x,y);
                    return std::vector<int>{x,y};
                }
            }
            std::vector<int>B;
            for(int i=1;i<(int)vec.size();++i){
                B.pb(vec[i]-vec[i-1]);
            }
            std::sort(all(B));
            return B;
        };
        while(A.size()>1){
            A=fuk(A);
        }
        std::cout<<A.back()<<'\n';
    }
    return 0;
}