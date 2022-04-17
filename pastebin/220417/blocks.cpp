#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 15;
const int MAXS = 1 << 10;
const int P = 998244353;
bool cover[MAXS]; int dp[MAXS], inv[MAXN];
int n, bit[MAXS], cnt[MAXS]; ll inter[MAXS];
int xl[MAXN], xr[MAXN], yl[MAXN], yr[MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int work(int s) {
	if (dp[s] != -1) return dp[s];
	if (cover[s]) return dp[s] = 0;
	int ans = n, cnt = 0;
	for (int i = 1; i <= n; i++)
		if ((s & bit[i]) == 0) {
			cnt++;
			ans = (ans + work(s | bit[i])) % P;
		}
	ans = 1ll * ans * inv[cnt] % P;
	return dp[s] = ans;
}
int main() {
	int T; cin >> T;
	while (T--) {
		cin >> n;
		xl[0] = yl[0] = 1;
		cin >> xr[0] >> yr[0];
		for (int i = 1; i <= n; i++) {
			cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
			xl[i]++, yl[i]++;
		}
		for (int i = 1; i <= n; i++)
			inv[i] = power(i, P - 2);
		int u = (1 << n) - 1;
		for (int i = 1; i <= n; i++)
			bit[i] = 1 << (i - 1);
		for (int s = 1; s <= u; s++) {
			cnt[s] = cnt[s - (s & -s)] + 1;
			int xL = xl[0], xR = xr[0], yL = yl[0], yR = yr[0];
			for (int i = 1; i <= n; i++)
				if (bit[i] & s) {
					xL = max(xL, xl[i]);
					xR = min(xR, xr[i]);
					yL = max(yL, yl[i]);
					yR = min(yR, yr[i]);
				}
			if (xL <= xR && yL <= yR) inter[s] = (xR - xL + 1ll) * (yR - yL + 1ll);
			else inter[s] = 0;
		}
		for (int s = 1; s <= u; s++) {
			ll cur = 0;
			for (int t = s; t >= 1; t = (t - 1) & s)
				if (cnt[t] & 1) cur += inter[t];
				else cur -= inter[t];
			if (cur == (xr[0] + 0ll) * (yr[0] + 0ll)) cover[s] = true;
			else cover[s] = false;
		}
		if (cover[u]) {
			memset(dp, -1, sizeof(dp));
			printf("%d\n", work(0));
		} else puts("-1");
		
	}
	return 0;
}