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
    std::vector<char>isPrime; // isPrime[i] => whether i is a prime number; isPrime[1] not defined 
    std::vector<int>phi; // phi[i] => euler function of i; phi[1] not defined
    std::vector<int>mu; // mu[i] => mobius function of i
    EulerSieve(int n):std::vector<int>(),isPrime(n+1),phi(n+1),mu(n+1){
        std::vector<char>vis(n+1);
        reserve(n/std::__lg(n));
        mu[1]=1;
        for(int i=2;i<=n;++i){
            if(!vis[i]) {
                push_back(i);
                vis[i]=true;
                isPrime[i]=true;
                phi[i]=i-1;
                mu[i]=-1;
            }
            for(auto p:*this){
                if(i*p>n) break;
                vis[i*p]=true;
                if(i%p==0) {
                    phi[i*p]=phi[i]*p;
                    break;
                }
                phi[i*p]=phi[i]*(p-1);
                mu[i*p]=-mu[i];
            }
        }
    }
};

int main(){
    EulerSieve A(100);
    for(auto x:A){
        std::cout<<x<<"\n";
    }
    std::cout<<(int)A.isPrime[13]<<'\n';
    return 0;
}