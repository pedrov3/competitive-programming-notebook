struct item {
  bool isValid = false;
  // TODO
  item operator+(item oth) {
    item c = item();
    // TODO
    return c;
  }
};

item seg[4 * MAX];

void buildseg(vi &a, int pos, int lx, int rx) {
  if (rx - lx == 1) {
    if (lx < (int)a.size()) {
      // TODO
    }
    return;
  }
  int mid = lx + (rx - lx) / 2;
  buildseg(a, 2 * pos + 1, lx, mid);
  buildseg(a, 2 * pos + 2, mid, rx);
  seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
}

void push(int pos, int lx, int rx) {
  if (rx - lx == 1) return;
  if (seg[pos].isValid) {
    for (int dx = 1; dx <= 2; dx++) {
      // TODO
      seg[2 * pos + dx].isValid = true;
    }
    seg[pos].isValid = false;
  }
}

void setseg(int l, int r, int v, int pos, int lx, int rx) {
  push(pos, lx, rx);
  if (lx >= r || rx <= l) return;
  if (lx >= l && rx <= r) {
    // TODO
    seg[pos].isValid = true;
    return;
  }
  int mid = lx + (rx - lx) / 2;
  setseg(l, r, v, 2 * pos + 1, lx, mid);
  setseg(l, r, v, 2 * pos + 2, mid, rx);
  seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
}

item getseg(int l, int r, int pos, int lx, int rx) {
  push(pos, lx, rx);
  if (lx >= r || rx <= l) return item();
  if (lx >= l && rx <= r) return seg[pos];
  int mid = lx + (rx - lx) / 2;
  return getseg(l, r, 2 * pos + 1, lx, mid) +
         getseg(l, r, 2 * pos + 2, mid, rx);
}
