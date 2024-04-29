void rotate90(vector<vi> &mat) {
  int n = mat.size();
  vector<vi> tmp = mat;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[j][n - i - 1] = tmp[i][j];
    }
  }
}
