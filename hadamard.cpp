vi hadamard_transform(const vi& a) {
  vi dp = a;
  for (int bit = 1; bit < a.size(); bit <<= 1) {
    for (int mask = 0; mask < a.size(); mask++) {
      if ((mask & bit) == 0) {
        int u = dp[mask], v = dp[mask ^ bit];
        dp[mask] = u + v;
        dp[mask ^ bit] = u - v;
      }
    }
  }
  return dp;
}

vi inverse_hadamard_transform(const vi<int>& f) {
  vi dp = f;
  for (int bit = 1; bit < f.size(); bit <<= 1) {
    for (int mask = 0; mask < f.size(); mask++) {
      if ((mask & bit) == 0) {
        int x = dp[mask], y = dp[mask ^ bit];
        dp[mask] = (x + y) / 2;
        dp[mask ^ bit] = (x - y) / 2;
      }
    }
  }
  return dp;
}

// a.size() == b.size() == 2^k
vi xor_convolution(const vi<int>& a, const vi<int>& b) {
  vi f = hadamard_transform(a);
  vi g = hadamard_transform(b);
  vi h(f.size());
  for (int i = 0; i < f.size(); i++) {
    h[i] = f[i] * g[i];
  }
  vi c = inverse_hadamard_transform(h);
  return c;
}
