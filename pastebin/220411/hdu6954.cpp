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
    std::vector<char>isPrime;
    EulerSieve(int n):std::vector<int>(),isPrime(n+1){
        std::vector<char>vis(n+1);
        reserve(n/std::__lg(n));
        for(int i=2;i<=n;++i){
            if(!vis[i]) pb(i),vis[i]=true,isPrime[i]=true;
            for(auto p:*this){
                if(i*p>n) break;
                vis[i*p]=true;
                if(i%p==0) break;
            }
        }
    }
};

int main(){
    const int size=10000000;
    EulerSieve prime(size);
    std::vector<ll>res(size+1);
    for(int i=3;i<=size;++i){
        res[i]+=res[i-1];
        if(prime.isPrime[i]) res[i]+=2*i;
        else res[i]+=i;
    }
    int T; std::cin>>T;
    while(T--){
        int x; std::cin>>x;
        std::cout<<res[x]<<'\n';
    }
    return 0;
}