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
    int getQuad()const {
        if(x>0&&y>=0) return 1;
        if(x<=0&&y>0) return 2;
        if(x<0&&y<=0) return 3;
        if(x>=0&&y<0) return 4;
        assert(false);
    }
    friend ll crs(const point&o1,const point&o2){
        return o1.x*o2.y-o2.x*o1.y;
    }
};

bool cmp(const point& o1,const point& o2){
    if(o1.getQuad()==o2.getQuad()) return crs(o1,o2)>0;
    else return o1.getQuad()<o2.getQuad();
}

int main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<point>A(n);
        for(int i=0;i<n;++i){
            std::cin>>A[i].x>>A[i].y;
        }
        std::sort(all(A),cmp);
        int ans=n;
        for(int i=0,j=0;i<n;++i){
            while(j<=i)j++;
            while(j-i+1<=n&&crs(A[i],A[j%n])>=0)
                j++;
            ans=std::min(ans,std::min(j-i,n-(j-i)));
        }
        std::cout<<ans<<'\n';
    }
    return 0;
}


/*
1
2
1 0
2 0

3
2
1 0
2 0
3
1 0
0 1
-1 -1
5
2 -1
1 2
-1 2
-2 -1
0 -2


1
8
1 0
1 1
0 1
-1 1
-1 0
-1 -1
0 -1
1 -1
*/