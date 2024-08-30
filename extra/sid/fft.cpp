typedef complex<double> cd;

constexpr double PI = acos(-1);

vector<cd> fft(vector<cd> a) {
  int n = a.size();
  if (n == 1) {
    return a;
  }

  vector<cd> left(n / 2), right(n / 2);
  for (int i = 0; i < n / 2; i++) {
    left[i] = a[2 * i];
    right[i] = a[2 * i + 1];
  }
  left = fft(left);
  right = fft(right);

  cd wn(cos((2 * PI) / n), sin((2 * PI) / n));
  cd w = 1;
  for (int i = 0; i < n; i++) {
    a[i] = left[i % (n / 2)] + w * right[i % (n / 2)];
    w *= wn;
  }
  return a;
}

// TODO: entender melhor e tbm a forma matricial
vector<cd> inv_fft(vector<cd> a) {
  int n = a.size();
  if (n == 1) {
    return a;
  }
  vector<cd> left(n / 2), right(n / 2);
  for (int i = 0; i < n / 2; i++) {
    left[i] = a[2 * i];
    right[i] = a[2 * i + 1];
  }
  left = inv_fft(left);
  right = inv_fft(right);

  cd wn(cos((-2 * PI) / n), sin((-2 * PI) / n));
  cd w = 1;
  for (int i = 0; i < n; i++) {
    a[i] = left[i % (n / 2)] + w * right[i % (n / 2)];
    a[i] /= 2;
    w *= wn;
  }
  return a;
}

vi multiply(vi a, vi b) {
  int n = 1;
  while (n < a.size() + b.size()) n *= 2;
  vector<cd> _a(n), _b(n);
  for (int i = 0; i < a.size(); i++) {
    _a[i] = complex<double>(a[i], 0);
  }
  for (int i = 0; i < b.size(); i++) {
    _b[i] = complex<double>(b[i], 0);
  }

  vector<cd> a1 = fft(_a);
  vector<cd> b1 = fft(_b);

  vector<cd> c1(n);
  for (int i = 0; i < n; i++) {
    c1[i] = a1[i] * b1[i];
  }
  vector<cd> retval_cd = inv_fft(c1);
  vi retval(n);
  for (int i = 0; i < n; i++) {
    retval[i] = round(retval_cd[i].real());
  }
  return retval;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int grau;
  cin >> grau;

  vi a(grau + 1), b(grau + 1);
  for (int i = 0; i < grau + 1; i++) {
    int coef;
    cin >> coef;
    a[i] = coef;
  }
  for (int i = 0; i < grau + 1; i++) {
    int coef;
    cin >> coef;
    b[i] = coef;
  }
  vi retval = multiply(a, b);
  for (auto &x : retval) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}
