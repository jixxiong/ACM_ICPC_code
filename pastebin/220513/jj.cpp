#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;
ld const PI=std::acos(-1.0);

struct node{
    ld x,y;
    node():x(0),y(0){}
    node(ld ang):x(std::cos(PI*ang/180)),y(std::sin(PI*ang/180)){}
    node(int ang):x(std::cos(PI*ang/180)),y(std::sin(PI*ang/180)){}
    node(ld x,ld y):x(x),y(y){}
    friend node operator+(node const&o1,node const&o2){
        return node(o1.x+o2.x,o1.y+o2.y);
    }
    friend node operator-(node const&o1,node const&o2){
        return node(o1.x-o2.x,o1.y-o2.y);
    }
    friend ld operator*(node const&o1,node const&o2){
        return o1.x*o2.x+o1.y*o2.y;
    }
    friend node operator*(node const&o1,ld x){
        return node(o1.x*x,o1.y*x);
    }
    friend node operator*(ld x,node const&o1){
        return node(o1.x*x,o1.y*x);
    }
    friend node operator/(node const&o1,ld x){
        return node(o1.x/x,o1.y/x);
    }
    friend ld crs(node const&o1,node const&o2){
        return o1.x*o2.y-o2.x*o1.y;
    }
    friend ld dis2(node const&o1,node const&o2){
        return (o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y);
    }
    friend ld dis(node const&o1,node const&o2){
        return std::sqrt((o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y));
    }
    friend std::ostream& operator<<(std::ostream& os,node const& o){
        return os<<o.x<<' '<<o.y;
    }
    friend std::istream& operator>>(std::istream& is,node& o){
        return is>>o.x>>o.y;
    }
};

int main(){
    int n,s_ang,t_ang;
    while(std::cin>>s_ang>>t_ang){
        std::cin>>n;
        std::vector<node>A(n+1);
        for(int i=0;i<=n;++i) std::cin>>A[i];
        if(n<=2) continue;
        if((node(0,0)-A[n])*(A[n-1]-A[n])>1e-4){
            // pr((node(0,0)-A[n])*(A[n-1]-A[n]));
            std::cout<<s_ang<<' '<<t_ang<<'\n';
            for(auto x:A) std::cout<<x<<'\n';
            exit(0);
        }
    }
    return 0;
}