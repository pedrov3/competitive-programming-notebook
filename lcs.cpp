int lcs(string &s, string &t) {
  int n = s.size();
  int m = t.size();
  vector<vi> dp = vector<vi>(n + 1, vi(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int ch1 = dp[i - 1][j];
      int ch2 = dp[i][j - 1];
      int ch3 = s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
      dp[i][j] = max({ch1, ch2, ch3});
    }
  }
  return dp[n][m];
}
