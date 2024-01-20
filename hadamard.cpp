vector<int> hadamard_transform(const vector<int>& a) {
  vector<int> dp = a;
  for (size_t bit = 1; bit < a.size(); bit <<= 1) {
    for (size_t mask = 0; mask < a.size(); mask++) {
      if ((mask & bit) == 0) {
        int u = dp[mask], v = dp[mask ^ bit];
        dp[mask] = u + v;
        dp[mask ^ bit] = u - v;
      }
    }
  }
  return dp;
}

vector<int> inverse_hadamard_transform(const vector<int>& f) {
  vector<int> dp = f;
  for (size_t bit = 1; bit < f.size(); bit <<= 1) {
    for (size_t mask = 0; mask < f.size(); mask++) {
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
vector<int> xor_convolution(const vector<int>& a, const vector<int>& b) {
  vector<int> f = hadamard_transform(a);
  vector<int> g = hadamard_transform(b);
  vector<int> h(f.size());
  for (size_t i = 0; i < f.size(); i++) {
    h[i] = f[i] * g[i];
  }
  vector<int> c = inverse_hadamard_transform(h);
  return c;
}
