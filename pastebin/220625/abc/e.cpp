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

int32_t main(){
    int n; std::cin>>n;
    std::vector<int>A(10);
    std::vector<int>B(10);
    std::iota(all(B),0);
    for(int i=1;i<=9;++i) std::cin>>A[i];
    std::sort(1+all(B),[&](int i,int j){
        if(A[i]==A[j])return i>j;
        return A[i]<A[j];
    });
    int r=n%A[B[1]];
    int c=n/A[B[1]];
    std::vector<char>ret;
    while(c){
        int j=B[1];
        for(int i=1;i<=9;++i){
            if(A[B[i]]<=r+A[B[1]]&&B[i]>j) j=B[i];
        }
        if(j!=B[1]){
            c--;
            ret.pb(j+'0');
            r-=A[j]-A[B[1]];
        }else{
            break;
        }
    }
    for(int i=1;i<=c;++i) ret.pb((B[1]+'0'));
    std::sort(all(ret),std::greater<char>());
    for(auto x:ret)std::cout<<x;
    return 0;
}

// #include <bits/stdc++.h>

// #ifndef LOCAL_DEBUG
//     __attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
//     #define er(args...) void()
// #else
//     #define vwn(x) #x"=",x,"\n"
//     void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
//     #define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
// #endif

// #define all(x) x.begin(),x.end()
// #define pb emplace_back
// using ll=long long;
// using ld=long double;



// int32_t main(){
//     int n; std::cin>>n;
//     std::vector<int>A(10);
//     std::vector<int>B(10);
//     std::iota(all(B),0);
//     for(int i=1;i<=9;++i) std::cin>>A[i];
//     std::sort(1+all(B),[&](int i,int j){
//         if(A[i]==A[j])return i>j;
//         return A[i]<A[j];
//     });
//     int r=n%A[B[1]];
//     int j=B[1];
//     for(int i=1;i<=9;++i){
//         if(A[B[i]]<=r+A[B[1]]&&B[i]>j) j=B[i];
//     }
//     std::vector<char>ret;
//     for(int i=1;i<=n/A[B[1]];++i) ret.pb((B[1]+'0'));
//     if(j>B[1]) ret.pop_back(),ret.pb(j+'0');
//     std::sort(all(ret),std::greater<char>());
//     for(auto x:ret)std::cout<<x;
//     return 0;
// }