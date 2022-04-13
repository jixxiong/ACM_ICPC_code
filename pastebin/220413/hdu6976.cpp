#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct line{
    int x,y;
    line(int x1,int y1,int x2,int y2):x(x2-x1),y(y2-y1){
        if(y<0) x=-x,y=-y;
        if(y==0&&x<0) x=-x;
    }
    bool operator<(const line&o)const{
        return (ll)x*o.y-(ll)y*o.x>0;
    }
};

int main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::map<line,int>mp;
        for(int i=1;i<=n;++i){
            int x1,y1,x2,y2; std::cin>>x1>>y1>>x2>>y2;
            mp[line(x1,y1,x2,y2)]++;
        }
        std::vector<int>cnt;
        for(auto it:mp) cnt.pb(it.second);
        sort(all(cnt));
        for(int i=0,j=1,rd=1,bg=0;j<=n;++j){
            if(--cnt[i]==0) bg=i+1;
            std::cout<<(j-rd)<<'\n';
            if(i==(int)cnt.size()-1) i=bg,rd++;
            else i++;
        }
    }
    return 0;
}