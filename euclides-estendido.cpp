#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> f(int a, int b) {
  if (b == 0) return {a, 1, 0};

  int g, x1, y1;
  tie(g, x1, y1) = f(b, a % b);

  return {g, y1, x1 - (a / b) * y1};
}

ll ext_euclid(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  ll _x, _y;
  ll gcd = ext_euclid(b, a % b, _x, _y);
  x = _y;
  y = _x - (a / b) * _y;
  return gcd;
}

// inverso modular
ll inv_mod(ll a, ll n) {
  ll x, y;
  ext_euclid(a, n, x, y);

  return (x % n + n) % n;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  int x, y, mdc;
  tie(x, y, mdc) = f(a, b);

  cout << x << " " << y << " " << mdc << "\n";
  return 0;
}
