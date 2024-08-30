const int P = 1e9 + 7;
mt19937 rmg((int)chrono::steady_clock::now().time_since_epoch().count());
int b1 = uniform_int_distribution<int>(1, P - 1)(rmg);
int b2 = uniform_int_distribution<int>(1, P - 1)(rmg);

struct hash_str {
  vector<ll> h1, p1, h2, p2;
  hash_str() {}
  hash_str(string &s) : h1(s.size()), p1(s.size()), h2(s.size()), p2(s.size()) {
    int n = s.size();
    h1[0] = s[0];
    h2[0] = s[0];
    for (int i = 1; i < n; i++) {
      h1[i] = (h1[i - 1] * b1 + s[i]) % P;
      h2[i] = (h2[i - 1] * b2 + s[i]) % P;
    }
    p1[0] = 1;
    p2[0] = 1;
    for (int i = 1; i < n; i++) {
      p1[i] = (p1[i - 1] * b1) % P;
      p2[i] = (p2[i - 1] * b2) % P;
    }
  }
  ii substr(int l, int r) {  // <- 4 3 2 1 0
    if (l == 0) return {h1[r], h2[r]};
    ll ans1 = (h1[r] - h1[l - 1] * p1[r - l + 1]) % P;
    ll ans2 = (h2[r] - h2[l - 1] * p2[r - l + 1]) % P;
    if (ans1 < 0) {
      ans1 += P;
    }
    if (ans2 < 0) {
      ans2 += P;
    }
    return {ans1, ans2};
  }
  int size() { return h1.size(); }
};
