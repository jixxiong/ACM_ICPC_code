#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}
#endif
void pr() { std::cerr << '\n'; }
template <class fst, class... lst> void pr(fst F, lst... L) {
    std::cerr << F << ' ';
    pr(L...);
}
#define all(x) x.begin(), x.end()
#define pb emplace_back
using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, int> mp;
    int max = 0, id = -1;
    for (int i = 1; i <= n; ++i) {
	std::string str;
	int sco;
	std::cin >> str >> sco;
	if (mp.count(str))
	    continue;
	mp[str] = sco;
	if (sco > max)
	    id = i, max = sco;
    }
    assert(id != -1);
    std::cout << id << '\n';
    return 0;
}