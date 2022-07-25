#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    long long ans = numeric_limits<long long>::max(), sum = 0;
    for (int i = 0; i < N; ++i) {
        if (i + 1 > X) {
            break;
        }
        sum += A[i] + B[i];
        ans = min(ans, sum + (long long)B[i] * (X - i - 1));
    }
    cout << ans << '\n';
    return 0;
}