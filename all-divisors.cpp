vi find_all_divisors(int n) {
  vi x;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (n / i == i) {
        x.push_back(i);
      } else {
        x.push_back(i);
        x.push_back(n / i);
      }
    }
  }
  x.push_back(n);
  return x;
}
