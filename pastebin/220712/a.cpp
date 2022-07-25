#include <bits/stdc++.h>

using ll=long long;

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

int main(){
    ll n; std::cin>>n;
    if(n<=2)
        std::cout<<"1\n";
    else{
        Matrix mat={{0,1},{1,1}};
        Matrix vec={{1,1}};
        mat = mat.qpow(n-2);
        std::cout<<(vec*mat)[0][1]<<'\n';
    }
    return 0;
}