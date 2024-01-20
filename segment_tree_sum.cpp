struct item {
  item operator+(item oth) {
    item c;
    // TODO
    return c;
  }
};
item seg[4 * MAX];

void buildseg(vi &vet, int pos, int lx, int rx) {
  if (rx - lx == 1) {
    if (lx < vet.size()) {
      // TODO:
    }
    return;
  }
  int mid = lx + (rx - lx) / 2;
  buildseg(vet, 2 * pos + 1, lx, mid);
  buildseg(vet, 2 * pos + 2, mid, rx);
  seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
}

void setseg(int i, int v, int pos, int lx, int rx) {
  if (rx - lx == 1) {
    // TODO:
    return;
  }
  int mid = lx + (rx - lx) / 2;
  if (i < mid)
    setseg(i, v, 2 * pos + 1, lx, mid);
  else
    setseg(i, v, 2 * pos + 2, mid, rx);
  seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
}

item getseg(int l, int r, int pos, int lx, int rx) {
  if (lx >= r || rx <= l) return item();
  if (lx >= l && rx <= r) return seg[pos];
  int mid = lx + (rx - lx) / 2;
  return getseg(l, r, 2 * pos + 1, lx, mid) +
         getseg(l, r, 2 * pos + 2, mid, rx);
}
