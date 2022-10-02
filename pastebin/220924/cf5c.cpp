#include <bits/stdc++.h>

#ifndef LOCAL_COMPILE
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) void()
#else
void _du(){std::cerr<<std::endl;}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
#define ld long double
#define ll long long
#define i32 int32_t
#define i64 int64_t
#define i128 __int128
template<class T>using vc    =std::vector<T>;
template<class T>using vvc   =vc<vc<T>>;
template<class T>using vvvc  =vc<vvc<T>>;
template<class T>using vvvvc =vc<vvvc<T>>;
template<class T>using vvvvvc=vc<vvvvc<T>>;
template<class T>auto  vcc   (i32 _1=0,i32 _2=0,const T&init=T()){ return vvc<T>(_1,vc<T>(_2,init)); }
template<class T>auto  vccc  (i32 _1=0,i32 _2=0,i32 _3=0,const T&init=T()){ return vvvc<T>(_1,vcc(_2,_3,init)); }
template<class T>auto  vcccc (i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,const T&init=T()){ return vvvvc<T>(_1,vccc(_2,_3,_4,init)); }
template<class T>auto  vccccc(i32 _1=0,i32 _2=0,i32 _3=0,i32 _4=0,i32 _5=0,const T&init=T()){ return vvvvvc<T>(_1,vcccc(_2,_3,_4,_5,init)); }

ld const EPS=1e-8;
ld const PI=std::acos((ld)-1.0);
i64 const mod=998244353;
i64 const inf=0x3f3f3f3f3f3f3f3f;

int32_t main(){
    std::string s; std::cin>>s;
    std::map<i32,i32,std::greater<i32>>mp;
    vc<i32>stk;
    vc<char>vis(s.length()+10);
    for(i32 i=0;i<(i32)s.length();++i){
        if(s[i]=='('){
            stk.push_back(i);
        }else{
            if(!stk.empty()){
                vis[i]=vis[stk.back()]=true;
                stk.pop_back();
            }
        }
    }
    for(i32 l=0,r;l<(i32)s.length();l=r){
        while(l<(i32)s.length()&&!vis[l]) l++;
        if(l>=(i32)s.length()) break;
        r=l+1;
        while(r<(i32)s.length()&&vis[r]) r++;
        mp[r-l]++;
    }
    if(mp.empty()) std::cout<<"0 1\n";
    else std::cout<<(mp.begin()->first)<<' '<<(mp.begin()->second)<<'\n';
    return 0;
}
