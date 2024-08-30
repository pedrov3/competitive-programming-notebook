int B = 1;  // TODO

struct item {
  int l, r, id;
  item() {}
  item(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
};

bool cmp(item a, item b) {
  if (a.l / B != b.l / B) return make_pair(a.l, a.r) < make_pair(b.l, b.r);
  return (a.l / B) % 2 ? a.r < b.r : a.r > b.r;
}

void add(int i) {
  // TODO
}

void rem(int i) {
  // TODO
}

vi mo(vector<item> &ev) {
  sort(all(ev), cmp);
  vi retval(ev.size());
  int _l = 0, _r = -1;
  for (auto &[l, r, id] : ev) {
    while (_l > l) add(--_l);
    while (_r < r) add(++_r);
    while (_l < l) rem(_l++);
    while (_r > r) rem(_r--);
    retval[id] = ans;
  }
  return retval;
}
