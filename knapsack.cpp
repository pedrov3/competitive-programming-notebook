
int memo[MAX][MAX];
vi c, v;

int knap(int i, int j) {
  if (i == c.size()) return memo[i][j] = 0;
  if (memo[i][j] != -1) return memo[i][j];

  int ch1 = -oo;
  if (c[i] <= j) {
    ch1 = knap(i + 1, j - c[i]) + v[i];
  }
  int ch2 = knap(i + 1, j);

  return memo[i][j] = max(ch1, ch2);
}
