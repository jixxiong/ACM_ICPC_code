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
const ld PI = std::acos((ld)-1.0);
const ld eps = 1e-8;

int fcmp(ld x,ld y=0){
	if(std::abs(x-y)<eps) return 0;
	if(x<y) return -1;
	return 1;
}

struct Point{
	ld x, y;
	Point(ld x = 0, ld y = 0):x(x), y(y) {}
	Point operator + (Point o){ return Point{x + o.x, y + o.y}; }
	Point operator * (ld k){ return Point{x * k, y * k}; }
	Point operator - (Point o){ return Point{x - o.x, y - o.y}; }
	ld dot(Point o){
		return x * o.x + y * o.y;
	}
	ld dis2(Point o){ return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y); }
	ld dis(Point o){ return std::sqrt(dis2(o)); }
	ld len2(){ return x * x + y * y; }
	ld len(){ return std::sqrt(len2()); }
	Point rot(ld cosr, ld sinr){
		return Point{x * cosr - y * sinr, y * cosr + x * sinr};
	}
	friend std::ostream& operator <<(std::ostream& os, Point o){
		return os<<o.x<< ' '<<o.y;
	}
};


int32_t main(){
	std::cout<<std::fixed<<std::setprecision(8);
	auto get_ori=[&](ld ang, ld dis = 1){
		ang = ang * PI / 180;
		return Point{dis*std::cos(ang), dis*std::sin(ang)};
	};
	ld inr = get_ori(18, 6).y / get_ori(54).y;
	Point Cen(15, 10);
	std::vector<Point> ps{
		{30, 20}, // C
		{30, 0},  // D
		Cen + get_ori(90, 6), // E
		Cen + get_ori(54, inr), // F
		Cen + get_ori(18, 6),  // G
		Cen + get_ori(-18, inr),  // H
		Cen + get_ori(-54, 6),  // I 
		Cen + get_ori(-90, inr),  // J
		Cen + get_ori(-126, 6),  // K 
		Cen + get_ori(-162, inr),  // L 
		Cen + get_ori(162, 6),  // M 
		Cen + get_ori(126, inr)  // N
	};
	int T; std::cin>>T;
	while(T--){
		Point A, B; std::cin>>A.x>>A.y>>B.x>>B.y;
		Point a = B - A;
		ld k = A.dis(B) / 20;
		er(a.dot(Point(0,1)));
		er(a.len2());
		ld cosr = std::abs(a.dot( Point(0, 1) ) / a.len());
		ld sinr = std::sqrt(1 - cosr * cosr);
		er(cosr, sinr);
		if(fcmp(a.x) > 0 && fcmp(a.y) < 0) cosr *= -1;
		else if(fcmp(a.x) < 0 && fcmp(a.y) < 0) cosr *=-1, sinr *=-1;
		else if(fcmp(a.x) < 0 && fcmp(a.y) > 0) sinr *= -1;
		sinr *= -1;
		for(int i=0;i<12;++i){
			Point o = ps[i];
			std::cout<<((o * k).rot(cosr, sinr) + A);
			std::cout<<" \n"[i==11];
		}
	}	
	return 0;
}