#include <bits/stdc++.h>
    
using namespace std;
using i64 = long long;
    
constexpr int maxn = 1e3 + 5;
i64 a[maxn];
i64 m[3];
    
int main() {
    /* iostream::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);*/
    int t(0);
    cin >> t;
    while (t--) {
        i64 n(0), h(0);
        cin >> n >> h;
        for (int i(0); i < n; ++i)
            cin >> a[i];
        m[0] = 0;
        m[1] = -1;
        for (int i(0); i < n; ++i) {
            if (m[0] <= a[i]) {
                m[1] = m[0];
                m[0] = a[i];
            } else if (m[1] <= a[i])
                m[1] = a[i];
        }
        i64 cnt(0);
        cnt = (h + m[0] + m[1] - 1) / (m[0] + m[1]);
        if (cnt * (m[0] + m[1]) - h > m[1])
            cout << cnt * 2 - 1;
        else
            cout << cnt * 2;
        cout << "\n";
    }
    return 0;
}

/*

10
10 10
1 2 3 4 5 1 2 3 4 5
10 10
1 2 3 4 1 2 3 4 1 2
10 10 
1 2 3 4 1 2 3 4 1 2

*/