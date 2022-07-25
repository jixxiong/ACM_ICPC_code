#include <bits/stdc++.h>
#ifndef LOCAL_DEBUG
	__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
	#define er(args...) void()
#else
	#define vwn(x) #x"=",x,"\n"
	void _er(){ std::cerr<<'\n'; } template<class F,class...L> void _er(F f,L...l) { std::cerr<<f<<' '; _er(l...); }
	#define er(args...) _er("\n---- line :",__LINE__,"----"); _er(args); _er("---- line :",__LINE__,"----\n")
#endif

#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;
using ld=long double;
const ld EPS=1e-12;
const ld PI=std::acos((ld)-1.0);

template<typename T>int fcmp(T x, T y=0){ if(std::fabs(x-y)<EPS) return 0; if(x<y) return -1; return 1; }

template<typename fint=ll>
struct Point{
	using Self=Point<fint>;
	fint x, y;
	Point(fint x=0,fint y=0):x(x),y(y){ }
	template<typename G>Point(Point<G> o):x(o.x),y(o.y){ }
	friend std::istream& operator>>(std::istream&is, Self&self){ return is>>self.x>>self.y; }
	friend std::ostream& operator<<(std::ostream&os, Self self){ return os<<"("<<self.x<<", "<<self.y<<")\n"; }
	friend Self operator+(Self self,Self rhs){ return Self{self.x+rhs.x, self.y+rhs.y}; }
	friend Self operator-(Self self,Self rhs){ return Self{self.x-rhs.x, self.y-rhs.y}; }
	friend bool operator==(Self self,Self rhs){ return self.x==rhs.x&&self.y==rhs.y; }
	friend bool operator!=(Self self,Self rhs){ return !(self.x==rhs.x&&self.y==rhs.y); }
	friend Point<ld> operator*(Self self,ld x){ return Point<ld>{self.x*x, self.y*x}; }
	friend Point<ld> operator/(Self self,ld x){ return Point<ld>{self.x/x, self.y/x}; }
	int get_quad(){ if(fcmp(x)>0&&fcmp(y)>=0) return 1; if(fcmp(x)<=0&&fcmp(y)>0) return 2; if(fcmp(x)<0&&fcmp(y)<=0) return 3; if(fcmp(x)>=0&&fcmp(y)<0) return 4; return 0; }
	Point<ld> rot(ld cosr,ld sinr){ return Point<ld>{x*cosr-y*sinr,y*cosr+x*sinr}; }
	fint dot(Self rhs){ return x*rhs.x+y*rhs.y; }
	fint det(Self rhs){ return x*rhs.y-rhs.x*y; }
	fint dis2(Self rhs){ return (x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y); }
	fint len2(){ return x*x+y*y; }
	ld dis(Self rhs){ return std::sqrt(dis2(rhs)); }
	ld len(){ return std::sqrt(len2()); }
	int to_left(Self o1, Self o2){ return fcmp((o2-o1).det(*this-o2)); }
	bool is_par(Self o){ return fcmp(det(o))==0; }
	bool is_ver(Self o){ return fcmp(dot(o))==0; }
	friend ld min_dis2(std::vector<Self>&vec,int l,int r){
		std::vector<Point<ld>>A;
		ld ang=rand()%360/180.0*PI;
		for(int i=l;i<=r;++i) A.pb(vec[i].rotate(ang));
		std::sort(all(A),[](Point<ld>o1,Point<ld>o2){ return fcmp(o1.x,o2.x)==0?fcmp(o1.x,o2.x)<0:fcmp(o1.y,o2.y)<0; });
		ld ret=std::numeric_limits<ld>::max();
		for(int i=0;i<(int)A.size();++i)
			for(int j=i+1;j<=std::min((int)A.size()-1,i+10);++j)
				ret=std::min(ret,A[i].dis2(A[j]));
		return ret;
	}
	friend ld min_dis(std::vector<Self>&vec,int l,int r){ return std::sqrt(min_dis2(vec,l,r)); }
};

template<typename fint=ll>
struct Line{
	using Self=Line<fint>;
	using inner=Point<fint>;
	inner u,d;
	Line(inner x,inner y):u(x),d(y-x){}
	friend bool operator==(Self o1,Self o2){ return o1.d.is_par(o2.d) && o1.d.is_par(o1.u-o2.u); }
	bool is_par(Self o){ return d.is_par(o.d) && !d.is_par(u-o.u); }
	bool is_ver(Self o){ return d.is_ver(o.d); }
	bool is_on(inner o){ return d.is_par(o-u); }
	bool is_in(inner o){ return is_on(o) && fcmp((o-u).dot(o-(u+d)))<=0; }
	bool is_edg(inner o){ return o==u||o==u+d; }
	int to_left(inner o){ return o.to_left(u,u+d); }
	inner inter(Self o){ return Point<ld>(u)+d*((o.d.det(u-o.u))/(d.det(o.d))); }
	ld dis(inner o){ return std::abs(d.det(o-u))/d.len(); }
	Point<ld> proj(inner o){ return Point<ld>(u)+d*((d.dot(o-u))/(d.dot(d))); }
};

