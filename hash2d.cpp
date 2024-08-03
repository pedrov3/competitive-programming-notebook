char mat[MAX][MAX];      // TODO
int hs[MAX][MAX];        // TODO
int PWX[MAX], PWY[MAX];  // TODO
int n, m;                // TODO

struct Hashing {
  static const int PX = 3731, PY = 2999, mod = 998244353;
  Hashing() {
    PWX[0] = PWY[0] = 1;
    for (int i = 0; i < n; i++) PWX[i + 1] = 1LL * PWX[i] * PX % mod;
    for (int i = 0; i < m; i++) PWY[i + 1] = 1LL * PWY[i] * PY % mod;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        hs[i + 1][j + 1] = (((((1LL) * hs[i][j + 1] * PX) % mod +
                              ((1LL) * hs[i + 1][j] * PY) % mod) %
                                 mod -
                             (((1LL) * hs[i][j] * PX) % mod) * PY) %
                                mod +
                            (mat[i][j])) %
                           mod;
        hs[i + 1][j + 1] %= mod;
        hs[i + 1][j + 1] += mod;
        hs[i + 1][j + 1] %= mod;
      }
    }
  }
  int get_hash(int x1, int y1, int x2, int y2) {  // 1-indexado inclusivo
    x1--;
    y1--;
    int dx = x2 - x1, dy = y2 - y1;
    return (((1LL * hs[x2][y2]) - (1LL * hs[x2][y1]) * PWY[dy] % mod + mod) %
                mod -
            1LL * (hs[x1][y2] - (1LL * hs[x1][y1]) * PWY[dy] % mod + mod) %
                mod * PWX[dx] % mod +
            mod) %
           mod;
  }
  int get_hash() { return get_hash(1, 1, n, m); }
};
// TODO: simplificar
