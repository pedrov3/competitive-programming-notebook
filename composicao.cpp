int weak(int n, int k) {
  return c(n + k - 1, k - 1);  // binomio
}

int strong(int n, int k) { return c(n - 1, k - 1); }
