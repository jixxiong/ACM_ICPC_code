#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

const int ba=233;
const int m1=998244353;
const int m2=1000000007;
const int N=500000;
int pw1[500010],pw2[500010];

struct Hash{
    std::vector<int>a1,a2;
    Hash(std::string& s,int n):a1(n+1),a2(n+1){
        for(int i=1;i<=n;++i){
            a1[i]=((ll)a1[i-1]*ba%m1+s[i-1])%m1;
            a2[i]=((ll)a2[i-1]*ba%m2+s[i-1])%m2;
        }
    }
    int get(int l,int r,int t){
        if(t==0){
            return (m1+a1[r]-(ll)a1[l-1]*pw1[r-l+1]%m1)%m1;
        }else{
            return (m2+a2[r]-(ll)a2[l-1]*pw2[r-l+1]%m2)%m2;
        }
    }
    std::pair<int,int>get(int l,int r){
        return {get(l,r,0),get(l,r,1)};
    }
};

int main(){
    pw1[0]=pw2[0]=1;
    for(int i=1;i<=N;++i){
        pw1[i]=(ll)pw1[i-1]*ba%m1;
        pw2[i]=(ll)pw2[i-1]*ba%m2;
    }
    int T; std::cin>>T;
    while(T--){
        std::string s,t;
        std::cin>>s>>t;
        int l1,l2; std::cin>>l1>>l2;
        if(l1>l2) std::swap(l1,l2);
        int g=s.length()-std::abs(l1-l2);
        auto check=[&](std::string s1,std::string& s2){
            auto fuk=s1;
            for(int i=0;i<10;++i) s1+=fuk;
            Hash ha1(s1,s1.length());
            Hash ha2(s2,s2.length());
            auto tar=ha2.get(1,s2.length());
            for(int i=(int)s2.length();i<=(int)s1.length();++i){
                int l=i-s2.length()+1;
                
                if(ha1.get(l,i)==tar&&((l-1)%g==0)) return true;
            }
            return false;
        };
        bool ok=check(s,t);
        if(l1!=(int)s.length()){
            auto t_1=t.substr(l1)+t.substr(0,l1);
            std::reverse(all(t_1));
            // pr(t_1);
            ok|=check(s,t_1);
        }
        g=s.length()-g;
        ok|=check(s,t);
        if(l2!=(int)s.length()){
            auto t_2=t.substr(l2)+t.substr(0,l2);
            std::reverse(all(t_2));
            ok|=check(s,t_2);
        }
        std::cout<<(ok?"yes":"no")<<'\n';
    }
    return 0;
}