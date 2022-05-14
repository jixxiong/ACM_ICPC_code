#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void pr(){ std::cerr<<'\n'; } template<class fst,class...lst>
void pr(fst F, lst... L) { std::cerr<<F<<' '; pr(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;
ld const PI=std::acos(-1.0);

struct node{
    ld x,y;
    node():x(0),y(0){}
    node(ld ang):x(std::cos(PI*ang/180)),y(std::sin(PI*ang/180)){}
    node(int ang):x(std::cos(PI*ang/180)),y(std::sin(PI*ang/180)){}
    node(ld x,ld y):x(x),y(y){}
    friend node operator+(node const&o1,node const&o2){
        return node(o1.x+o2.x,o1.y+o2.y);
    }
    friend node operator-(node const&o1,node const&o2){
        return node(o1.x-o2.x,o1.y-o2.y);
    }
    friend ld operator*(node const&o1,node const&o2){
        return o1.x*o2.x+o1.y*o2.y;
    }
    friend node operator*(node const&o1,ld x){
        return node(o1.x*x,o1.y*x);
    }
    friend node operator*(ld x,node const&o1){
        return node(o1.x*x,o1.y*x);
    }
    friend node operator/(node const&o1,ld x){
        return node(o1.x/x,o1.y/x);
    }
    friend ld dis2(node const&o1,node const&o2){
        return (o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y);
    }
    friend ld dis(node const&o1,node const&o2){
        return std::sqrt((o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y));
    }
    friend std::ostream& operator<<(std::ostream& os,node const& o){
        return os<<o.x<<' '<<o.y;
    }
};

int main(){
    int T; std::cin>>T;
    while(T--){
        // for(int s_ang=0;s_ang<=359;++s_ang){
        //     for(int t_ang=0;t_ang<=359;++t_ang){
        std::cout<<std::fixed<<std::setprecision(8);
        int s_ang,t_ang; std::cin>>s_ang>>t_ang;
        // std::cout<<s_ang << ' '<<t_ang<<'\n';
        node s(s_ang),t(t_ang);
        if(s_ang==t_ang){
            std::cout<<"0\n";
            std::cout<<s<<'\n';
        }else if(std::abs(s_ang-t_ang)==180){
            std::cout<<"4\n";
            std::cout<<s<<'\n';
            node a=s+node(s_ang+90);
            std::cout<<a<<'\n';
            node b=a+node(s_ang+180);
            std::cout<<b<<'\n';
            node c=b+node(s_ang+180);
            std::cout<<c<<'\n';
            node d=c+node(s_ang+270);
            std::cout<<d<<'\n';
        }else if(std::abs(s_ang-t_ang)<=90){
            std::cout<<"2\n";
            std::cout<<s<<'\n';
            std::cout<<(s+t)<<'\n';
            std::cout<<t<<'\n';
        }else{
            std::vector<node>ans{s};
            int flg=1;
            int x=(s_ang-t_ang);
            if(x>0){
                if(x<180) flg=-1;
                else flg=1;
            }else{
                x=-x;
                if(x<180) flg=-1;
                else flg=1;
            }
            node a=s+node(s_ang+flg*90);
            ans.pb(a);
            node b=(a+t)/2;
            ld ht=std::sqrt(1-dis2(b,t));
            ld ang=std::atan2((a-t).y,(a-t).x)*180/PI;
            node c1=b+node(ang+90)*ht;
            node c2=b+node(ang-90)*ht;
            if(dis(c1,node(0,0))>=1)
                ans.pb(c1);
            else
                ans.pb(c2);
            if((node(0,0)-t)*(ans.back()-t)<1e-8){
                std::cout<<"3\n";
                ans.pb(t);
                for(auto x:ans) std::cout<<x<<'\n';
                continue;
            }else{
                std::cout<<"4\n";
                std::cout<<s<<'\n';
                a=ans[1];
                std::cout<<a<<'\n';
                node b=a+node(s_ang+180);
                std::cout<<b<<'\n';
                std::cout<<(b+t)<<'\n';
                std::cout<<t<<'\n';
            }
        }
            // }}
    }
    return 0;
}