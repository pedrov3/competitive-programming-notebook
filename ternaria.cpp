
double f(double x) {  // TODO
}

double ts(double l, double r) {
  const int MAXIT = 500;  // TODO
  for (int tt = 0; tt < MAXIT; tt++) {
    double dx = (r - l) / 3.0;
    double x1 = l + dx;
    double x2 = r - dx;
    if (f(x1) < f(x2))
      l = x1;
    else
      r = x2;
  }
  return l;  // TODO
}
