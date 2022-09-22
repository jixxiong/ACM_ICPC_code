#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()

using wEdge=pair<int,long long>;
struct wGraph:public vector<vector<wEdge>>{ // 存A集合指向B集合的带权边
	int n1,n2; // n1->A集合大小，n2->B集合大小
	wGraph(int n1,int n2):vector<vector<wEdge>>(n1+1),n1(n1),n2(n2+1){}
	void add(int u,int v,long long w){
		operator[](u).emplace_back(wEdge(v,w));
	}
};

// KM算法 => 带权二分图最大完美匹配 O(n^2*m) => 优化的话用最小费用最大流
// 要求 len(A)<=len(B) 必须保证完美匹配
struct MaximalMatching{
	constexpr static long long INF=0x3f3f3f3f3f3f3f3f;
	vector<char>visx,visy; // 辅助vis数组，代表A集合、B集合的元素是否已经匹配
	vector<int>match; // 答案数组，代表B集合的元素匹配对象是谁
	vector<long long>L,R;
	bool fail;
	MaximalMatching(wGraph&G):
		visx(G.n2+1),visy(G.n2+1),match(G.n2+1),
		L(G.n1+1,-INF),R(G.n2+1),fail(false){
		auto dfs=[&](auto&&self,int a)->bool{
			visx[a]=true;
			for(auto [b,w]:G[a]){
				if(visy[b]||L[a]+R[b]!=w)
					continue;
				visy[b]=true;
				if(match[b]==0||self(self,match[b])){
					match[b]=a;
					return 1;
				}
			}
			return 0;
		};
		for(int a=1;a<=G.n1;++a)
			for(auto [_,w]:G[a])
				L[a]=max(L[a],w);
		for(int a=1;a<=G.n1;++a){
			while(true){
				fill(all(visx),0);
				fill(all(visy),0);
				if(dfs(dfs,a))
					break;
				long long d=INF;
				for(int na=1;na<=G.n1;++na)
					if(visx[na])
						for(auto [b,w]:G[na])
							if(!visy[b])
								d=min(d,L[na]+R[b]-w);
				if(d==INF){
					fail=true;
					return ;
				}
				for(int a=1;a<=G.n1;++a)
					if(visx[a])
						L[a]-=d;
				for(int b=1;b<=G.n2;++b)
					if(visy[b])
						R[b]+=d;
			}
		}
	}
};

struct km {
    int n;
    vector<int> mx,my,pre;
    vector<bool> visx,visy;
    vector<int> lx,ly;
    vector<vector<int>> g;
    vector<int> slack;
    int inf,res;
    queue<int> q;
    int nn,mm;
    km(int _n,int _m) {
        nn=_n; mm=_m;
        n=max(nn,mm);
        inf=numeric_limits<int>::max();
        res=0;
        g=vector<vector<int>> (n,vector<int>(n));
        mx=vector<int> (n,-1);
        my=vector<int> (n,-1);
        pre=vector<int> (n);
        visx=vector<bool> (n);
        visy=vector<bool> (n);
        lx=vector<int>(n,-inf);
        ly=vector<int>(n);
        slack=vector<int>(n);
    }
    void add(int u,int v,int w) {
        g[u][v]=w;
    }
    bool check(int v) {
        visy[v]=true;
        if(my[v]!=-1) {
            q.push(my[v]);
            visx[my[v]]=true;
            return false;
        }
        while(v!=-1) {
            my[v]=pre[v];
            swap(v,mx[pre[v]]);
        }
        return true;
    }
    void bfs(int i) {
        while(!q.empty()) {
            q.pop();
        }
        q.push(i);
        visx[i]=true;
        while(true) {
            while(!q.empty()) {
                int u=q.front();
                q.pop();
                for(int v=0;v<n;v++) {
                    if(!visy[v]) {
                        int delta=lx[u]+ly[v]-g[u][v];
                        if(slack[v]>=delta) {
                            pre[v]=u;
                            if(delta) {
                                slack[v]=delta;
                            } else if(check(v)) {
                                return;
                            }
                        }
                    }
                }
            }
            int a=inf;
            for(int j=0;j<n;j++) {
                if(!visy[j]) {
                    a=min(a,slack[j]);
                }
            }
            for(int j=0;j<n;j++) {
                if(visx[j]) {
                    lx[j]-=a;
                }
                if(visy[j]) {
                    ly[j]+=a;
                } else {
                    slack[j]-=a;
                }
            }
            for(int j=0;j<n;j++) {
                if(!visy[j]&&slack[j]==0&&check(j)) {
                    return;
                }
            }
        }
    }
    int solve() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                lx[i]=max(lx[i],g[i][j]);
            }
        }
        for(int i=0;i<n;i++) {
            fill(slack.begin(),slack.end(),inf);
            fill(visx.begin(),visx.end(),false);
            fill(visy.begin(),visy.end(),false);
            bfs(i);
        }
        for(int i=0;i<n;i++) {
            if(g[i][mx[i]]>0) res+=g[i][mx[i]];
            else mx[i]=-1;
        }
        return res;
    }
};


signed main(){
	int n,m;
	scanf("%lld%lld",&n,&m);
	wGraph G(n,n);
	for(int i=1;i<=m;++i){
		int u,v,d;
		scanf("%lld%lld%lld",&u,&v,&d);
		G.add(u,v,d);
	}
	MaximalMatching mat(G);
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=mat.L[i]+mat.R[i];
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i)
		printf("%lld ",mat.match[i]);
	return 0;
}
