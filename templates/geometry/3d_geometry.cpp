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

template<typename fint=ll>
struct Point3{
	using Self=Point3<fint>;
	fint x,y,z;
	Point3(fint x=0,fint y=0,fint z=0):x(x),y(y),z(z){ }
	friend std::istream& operator>>(std::istream&is, Self&self){ return is>>self.x>>self.y>>self.z; }
	friend std::ostream& operator<<(std::ostream&os, Self&self){ return os<<"("<<self.x<<", "<<self.y<<", "<<self.z<<")"; }
	friend Self operator+(Self self,Self rhs){ return Self{self.x+rhs.x, self.y+rhs.y, self.z+rhs.z}; }
	friend Self operator-(Self self,Self rhs){ return Self{self.x-rhs.x, self.y-rhs.y, self.z-rhs.z}; }
	friend Point3<ld> operator*(Self self,ld x){ return Point3<ld>{self.x*x, self.y*x, self.z*x}; }
	friend Point3<ld> operator/(Self self,ld x){ return Point3<ld>{self.x/x, self.y/x, self.z/x}; }
	fint dot(Self rhs){ return x*rhs.x+y*rhs.y+z*rhs.z; }
	Self det(Self rhs){ return { (y*rhs.z-rhs.y*z), -(x*rhs.z-rhs.x*z), (x*rhs.y-rhs.x*y) }; }
	fint dis2(Self rhs){ return (x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y)+(z-rhs.z)*(z-rhs.z); }
	ld dis(Self rhs){ return std::sqrt(dis2(rhs)); }
};

template<typename fint=ll>
struct Circle3{
	using Self=Circle3<fint>;
	Point3<fint>cen;
	fint rad;
	Circle3(fint x=0,fint y=0,fint z=0,fint rad=0):cen(x,y,z),rad(rad){ }
	bool rela(Self o){
		// -1=> 外不相交, 0 => 外切, 1 => 相交, 2 => 内切, 3 => 内涵
		fint dis = cen.dis2(o.cen);
		if(fcmp(dis,(rad+o.rad)*(rad+o.rad))>0) return -1;
		if(fcmp(dis,(rad+o.rad)*(rad+o.rad))==0) return 0;
		if(fcmp(std::sqrt(dis)+std::min(rad,o.rad),std::max(rad,o.rad))==0) return 2;
		if(fcmp(std::sqrt(dis)+std::min(rad,o.rad),std::max(rad,o.rad))<0) return 3;
		return 1;
	}
};


int32_t main(){
	
	return 0;
}