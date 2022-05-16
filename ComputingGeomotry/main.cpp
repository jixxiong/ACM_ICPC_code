#include "head.h"
#include "point.h"
#include "line.h"
#include "convex.h"

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