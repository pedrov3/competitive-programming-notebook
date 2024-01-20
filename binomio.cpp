void build() {
  binom[0][0] = 1;
  for (int i = 1; i < MAX; i++) {
    binom[i][i] = binom[i][0] = 1;
    for (int j = 1; j < i; j++) {
      binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
    }
  }
}
