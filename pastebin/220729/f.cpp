#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb emplace_back
#define int long long
using ld=long double;
using ll=long long;

#ifndef LOCAL_DEBUG
__attribute((constructor))void unbind(){std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);}
#define du(...) 4933
#else
void _du(){std::cerr<<'\n';}template<class F,class...L>void _du(F f,L...l){std::cerr<<f<<' ';_du(l...);}
#define du(args...){std::cerr<<"[LINE "<<__LINE__<<"]: ";_du(args);}
#endif

template<typename T>using vc=std::vector<T>;
template<typename T>using vvc=std::vector<vc<T>>;
template<typename T>using vvvc=std::vector<vvc<T>>;
template<typename T>using vvvvc=std::vector<vvvc<T>>;

const ld EPS=1e-8;
const ld PI=std::acos((ld)-1.0);

int const p = 1'000'000'007; // 模数

// 矩阵类模板，建议留存
// 矩阵类，继承自 std::vector<std::vector<int>> 即动态二维 int 数组
struct Matrix : std::vector<std::vector<int>>{ 
    using Self=std::vector<std::vector<int>>;
    using Inner=std::vector<int>;
    int n,m;
        // 构造函数，给定矩阵的第一维大小 n，第二维大小 m，以及初始情况下矩阵的每个元素的值 x
    Matrix(int n=0,int m=0,int x=0):Self(n,Inner(m,x)),n(n),m(m){ } 
        // 传入 initializer_list 的构造函数，方便使用 {{},...,{}} 的形式定义 Matrix 对象
    Matrix(std::initializer_list<Inner> const& is):Self(is),n(is.size()),m(is.begin()->size()){}
        // 静态方法，传入一个整数 n，返回一个 n * n 的单位方阵
        static Matrix I(int n){
        Matrix ret(n,n);
        for(int i=0;i<n;++i)
            ret[i][i]=1;
        return ret;
    }
        // 重载 * 乘法运算符，用于支持矩阵的乘法，时间复杂度O(n * m * mat.m)
    Matrix operator*(Matrix const& mat){
        auto const& self=*this;
        assert(m==mat.n);
        Matrix ret(n,mat.m);
        for(int i=0;i<n;++i)
            for(int k=0;k<m;++k)
                for(int j=0;j<mat.m;++j)
                    ret[i][j]=(ret[i][j]+(ll)self[i][k]*mat[k][j]%p)%p;
        return ret;
    }
        // 矩阵快速幂，计算矩阵的 k 次幂，时间复杂度 O(n^3logk)
    Matrix qpow(ll k){
        assert(n==m);
        Matrix ret=I(n);
        Matrix base=*this;
        if(k==0) return ret;
        while(k){
            if(k&1) ret=base*ret;
            base=base*base;
            k>>=1;
        }
        return ret;
    }
        // 重载 << 左移操作符，用于打印矩阵，方便调试
    friend std::ostream& operator<<(std::ostream& os, Matrix const& mat){
        os<<"[\n";
        for(int i=0;i<mat.n;++i){
            os<<"\t[";
            for(int j=0;j<mat.m;++j)
                os<<mat[i][j]<<",]"[j==mat.m-1];
            if(i!=mat.n-1) os<<',';
            os<<'\n';
        }
        os<<"]\n";
        return os;
    }
};

struct node{
    int r,x,k;
    node(int r=0,int x=0,int k=0):r(r),x(x),k(k){}
    bool operator<(node o)const{
        return x<o.x;
    }
};

int32_t main(){
    vc<Matrix>mul(8,Matrix{{1,1,0},{1,1,1},{0,1,1}});
    for(int i=0;i<8;++i){
        if(!(i&1)){
            for(int j=0;j<3;++j){
                mul[i][j][0]=0;
            }
        }
        if(!(i&2)){
            for(int j=0;j<3;++j){
                mul[i][j][1]=0;
            }
        }
        if(!(i&4)){
            for(int j=0;j<3;++j){
                mul[i][j][2]=0;
            }
        }
    }
    Matrix f={{0,1,0}};
    int n,m; std::cin>>n>>m;
    vc<node>A;
    for(int i=0;i<n;++i){
        int row,l,r; std::cin>>row>>l>>r;
        A.pb(node(row,l,1));
        A.pb(node(row,r+1,-1));
    }
    A.pb(node(1,m+1,1));
    A.pb(node(2,m+1,1));
    A.pb(node(3,m+1,1));
    std::sort(all(A));
    int x=1;
    bool first=true;
    std::array<int,3>cnt{0,0,0};
    for(auto [row,nx,nk]:A){
        if(nx==x){
            cnt[row-1]+=nk;
        }else{
            f=f*mul[(!cnt[0])+((!cnt[1])<<1)+((!cnt[2])<<2)].qpow(first?(first=false,nx-x-1):nx-x);
            cnt[row-1]+=nk;
            x=nx;
        }
    }
    std::cout<<f[0][1]<<'\n';
    return 0;
}