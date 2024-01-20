int b[MAX], st[MAX][K];

void kmpp(string &p) {
  int i = 0, j = -1, n = p.size();
  b[0] = -1;
  while (i < n) {
    while (j >= 0 && p[i] != p[j]) j = b[j];
    ++i, ++j;
    b[i] = j;
  }
  for (int i = 0; i < n; i++)
    for (int ch = 0; ch < K; ch++)
      if (to_i(p[i]) == ch)
        st[i][ch] = i + 1;
      else
        st[i][ch] = b[i] == -1 ? 0 : st[b[i]][ch];
}

bool kmp(string &t, string &p) {
  int i = 0, j = 0, n = t.size(), m = p.size();
  while (i < n) {
    j = st[j][to_i(t[i])];
    ++i;
    if (j == m) {
      j = b[j];
      return true;
    }
  }
  return false;
}
