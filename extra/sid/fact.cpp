struct fact {
  vi m, p, divisores;  // TODO: trocar por um map
  fact(ll a) {
    for (auto &x : primos) {
      int _m = 0;
      while (a % x == 0) _m++, a /= x;
      if (_m) {
        m.push_back(_m);
        p.push_back(x);
      }
    }
    if (a > 1) {
      m.push_back(1);
      p.push_back(a);
    }
  }
  void b(int i = 0, ll val = 1) {
    if (i == p.size()) {
      divisores.push_back(val);
      return;
    }
    ll _p = 1;
    for (int _m = 0; _m <= m[i]; _m++) {
      b(i + 1, val * _p);
      _p *= p[i];
    }
  }
  vi get_divisores() {
    b();
    return divisores;
  }
  void imprimir() {
    for (int i = 0; i < m.size(); i++)
      cout << (i > 0 ? "," : "") << p[i] << " ^ " << m[i]
           << (i == m.size() - 1 ? "\n" : "");
  }
};
