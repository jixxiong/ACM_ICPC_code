#include <bits/stdc++.h>

int32_t main(){
    int T; std::cin>>T;
    while(T--){
        int n,m; std::cin>>n>>m;
        std::string s,t; std::cin>>s>>t;
        s=' '+s; t=' '+t;
        std::vector<int>st(m+1,n+1),ed(m+1,0);
        std::vector<std::vector<int>>lcp(n+2,std::vector<int>(m+2));
        for(int p=1,i=1;i<=n&&p<=m;++i)
            if(s[i]==t[p])
                st[p++]=i;
        for(int p=m,i=n;i>=1&&p>=1;--i)
            if(s[i]==t[p])
                ed[p--]=i;
        for(int i=n;i>=1;--i)
            for(int j=m;j>=1;--j)
                lcp[i][j]=s[i]==t[j]?lcp[i+1][j+1]+1:0;
        int ans=2*n+10;
        for(int j=1;j<=m;++j){
            for(int i=st[j];i<=ed[j];++i){
                int mr=lcp[i][j];
                if(j+mr<=m&&ed[j+mr]<=i+mr-1) continue;
                int c=i+i-j;
                if(i+mr<=n) c+=n-(i+mr)+1;
                ans=std::min(ans,c);
            }
        }
        if(ans<2*n+5) ans=std::min(ans,n-lcp[1][1]);
        std::cout<<(ans>2*n+5?-1:ans)<<'\n';
    }
    return 0;
}