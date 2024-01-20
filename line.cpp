struct line {
  int a, b, c;
  line() {}
  // a * x + b * y + c = 0
  line(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
  line(ii x, ii y) {
    a = (x.second - y.second);
    b = (-x.first + y.first);
    c = x.first * y.second - x.second * y.first;

    int g = gcd(a, gcd(b, c));
    a /= g;
    b /= g;
    c /= g;
  }
  bool is(ii x) {
    int v1 = a * x.first;
    int v2 = b * x.second;
    //       cout << v1 + v2 << " vs " << -c << "\n";
    return v1 + v2 == -c;
  }
};
