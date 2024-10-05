int n, k;           // TODO
vi prv_dp, new_dp;  // TODO:

int c(int l, int r) {}

void solve(int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int opt = -1, mx = -oo; // TODO: maximo?
  for (int i = optl; i <= min(mid, optr); i++) {
    int now = (i == 0 ? 0 : prv_dp[i - 1]) + c(i, mid);
    if (now > mx) mx = now, opt = i;
  }
  new_dp[mid] = mx;
  solve(l, mid - 1, optl, opt);
  solve(mid + 1, r, opt, optr);
}

int solve() {
  fill(all(prv_dp), -oo); // TODO: maximo?
  for (int kk = 1; kk <= k; kk++) {
    solve(0, n - 1, 0, n - 1);
    prv_dp = new_dp;
  }
  return prv_dp[n - 1];
}
