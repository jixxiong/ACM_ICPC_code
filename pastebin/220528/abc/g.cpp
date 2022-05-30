#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
    __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
    #define er(args...) void()
#else
    #define vwn(x) #x"=",x,"\n"
    void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
    #define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;
#define int long long

int32_t main(){
    int n; ll L,R; std::cin>>n>>L>>R;
    std::vector<int>A(n+1);
    std::iota(all(A),0);
    auto fun=[&](int x){
        return ((ll)((n-1)+(n-x))*x)/2;
    };
    auto fa=[&](ll x)->int{
        int l=0,r=n+1;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(fun(mid)<x)l=mid;
            else r=mid;
        }
        return l;
    };
    if(fa(L)==fa(R)){
        int s=fa(L);
        int a=s+1+L-fun(s);
        int b=s+1+R-fun(s);
        for(int i=a;i<=b;++i) std::swap(A[s+1],A[i]);
        for(int i=1;i<=n;++i) std::cout<<A[i]<<" \n"[i==n];
        return 0;
    }
    int s=fa(L)+1;
    int t=fun(s)-L+1;
    for(int i=n-t+1;i<=n;++i) std::swap(A[s],A[i]);
    int ls=s+1;
    s=fa(R);
    if(s>=ls){
        int l=s-ls+1;
        std::reverse(A.begin()+ls,A.begin()+n-l+1);
        std::reverse(A.begin()+ls,A.end());
    }
    t=R-fun(s);
    for(int i=++s+1;i<=s+t;++i) std::swap(A[i],A[s]);
    for(int i=1;i<=n;++i) std::cout<<A[i]<<" \n"[i==n];
    return 0;
}