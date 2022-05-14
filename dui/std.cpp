//@Author: ZIMA
#include <bits/stdc++.h>
using namespace std;
#define IOS                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);                       \
    std::cout.tie(0);
#define PP pair<int, int>
#define endl '\n'
#define ll long long
#define int long long
const int INF = 1e16;
char s[3][200050];
int d[3][200050];
bool vis[3][200050];
int f[] = {0, 1, 0, -1, 0};
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= 2; i++) {
	for (int j = 1; j <= n; j++) {
	    d[i][j] = INF;
	    vis[i][j] = 0;
	}
    }
    bool flag = 0;
    int prex = -1, prey = -1;
    for (int i = 1; i <= 2; i++) {
	cin >> s[i] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
	if (s[1][i] == '*' && s[2][i] == '*') {
	    ans++;
	    if (prex == -1 && prey == -1) {
	    } else {
		ans += i - max(prex, prey);
	    }
	    prex = prey = i;
	} else if (s[1][i] == '*' && s[2][i] != '*') {
	    if (prex == -1 && prey == -1) {
	    } else if (prex == -1 && prey != -1) {
		ans += i - prey + 1;
		prey = i;
	    } else if (prex != -1 && prey == -1) {
		ans += i - prex;
	    } else {
		if (i - prex >= i - prey + 1) {
		    ans += i - prey + 1;
		    prey = i;
		} else {
		    ans += i - prex;
		}
	    }
	    prex = i;
	} else if (s[1][i] != '*' && s[2][i] == '*') {
	    if (prex == -1 && prey == -1) {
	    } else if (prex != -1 && prey == -1) {
		ans += i - prex + 1;
		prex = i;
	    } else if (prex == -1 && prey != -1) {
		ans += i - prey;
	    } else {
		if (i - prey >= i - prex + 1) {
		    ans += i - prex + 1;
		    prex = i;
		} else {
		    ans += i - prey;
		}
	    }
	    prey = i;
	}
	// cout<<ans<<" \n"[i==n];
    }
    cout << ans << endl;
}
signed main() {
    IOS;
    int __;
    cin >> __;
    while (__--) solve();
    return 0;
}