#include <bits/stdc++.h>
using namespace std;

void fo(){ cerr<<endl; } template<class fst,class...lst>
void fo(fst F, lst... L) { cerr<<F<<" "; fo(L...); }
#define all(x) x.begin(),x.end()
using ll=long long;

struct Manacher:vector<int>{
    int max_len;   // 最大回文子串的长度
    Manacher(const char* s,int len):vector<int>(2*len+2),max_len(0){
        vector<int>&p=*this; // p[i] => 以 i 为起点的最大回文半径
        int n=2*len+1;
        // 经过处理后字符串变成 "$#1#2#3#..."
        string t="$#";
        for(int i=1;i<=len;++i)
            t+=s[i]+string(1,'#');
        for(int k=1,r=0,mid=0;k<=n;++k){
            if(k<=r) p[k]=min(p[(mid<<1)-k],r-k+1);
            while(t[k-p[k]]==t[k+p[k]]) ++p[k];
            if(p[k]+k>r) r=p[k]+k-1,mid=k;
            if(p[k]-1>max_len) max_len=p[k]-1;
        }
    }
};


int main(){
    string str(11000010,0);
    scanf("%s",&str[1]);
    Manacher len(&str[0],strlen(&str[1]));
    printf("%d\n",len.max_len);
    return 0; 
}