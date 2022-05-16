#include "head.h"
#include "point.cpp"
#include "line.cpp"
#include "convex.cpp"

int main(){
    int n; std::cin>>n;
    std::vector<point> A(n);
    for(int i=0;i<n;++i){
        std::cin>>A[i].x>>A[i].y;
    }
    auto g=get_convex_hull(A);
    std::cout<<diameter_squ(get_convex_hull(A))<<'\n';
    return 0;
}