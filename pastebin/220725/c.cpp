#include <bits/stdc++.h>

using namespace std::string_literals;
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T> auto Vec(T init,int s){ return std::vector(s,init); }
template<typename T,typename...L> auto Vec(T init,int s,L...l){ return std::vector(s,Vec<T>(init,l...)); }

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);
const int base=233,mod=1000000007;

int32_t main(){
    int n; std::cin>>n;
    auto pos=Vec<int>(0,n+1);
    auto len=Vec<int>(0,n+1);
    auto ori=Vec<std::string>("",n+1);
    std::string s=" ";
    int tn=0;
    for(int i=1;i<=n;++i){
        pos[i]=(int)s.length();
        std::string t; std::cin>>t;
        s+=t;
        ori[i]=t;
        len[i]=t.length();
        tn+=len[i];
    }
    auto hs=Vec<int>(0,n+1);
    auto pw=Vec<int>(0,n+1); pw[0]=1;
    for(int i=1;i<=tn;++i){
        
    }
    auto B=Vec<int>(0,n+1);
    std::iota(1+all(B),1);
    std::sort(1+all(B),
        [&](int i,int j){
            bool rev=false;
            if(len[i]>len[j]) std::swap(i,j),rev=true;
            int pi=pos[i],pj=pos[j];
            int k=st.qry(rk[pi],rk[pj]);
            if(k<len[i]) return rev?(s[k+pos[i]]>s[k+pos[j]]):(s[k+pos[i]]<s[k+pos[j]]);
            int lcp2=st.qry(rk[pj],rk[pj+len[i]]);
            if(len[i]+lcp2<len[j]) return rev?(s[pj+lcp2]>s[pj+len[i]+lcp2]):(s[pj+lcp2]<s[pj+len[i]+lcp2]);
            int lcp3=st.qry(rk[pj+len[j]-len[i]],rk[pi]);
            if(len[i]<=lcp3) return false;
            return rev?(s[pj+len[j]-len[i]+lcp3]>s[pi+lcp3]):(s[pj+len[j]-len[i]+lcp3]<s[pi+lcp3]);
        });
    for(int i=1;i<=n;++i){
        std::cout<<ori[B[i]];
    }
    std::cout<<"\n";
    return 0;
}