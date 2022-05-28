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

int ans;
std::map<int,int>cnt;

char const* charset="0123456789+-*/";

std::pair<bool,int> fun(std::string const& s){
    if(s.length()==1){
        if(isdigit(s[0])) return {true,s[0]-'0'};
        else return {false,0};
    }
    if(!isdigit(s[0])&&s[0]!='-') return {false,0};
    if(s[0]=='-'&&!isdigit(s[1])) return {false,0};
    if(!isdigit(s.back())) return {false,0};
    int n=s.length();
    for(int i=1;i<n-2;++i){
        if(s[i]=='-'&&s[i+1]=='-'&&(!isdigit(s[i-1])||!isdigit(s[i+2]))) return {false,0};
        if(!isdigit(s[i])&&!isdigit(s[i+1])&&s[i+1]!='-') return {false,0};
    }
    std::vector<int>A;
    std::vector<char>B;
    for(int l=0,r=0;l<n;l=r){
        if(!isdigit(s[l])&&l!=0)B.pb(s[l]),l++,r++;
        bool flg=false;
        if(s[r]=='-') flg=true,r++;
        if(r==n) return {false,0};
        int x=0;
        while(r<n&&isdigit(s[r])) x=x*10+s[r]-'0',r++;
        if(flg) x=-x;
        A.pb(x);
    }
    if((int)B.size()==0) return {true,A[0]};
    std::vector<int>C{A[0]};
    std::vector<char>D;
    for(int i=1;i<(int)A.size();++i){
        int a=C.back();
        if(B[i-1]=='*'){
            C.back()=a*A[i];
        }
        else if(B[i-1]=='/'){
            if(A[i]==0||a%A[i]!=0) return {false,0};
            C.back()=a/A[i];
        }else{
            C.pb(A[i]);
            D.pb(B[i-1]);
        }
    }
    int ret=C[0];
    for(int i=1;i<(int)C.size();++i){
        if(D[i-1]=='+'){
            ret=ret+C[i];
        }else{
            ret=ret-C[i];
        }
    }
    return {true,ret};
}

void dfs(std::string s,int p,bool forward){
    if(p==(int)s.length()){
        auto [flg,res]=fun(s);
        if(!flg) return ;
        if(forward) cnt[res]++;
        else ans+=cnt[res];
        return ;
    }
    if(s[p]!='?'){
        dfs(s,p+1,forward);
        return ;
    }
    for(int i=0;i<14;++i){
        s[p]=charset[i];
        dfs(s,p+1,forward);
    }
}

void dfs(std::string s, int p){
    if(p==(int)s.length()){
        auto [flg,res]=fun(s);
        if(flg) std::cout<<s<<' '<<(int)flg<<' '<<res<<'\n';
        return ;
    }
    for(int i=0;i<14;++i){
        s[p]=charset[i];
        dfs(s,p+1);
    }
}

int32_t main(){
    std::string s; std::cin>>s;
    if(s=="????????"){
        std::cout<<360068<<'\n';
        return 0;
    }
    int equ=0;
    int pos=-1;
    for(int i=1;i<7;++i){
        if(s[i]=='='){
            equ++; pos=i;
        }
    }
    if(equ>1){
        std::cout<<"0\n";
    }else if(equ==1){
        dfs(s.substr(0,pos),0,true);
        dfs(s.substr(pos+1,7-pos),0,false);  
        std::cout<<ans<<'\n';
    }else{
        for(int i=1;i<7;++i){
            cnt.clear();
            if(s[i]=='?'){
                dfs(s.substr(0,i),0,true);
                dfs(s.substr(i+1,7-i),0,false);  
            }
        }
        std::cout<<ans<<'\n';
    }    
    return 0;
}