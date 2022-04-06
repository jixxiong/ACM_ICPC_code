#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}
#endif
void fk() { std::cerr << '\n'; }
template <class fst, class... lst>
void fk(fst F, lst... L) {
    std::cerr << F << ' ';
    fk(L...);
}
#define all(x) x.begin(), x.end()
#define pb emplace_back
using ll = long long;

// O(n) => suffix array
// str[n+1] 为最小字符
// 若对整数数组求SA应当先进行离散化
template <typename T = char, int sigma = 300>
struct SA {
    std::vector<int> sa, rk, ht;
    SA(T* str, int n) {
	const int SIZE = std::max(sigma, n) + 2;
	sa.resize(SIZE), rk.resize(SIZE), ht.resize(SIZE);
	std::vector<int> s(SIZE << 1), t(SIZE << 1), p(SIZE), cr(SIZE),
	    ct(SIZE);
	str[++n] = 0, ++str;
	int m = [&]() {
	    int m = *std::max_element(str, str + n);
	    std::fill_n(&rk[0], m + 1, 0);
	    for (int i = 0; i < n; i++) rk[(int)str[i]] = 1;
	    for (int i = 0; i < m; i++) rk[i + 1] += rk[i];
	    for (int i = 0; i < n; i++) s[i] = rk[(int)str[i]] - 1;
	    return rk[m];
	}();
	std::function<void(int, int, int*, int*, int*)> sais =
	    [&](int n, int m, int* s, int* t, int* p) {
		int n1 = t[n - 1] = 0, ch = rk[0] = -1, *s1 = s + n;
		auto ps = [&](int x) { sa[cr[s[x]]--] = x; };
		auto pl = [&](int x) { sa[cr[s[x]]++] = x; };
		auto IS = [&](int* v) {
		    std::fill_n(&sa[0], n, -1);
		    std::fill_n(&ct[0], m, 0);
		    for (int i = 0; i < n; i++) ct[s[i]]++;
		    for (int i = 1; i < m; i++) ct[i] += ct[i - 1];
		    for (int i = 0; i < m; i++) cr[i] = ct[i] - 1;
		    for (int i = n1 - 1; ~i; i--) ps(v[i]);
		    for (int i = 1; i < m; i++) cr[i] = ct[i - 1];
		    for (int i = 0; i < n; i++)
			if (sa[i] > 0 && t[sa[i] - 1]) pl(sa[i] - 1);
		    for (int i = 0; i < m; i++) cr[i] = ct[i] - 1;
		    for (int i = n - 1; ~i; i--)
			if (sa[i] > 0 && !t[sa[i] - 1]) ps(sa[i] - 1);
		};
		for (int i = n - 2; ~i; i--)
		    t[i] = s[i] == s[i + 1] ? t[i + 1] : s[i] > s[i + 1];
		for (int i = 1; i < n; i++)
		    rk[i] = t[i - 1] && !t[i] ? (p[n1] = i, n1++) : -1;
		IS(p);
		for (int i = 0, x, y; i < n; i++)
		    if (~(x = rk[sa[i]])) {
			if (ch < 1 || p[x + 1] - p[x] != p[y + 1] - p[y])
			    ch++;
			else
			    for (int j = p[x], k = p[y]; j <= p[x + 1];
				 j++, k++)
				if ((s[j] << 1 | t[j]) != (s[k] << 1 | t[k])) {
				    ch++;
				    break;
				}
			s1[y = x] = ch;
		    }
		if (ch + 1 < n1)
		    sais(n1, ch + 1, s1, t + n, p + n1);
		else
		    for (int i = 0; i < n1; i++) sa[s1[i]] = i;
		for (int i = 0; i < n1; i++) s1[i] = p[sa[i]];
		IS(s1);
	    };
	sais(n, m, &s[0], &t[0], &p[0]);
	for (int i = 0; i < n; i++) rk[sa[i]] = i;
	for (int i = 0, h = ht[0] = 0; i < n - 1; i++) {
	    int j = sa[rk[i] - 1];
	    while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
	    if ((ht[rk[i]] = h)) h--;
	}
	for (int i = n - 1; i >= 1; --i) ++sa[i], rk[i] = rk[i - 1];
	sa.resize(n + 1), ht.resize(n + 1), rk.resize(n + 1);
    }
};

char s[3000010];
char t[1000010];
int top = 0;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> L(n + 1), R(n + 1);
    std::vector<int> idx(1);
    for (int i = 1; i <= n; ++i) {
	std::cin >> (t + 1);
	if (i > 1) s[++top] = '#', idx.pb(0);
	L[i] = top + 1;
	for (int j = 1; t[j]; ++j) {
	    s[++top] = t[j];
	    idx.pb(i);
	}
	R[i] = top;
    }
    SA<char> sa(s, top);

    return 0;
}

/*

3
ababa
babab
aba

*/