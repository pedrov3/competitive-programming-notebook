int memo[20][2][2][4];

int dp(vi &x, vi &y, int i, bool el = true, bool er = true, int p = 0) {
  if (i == -1) {
    return p > 1;
  }
  int &ans = memo[i][el][er][p];
  if (ans != -1) return ans;
  ans = 0;
  int r = er ? y[i] : 9;
  int l = el ? x[i] : 0;
  for (int val = l; val <= r; val++) {
    bool new_er = er && val == r;
    bool new_el = el && val == l;
    ans += dp(x, y, i - 1, new_el, new_er, p + (val != 1));
  }
  return ans;
}

vi num2v(int n) {
  vi retval;
  if (n == 0) retval.push_back(0);
  while (n > 0) {
    retval.push_back(n % 10);
    n /= 10;
  }
  return retval;
}

int solve(int l, int r) {
  vi a = num2v(l);
  vi b = num2v(r);
  while (a.size() < b.size()) a.emplace_back(0);
  memset(memo, -1, sizeof(memo));
  return dp(a, b, a.size() - 1);
}