template<typename fint=ll>
struct Convex:std::vector<Point<fint>>{
	using inner=Point<fint>;
	using Self=Convex<fint>;
	Convex(int n=0):std::vector<Point<fint>>(n){ }
	friend std::istream& operator>>(std::istream&is,Self&self){ for(auto&x:self) is>>x; return is; }
	friend std::ostream& operator<<(std::ostream&os,Self&self){ for(auto&x:self) os<<x; return os; }
	void sort_by_quad(){
		std::sort(this->begin(),this->end(),[](inner o1,inner o2){ return o1.get_quad()==o2.get_quad()?fcmp(o1.det(o2))>0:o1.get_quad()<o2.get_quad(); });
	}
	void sort_by_ltl(){
		inner ltl=*std::min_element(this->begin(),this->end(),[](inner o1,inner o2){ return fcmp(o1.x,o2.x)==0?fcmp(o1.y,o2.y)<0:fcmp(o1.x,o2.x)<0; });
		std::sort(this->begin(),this->end(),[ltl](inner o1,inner o2){
			auto cross=(o1-ltl).det(o2-ltl);
			return fcmp(cross)==0?(fcmp(o1.x,o2.x)==0?fcmp(o1.y,o2.y)<0:fcmp(o1.x,o2.x)<0):fcmp(cross)>0;
		});
	}
	void sort_by_point(inner o){
		auto cmp=[](inner o1,inner o2){ return o1.get_quad()==o2.get_quad()?fcmp(o1.det(o2))>0:o1.get_quad()<o2.get_quad(); };
		std::sort(this->begin(),this->end(),[&](inner o1,inner o2){ return cmp(o1-o,o2-o); });
	}
	void to_convex(){
		Self& A=*this;
		sort_by_ltl();
		A.erase(std::unique(A.begin(),A.end()),A.end());
		if((int)A.size()==1) return ;
		std::vector<int>B{0,1};
		for(int i=2;i<(int)A.size();++i){
			while(((int)B.size()>=2)&&(A[i].to_left(A[*next(B.rbegin())],A[B.back()])<=0)) B.pop_back();
			B.pb(i);
		}
		Self ret; ret.reserve(B.size());
		std::for_each(all(B),[&](int i){ ret.pb(A[i]); });
		A=ret;
	}
	fint diameter2(){
		auto& g=*this;
		int p=1,n=g.size();
		auto area=[&](int i,int j,int q){
			return (g[j]-g[i]).det(g[q]-g[i]);
		};
		fint ret=0;
		for(int i=0;i<n;++i){
			while(area(i,(i+1)%n,p)<area(i,(i+1)%n,(p+1)%n))p=(p+1)%n;
			ret=std::max({ret,g[i].dis2(g[p]),g[(i+1)%n].dis2(g[p])});
		}
		return ret;
	}
	ld diameter(){
		return std::sqrt(diameter2());
	}
	ld perimeter(){
		Self& g=*this;
		int n=g.size();
		if(n<=1) return 0;
		if(n==2) return g[0].dis(g[1]) * 2; // unsure
		ld ret=0;
		for(int i=0;i<n;++i){
			ret+=g[i].dis(g[(i+1)%n]);
		}
		return ret;
	}
	bool is_in(inner p){
		auto& A=*this; int n=(int)A.size();
		int cnt = 0;
		for(int i=0;i<n;++i){
			auto u=A[i],v=A[(i+1)%n];
			Line<ld>uv(u,v);
			if(uv.is_in(p)) return true;
			int k=fcmp(uv.d.det(p-u));
			int d1=fcmp(u.y-p.y);
			int d2=fcmp(v.y-p.y);
			if(k>0 && d1<=0 && d2>0) cnt--;
			if(k<0 && d1>0 && d2<=0) cnt++;
		}
		return cnt!=0;
	}
};

int32_t main(){
	int n; std::cin>>n;
	std::vector<std::pair<Point<ll>,Point<ll>>>A(n);
	for(int i=0;i<n;++i){
		int x1,x2,y; std::cin>>x1>>x2>>y;
		A[i]=std::make_pair(Point<ll>(x1,y),Point<ll>(x2,y));
	}
	for(int i=0;i<n;++i){
		auto fun=[&](Point<ll>o){
			Convex<ll>B;
			std::vector<std::pair<int,int>>C;
			for(int j=0;j<n;++j){
				if(j==i) continue;
				std::pair<Point<ll>,Point<ll>> p=A[j];
				auto inv=[](Point<ll>o1,Point<ll>o2){
					return Point<ll>(2*o2.x-o1.x,2*o2.y-o1.y);
				};
				if(p.first.y>o.y){
					B.pb(inv(p.second,o));B.pb(inv(p.first,o));
				}else{
					B.pb(p.first);B.pb(p.second);
				}
				C.pb(std::pair<int,int>((int)C.size(),1));
				C.pb(std::pair<int,int>((int)C.size(),-1));
			}
			std::sort(all(C),[&](std::pair<int,int>i1,std::pair<int,int>i2){
				auto o1=B[i1.first],o2=B[i2.first];
				int q1=(o1-o).get_quad(),q2=(o2-o).get_quad();
				if(q1!=q2) return q1<q2;
				return fcmp((o1-o).det(o2-o))>0;
			});
			
		};
	}
	return 0;
}