struct Matrix {  // Estrutura para representar uma matriz
                 // com operador de multiplicação definido
  vector<vi> m;
  Matrix(bool identify = false) {
    m.resize(MAX, vi(MAX));
    for (auto &x : m)
      for (auto &y : x) y = 0;
    for (int i = 0; i < MAX; i++) m[i][i] = identify;
  }
  Matrix(vector<vi> mat) {
    m.resize(MAX, vi(MAX));
    for (auto &x : m)
      for (auto &y : x) y = 0;
    for (int i = 0; i < MAX; i++)
      for (int j = 0; j < MAX; j++) m[i][j] = mat[i][j];
  }
  vi &operator[](int pos) { return m[pos]; }
  Matrix operator*(Matrix oth) {
    Matrix ans;
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        int &sum = ans[i][j];
        for (int k = 0; k < MAX; k++) {
          sum = (sum + (m[i][k] * oth[k][j]) % P) % P;
        }
      }
    }
    return ans;
  }
};

Matrix expbin(Matrix base, int exp) {  // Exponenciação binária
  Matrix ans(true);
  while (exp) {
    if (exp & 1LL) ans = ans * base;
    base = base * base;
    exp >>= 1;
  }
  return ans;
}
