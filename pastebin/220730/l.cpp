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

auto POSS()->void{
    std::cout<<"possible ";
}

auto IMPOSS()->void{
    std::cout<<"impossible\n";
}

ld const sqrt2=std::sqrt((ld)2);
ld const sqrt5=std::sqrt((ld)5);
ld const fuck=std::sqrt((1/(ld)2)+1/(2*sqrt5)) / (std::tan(PI/5));

auto change(int& n,ld& a)->void{
    if(n==4){
        a/=3;
    }else if(n==6){
        n=8;
        a/=sqrt2;
    }else if(n==8){
        n=6;
        a*=sqrt2/3;
    }else if(n==12){
        n=20;
        a*=fuck;
    }else if(n==20){
        n=12;
        a*=(sqrt5-1)/2;
    }
}

int32_t main(){
    std::cout<<std::fixed<<std::setprecision(10);
    int T; std::cin>>T;
    while(T--){
        int n,k; ld a; std::cin>>n>>a>>k;
        if(!(n==4||n==6||n==8||n==12||n==20)){
            IMPOSS();
        }else{
            while(k--) change(n,a);
            POSS();
            std::cout<<n<<' '<<a<<'\n';
        }
    }
    return 0;
}