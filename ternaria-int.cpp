
int f(int x) {}

int ts(int l, int r) {
  int ans = oo;
  while (l <= r) {
    int dx = (r - l) / 3.0;
    int x1 = l + dx;
    int x2 = r - dx;
    int f1 = f(x1);
    int f2 = f(x2);
    if (f1 > f2) {
      ans = f2;
      l = x1 + 1;
    } else {
      ans = f1;
      r = x2 - 1;
    }
  }
  return ans;
}
