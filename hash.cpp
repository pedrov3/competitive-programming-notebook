const int P = 1e9 + 7;
mt19937 rmg((int)chrono::steady_clock::now().time_since_epoch().count());
struct hash_str {
  vector<ll> h, p;
  hash_str(string &s) : h(s.size()), p(s.size()) {
    int n = s.size();
    h[0] = s[0];
    int b = uniform_int_distribution<int>(0, P - 1)(rmg);
    for (int i = 1; i < n; i++) {
      h[i] = (h[i - 1] * b + s[i]) % P;
    }
    p[0] = 1;
    for (int i = 1; i < n; i++) {
      p[i] = (p[i - 1] * b) % P;
    }
  }
  ll substr(int l, int r) {  // <- 4 3 2 1 0
    if (l == 0) return h[r];
    ll ans = (h[r] - h[l - 1] * p[r - l + 1]) % P;
    if (ans < 0) {
      ans += P;
    }
    return ans;
  }
};
