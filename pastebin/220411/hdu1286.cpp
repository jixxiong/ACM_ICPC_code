#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

// find all the prime numbers no greater than n with time complexity O(n)
struct EulerSieve:std::vector<int>{
    std::vector<char>isPrime; // isPrime[1] not defined 
    std::vector<int>phi; // phi[1] not defined
    EulerSieve(int n):std::vector<int>(),isPrime(n+1),phi(n+1){
        std::vector<char>vis(n+1);
        reserve(n/std::__lg(n));
        for(int i=2;i<=n;++i){
            if(!vis[i]) {
                push_back(i);
                vis[i]=true;
                isPrime[i]=true;
                phi[i]=i-1;
            }
            for(auto p:*this){
                if(i*p>n) break;
                vis[i*p]=true;
                if(i%p==0) {
                    phi[i*p]=phi[i]*p;
                    break;
                }
                phi[i*p]=phi[i]*(p-1);
            }
        }
    }
};

int main(){
    EulerSieve A(100000);
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::cout<<A.phi[n]<<'\n';
    }
    return 0;
}