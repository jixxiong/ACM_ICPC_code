#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using ll = long long;

// assume that `x`, `y >= 0`, `m > 0` and `x < m`
ll qpow(ll x, ll y, ll m) {
  if (y == 0) {
    return 1;
  }
  ll z = 1;
  while (y) {
    if (y & 1) {
      z = (z * x) % m;
    }
    x = (x * x) % m;
    y >>= 1;
  }
  return z % m;
}

// find a solution `x`, `y`
// such that `a * x + b * y = gcd(a, b)`
ll exgcd(ll &x, ll &y, ll a, ll b) {
  if (b == 0) {
    return x = 1, y = 0, a;
  }
  auto g = exgcd(y, x, b, a % b);
  y -= a / b * x;
  return g;
}

// find `x` such that `x % P[i] = A[i]` for all `i`
// P[i] 互质
ll CRT(std::vector<ll> const &A, std::vector<ll> const &P) {
  ll n = 1, ans = 0;
  for (auto p : P) {
    n *= p;
  }
  for (int i = 0; i < (int)A.size(); ++i) {
    ll m = n / P[i], b, _;
    // find b, such that `m * b % P[i] = 1` with exgcd
    // in other words `m * b + P[i] * _ = 1`
    exgcd(b, _, m, P[i]);
    ans = (ans + A[i] * m * b % n) % n;
  }
  return (ans % n + n) % n;
}

// find `x` such that `x % P[i] = A[i]` for all `i`
// P[i] 不需要互质
ll exCRT(std::vector<ll> &A, std::vector<ll> const &P) {
  ll n = P[0], ans = A[0] % P[0];
  for (int i = 1; i < (int)A.size(); ++i) {
    A[i] %= P[i];
    ll c = ((A[i] - ans) % P[i] + P[i]) % P[i];
    ll x, y;
    auto g = exgcd(x, y, n, P[i]);
    if (c % g != 0) {
      // 无解
      return -1;
    }
    x = (__int128)x * (c / g) % (P[i] / g);
    ans += x * n;
    n *= P[i] / g;
    ans = (ans + n) % n;
  }
  return ans;
}

ll mul(ll x, ll k, ll p) {
  ll ret = 0;
  while (k) {
    if (k & 1) {
      ret = (ret + x) % p;
    }
    x = (x + x) % p;
    k >>= 1;
  }
  return ret;
}

// find `x`, such that a ^ x = b (mod p)
// p is a prime number
ll BSGS(ll a, ll b, ll p) {
  std::unordered_map<ll, ll> q;
  b %= p;
  ll t = (ll)std::sqrt(p) + 1, num = b;
  for (int i = 0; i < t; ++i) {
    q[num] = i;
    num = num * a % p;
  }
  a = qpow(a, t, p);
  if (a != 0) {
    return b == 0 ? 1 : -1;
  }
  num = a;
  for (int i = 1; i <= t; ++i) {
    if (q.count(num)) {
      return i * t - q[num];
    }
    num = num * a % p;
  }
  return -1;
}

struct EulerSieve {
  EulerSieve(size_t n) : phi(n + 1), mu(n + 1) {
    std::vector<bool> vis(n + 1);
    vis[1] = true;
    phi[1] = mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (!vis[i]) {
        prime.emplace_back(i);
        mu[i] = -1;
        phi[i] = i - 1;
      }
      for (auto p : prime) {
        if (i * p > n) {
          break;
        }
        vis[i * p] = true;
        if (i % p == 0) {
          phi[i * p] = phi[i] * p;
          break;
        }
        phi[i * p] = phi[i] * phi[p];
        mu[i * p] = -mu[i];
      }
    }
  }
  std::vector<int> phi, mu, prime;
};

int32_t main() {
  std::ios::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<ll> A, P;
  for (int i = 0; i < n; ++i) {
    ll a, p;
    std::cin >> a >> p;
    A.emplace_back(a);
    P.emplace_back(p);
  }
  std::cout << exCRT(P, A) << '\n';
  return 0;
}
