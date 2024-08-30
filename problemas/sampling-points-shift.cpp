// Um polinômio f(x) de grau menor que N está oculto são dados N valores $f(0), f(1), ... , f(N-1) e dois inteiros c, M.
// Calcule f(c + k) (mod 998244353) para k = 0, 1, ... , M - 1.
vector<mint> sampling_points_shift(const vector<mint>& f, mint c, int m) {
  int n = f.size();
  vector<mint> fat(n + m), a(n + m), b(n + m), s(n + m), res(m);
  fat[0] = 1;
  for (int i = 1; i < n + m; i++) fat[i] = fat[i - 1] * i;
  for (int i = 0; i < n + m; i++) {
    if (i < n) {
      int sign = ((n - 1) - i) & 1 ? -1 : 1;
      a[i] = (sign * f[i]) / (fat[(n - 1) - i] * fat[i]);
    }
    b[i] = ((c - n + i + 1) == 0) ? 1 : 1 / (c - n + i + 1);
  }
  s[0] = 1;
  for (int i = 1; i < n + m; i++)
    s[i] = s[i - 1] * max((int)(c - n + i).val(), (int)1);
  auto retval = convolution(a, b);
  for (int k = 0; k < m; k++) {
    int x = -1;
    if ((c + k).val() < n) {
      x = (c + k).val();
      if (x + modint::mod() < n) continue;// small mod, two zero case
    }
    if (x == -1) res[k] = retval[n + k - 1] * s[n + k] / s[k]; // non-zero case
    else res[k] = f[x]; // zero-case
  }
  return res;
}
