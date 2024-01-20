

int getbit(int lx, int ly, int rx, int ry) {  // entrada - fechado
  rx++;                                       // aberto
  ry++;
  return pref[rx][ry] - pref[rx][ly] - pref[lx][ry] + pref[lx][ly];
}

void build() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pref[i + 1][j + 1] =
          pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + mat[i][j];
    }
  }
}
