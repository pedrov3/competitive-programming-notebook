int tab[LOGN][2 * MAXN];

int op(int a, int b) { return min(a, b); }

void build(vi &vet) {
  int N = vet.size();
  int n = 1;
  while (n < N) n *= 2;
  for (int i = 0; (1 << i) < n; i++) {
    int sz = 1 << i;
    for (int m = 0; m < n; m += 2 * sz) {
      tab[i][m + sz - 1] = vet[m + sz - 1];
      for (int j = 1; j < sz; j++) {
        tab[i][m + sz - 1 - j] =
            op(tab[i][m + sz - 1 - j + 1], vet[m + sz - j - 1]);
      }
    }
    for (int m = sz; m < n; m += 2 * sz) {
      tab[i][m] = vet[m];
      for (int j = 1; j < sz; j++) {
        tab[i][m + j] = op(tab[i][m + j - 1], vet[m + j]);
      }
    }
  }
}

int get(int l, int r) {  // [l, r]
  if (l == r) return tab[0][l];
  int h = __builtin_clz(1) - __builtin_clz(l ^ r);
  return op(tab[h][l], tab[h][r]);
}
