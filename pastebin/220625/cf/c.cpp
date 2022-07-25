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

int32_t main(){
    int T; std::cin>>T;
    while(T--){
    	int n, m; std::cin>>n>>m;
    	std::list<int>A;
    	ll s1=0;
    	for(int i=0;i<n;++i){
    		int x; std::cin>>x;
    		s1+=x;
    		A.push_back(x);
    	}
    	int k; std::cin>>k;
    	std::list<int>B;
    	ll s2=0;
    	for(int i=0;i<k;++i){
    		int x; std::cin>>x;
    		s2+=x;
    		B.push_back(x);
    	}
    	if(s1!=s2){
    		std::cout<<"No"<<'\n';
    		continue;
    	}
    	auto i=A.begin(),j=B.begin();
    	bool fail=false;
    	while(i!=A.end()&&j!=B.end()){
    		if(*i==*j){
    			i++;
    			j++;
    			continue;
    		}
    		if(*i>=m**j&&(*i)%m==0){
    			int add=(*i)/m;
    			for(int t=1;t<=m;++t){
    				A.insert(std::next(i),add);
    			}
    			i=A.erase(i);
    			continue;
    		}
    		if(*j>=m**i&&(*j)%m==0){
    			int add=(*j)/m;
    			for(int t=1;t<=m;++t){
    				B.insert(std::next(j),add);
    			}
    			j=B.erase(j);
    			continue;
    		}
    		fail=true;
    		break;
    	}
    	std::cout<<(fail||i!=A.end()||j!=B.end()?"No":"Yes")<<'\n';
    }
    return 0;
}