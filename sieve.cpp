vi p(MAXS + 1, 1), d(MAXS + 1), primos;
void sieve(int n = MAXS) {
  p[0] = p[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (p[i]) {
      primos.emplace_back(i);
      d[i] = i;
      for (int j = i * i; j <= n; j += i) {
        p[j] = 0;
        d[j] = i;
      }
    }
  }
}
