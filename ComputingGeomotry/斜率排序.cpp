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
        if(y<0) x=-x,y=-y;  // 规范化方向向量 => dy>0
        if(y==0&&x<0) x=-x; // dy=0 => dx>0
    }
    bool operator<(const line&o)const{
        return (ll)x*o.y-(ll)y*o.x>0;
    }
};

int main(){
    
    return 0;
}