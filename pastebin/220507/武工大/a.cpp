#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

int main(){
    std::string s; 
    while(std::cin>>s){
        std::string t; std::cin>>t;
        int tic;
        bool type;
        if(s.length()<=5){
            if(s.length()!=5)s='0'+s;
            tic=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
            type=0;
        }else{
            if(s.length()!=8)s='0'+s;
            tic=((s[0]-'0')*10+s[1]-'0')*3600+((s[3]-'0')*10+s[4]-'0')*60+(s[6]-'0')*10+s[7]-'0';
            type=1;
        }
        if(t=="0.25x"){
            tic=tic*4;
        }
        if(t=="0.5x"){
            tic=tic*2;
        }
        if(t=="0.75x"){
            tic=tic*4;
            if(tic%3>=2)tic=tic/3+1;
            else tic=tic/3;
        }
        if(t=="1.25x"){
            tic=tic*4;
            if(tic%5>=3)tic=tic/5+1;
            else tic=tic/5;
        }
        if(t=="1.5x"){
            tic=tic*2;
            if(tic%3>=2)tic=tic/3+1;
            else tic=tic/3;
        }  
        if(t=="1.75x"){
            tic=tic*4;
            if(tic%7>=4)tic=tic/7+1;
            else tic=tic/7;
        }
        if(t=="2.0x"){
            if(tic%2>=1)tic=tic/2+1;
            else tic=tic/2;
        }
        if(tic>=3600){
            std::cout<<tic/3600<<":";
            tic%=3600;
            std::cout<<std::setw(2)<<std::setfill('0');
        }
        std::cout<<tic/60<<":"<<std::setw(2)<<std::setfill('0')<<tic%60<<'\n';
    }
    return 0;
}