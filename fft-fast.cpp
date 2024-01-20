typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct complex_t {
  double a{0.0}, b{0.0};
  complex_t() {}
  complex_t(double na) : a{na} {}
  complex_t(double na, double nb) : a{na}, b{nb} {}
  const complex_t operator+(const complex_t &c) const {
    return complex_t(a + c.a, b + c.b);
  }
  const complex_t operator-(const complex_t &c) const {
    return complex_t(a - c.a, b - c.b);
  }
  const complex_t operator*(const complex_t &c) const {
    return complex_t(a * c.a - b * c.b, a * c.b + b * c.a);
  }
  const complex_t operator/(const int &c) const {
    return complex_t(a / c, b / c);
  }
};
using cd = complex_t;
const double PI = acos(-1);
void fft(vector<cd> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w = w * wlen;
      }
    }
  }
  if (invert) {
    for (cd &x : a) {
      x = x / n;
    }
  }
}
vector<ll> multiply(vector<int> const &a, vector<int> const &b) {
  vector<cd> fa(a.begin(), a.end());
  vector<cd> fb(b.begin(), b.end());
  int n = 1;
  while (n < int(a.size() + b.size())) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i];
  fft(fa, true);
  vector<ll> result(n);
  for (int i = 0; i < n; i++) result[i] = round(fa[i].a);
  return result;
}
