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
    int n, w;
    std::cin >> n >> w;
    std::vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i)
	std::cin >> A[i];
    std::set<int> st;
    for (int i = 1; i <= n; ++i) {
	if (A[i] <= w)
	    st.insert(A[i]);
	for (int j = i + 1; j <= n; ++j) {
	    if (A[i] + A[j] <= w)
		st.insert(A[i] + A[j]);
	    for (int k = j + 1; k <= n; ++k) {
		if (A[i] + A[j] + A[k] <= w)
		    st.insert(A[i] + A[j] + A[k]);
	    }
	}
    }
    std::cout << st.size() << '\n';
    return 0;
}