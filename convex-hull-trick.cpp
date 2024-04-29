struct cht_line {
  int a, b, x;
  cht_line(int _a, int _b, int _x) : a(_a), b(_b), x(_x) {}
  bool operator<(int oth) { return x < oth; }
};

deque<cht_line> cht;

int inter(cht_line x, cht_line y) {
  assert(x.a != y.a);
  if (((x.b - y.b) > 0 && (y.a - x.a) < 0) ||
      ((x.b - y.b) < 0 && (y.a - x.a) > 0)) {
    return -((abs(x.b - y.b) + (y.a - x.a - 1)) / abs(y.a - x.a));
  }
  return (x.b - y.b) / (y.a - x.a);
}

void add_line_back(int a, int b) {  // coefience angular maior
  if (!cht.empty() && cht.back().a == a) cht.pop_back();
  while (cht.size() >= 2) {
    int x = inter(cht[cht.size() - 1], {a, b, 0});
    int y = inter(cht[cht.size() - 2], cht[cht.size() - 1]);
    if (x < y)
      cht.pop_back();
    else
      break;
  }
  if (!cht.empty()) {
    cht.back().x = inter(cht.back(), {a, b, 0});
  }
  cht.emplace_back(a, b, oo);
}

void add_line_front(int a, int b) {  // coeficiente angular menor
  if (!cht.empty() && cht[0].a == a) return;
  while (cht.size() >= 2) {
    int x = inter({a, b, 0}, cht[0]);
    int y = inter(cht[0], cht[1]);
    if (x > y)
      cht.pop_front();
    else
      break;
  }
  cht.push_front({a, b, oo});
  if (cht.size() > 1) {
    cht[0].x = inter(cht[0], cht[1]);
  }
}

int query(int x) {  // maximo
  int pos = lower_bound(all(cht), x) - cht.begin();
  return cht[pos].a * x + cht[pos].b;
}
