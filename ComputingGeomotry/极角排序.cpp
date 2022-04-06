#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

struct point{
    ll x,y;
};

ll crs(const point&o1,const point&o2){
    return o1.x*o2.y-o2.x*o1.y;
}

int xiangxian(point a){
    if(a.x>0&&a.y>=0)  return 1;
    if(a.x<=0&&a.y>0)  return 2;
    if(a.x<0&&a.y<=0)  return 3;
    if(a.x>=0&&a.y<0)  return 4;
    assert(false);
}

bool cmp3(point a,point b){
    if(xiangxian(a)==xiangxian(b))
        return crs(a,b)>0;
    else return xiangxian(a)<xiangxian(b);
}

int main(){
    
    return 0;
}