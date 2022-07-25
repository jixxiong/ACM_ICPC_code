#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-12)
#define double long double
#define ld long double
    const int N=2e5+10,inf=2e9;
    int n;
    int a[N];
    int pre[N][2],suf[N][2];
    int fcmp(ld x,ld y=0){
        if(std::abs(x-y)<eps) return 0;
        if(x<y) return -1;
        return 1;
    }
    inline void check(double t1,double t2,double &t3,double &t4)
    {
        if(t1<t3||(fabs(t1-t3)<eps&&t2>t4)) t3=t1,t4=t2;
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        cin>>n;
        pre[0][0]=suf[n+1][0]=inf*inf;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            pre[i][0]=min(pre[i-1][0],a[i]);
            pre[i][1]=max(pre[i-1][1],a[i]);
        }
        for(int i=n;i>=1;--i)
        {
            suf[i][0]=min(suf[i+1][0],a[i]);
            suf[i][1]=max(suf[i+1][1],a[i]);
        }
        cout<<fixed<<setprecision(10)<<1.0000000000<<' ';
        for(int i=2;i<=n;++i)
        {
            //最大值在后面
            //(1-t)*suf[i][1]>=pre[i-1][1]
            //(1-t)>=pre[i-1][1]/suf[i][1]
            //t<=1-pre[i-1][1]/suf[i][1]
            double dx=inf,ans=-1;
            double tr=1.0-1.0*pre[i-1][1]/(1.0*suf[i][1]);
            //if(tr>1) tr=1;
            //if(tr<0) tr=0;
            //最小值在后面
            //(1-t)*suf[i][0]<=pre[i-1][0]
            //(1-t)<=pre[i-1][0]/suf[i][0]
            //t>=1-pre[i-1][0]/suf[i][0];
            double tl=1.0-1.0*pre[i-1][0]/(1.0*suf[i][1]);
            //if(tl>1) tl=1;
            //if(tl<0) tl=0;
            if(tl-eps<tr)
            {
                double t1,t2;
                //最大值在后面，最小值在后面 t<=tr,t>=tl
                if(tl-eps<1&&tr+eps>0)
                {
                    t2=min((double)1.0,tr);
                    t1=1.0*(suf[i][1]-suf[i][0])*(1.0-t2);
                    check(t1,t2,dx,ans);
                }
                
                //最大值在后面，最小值在前面 t<=tr,t<=tl
                if(tl+eps>0)
                {
                    t2=min((double)1.0,tl),t1=1.0*(suf[i][1]*(1.0-t2)-pre[i-1][0]);
                    check(t1,t2,dx,ans);
                }
                
                //最大值在前面，最小值在后面 t>=tr,t>=tl
                if(tr-eps<1)
                {
                    t2=max((double)0.0,tr),t1=1.0*(pre[i-1][1]-suf[i][0]*(1.0-t2));
                    check(t1,t2,dx,ans);
                }
                
                //最大值在前面，最小值在前面,t>=tr,t<=tl 不存在
            }
            else
            {
                double t1,t2;
                //tr<=tl
                //最大值在后面，最小值在后面 t<=tr,t>=tl 不存在
                //最大值在后面，最小值在前面 t<=tr,t<=tl
                if(tr+eps>0)
                {
                    t2=min((double)1.0,tr),t1=1.0*(suf[i][1]*(1.0-t2)-pre[i-1][0]);
                    //cout<<t1<<"!!"<<' '<<t2<<"!!!"<<endl;

                    check(t1,t2,dx,ans);
                }
                
                //最大值在前面，最小值在后面 t>=tr,t>=tl
                if(tl-eps<1)
                {
                    t2=max((double)0.0,tl),t1=1.0*(pre[i-1][1]-suf[i][0]*(1.0-t2));
                    check(t1,t2,dx,ans);
                }
                
                //最大值在前面，最小值在前面,t>=tr,t<=tl
                if(tr-eps<1&&tl+eps>0)
                {
                    t2=min((double)1.0,tl),t1=1.0*(pre[i-1][1]-pre[i-1][0]);
                    check(t1,t2,dx,ans);
                }
                
            }
            cout<<fixed<<setprecision(10)<<ans<<' ';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
4 
abcbccbc
cbabccbc
*/