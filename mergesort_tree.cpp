struct item {
  vi vet;
  item operator+(item oth) {
    item c;
    vi tmp(this->vet.size() + oth.vet.size());
    int i, j;
    i = j = 0;
    for (int k = 0; k < tmp.size(); k++) {
      if (j == oth.vet.size() ||
          (i < this->vet.size() && this->vet[i] < oth.vet[j])) {
        tmp[k] = this->vet[i++];
      } else {
        tmp[k] = oth.vet[j++];
      }
    }
    c.vet = tmp;
    return c;
  }
};

item seg[4 * MAX];
int tamseg;

void initseg(int n) {
  tamseg = 1;
  while (tamseg < n) tamseg *= 2;
}

void buildseg(vector<int> &vet, int pos, int lx, int rx) {
  if (rx - lx == 1) {
    if (lx < vet.size()) seg[pos].vet.emplace_back(vet[lx]);
    return;
  }
  int mid = lx + (rx - lx) / 2;
  buildseg(vet, 2 * pos + 1, lx, mid);
  buildseg(vet, 2 * pos + 2, mid, rx);

  seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
}

// responde quantos são os valores são no <= x no intervalo [l, r)
int getseg(int l, int r, int x, int pos, int lx, int rx) {
  if (lx >= r || rx <= l) return 0;

  if (lx >= l && rx <= r) {
    if (seg[pos].vet[0] > x) return 0;

    int a = 0;                        // good
    int b = seg[pos].vet.size() + 1;  // bad
    seg[pos].vet.emplace_back(oo);
    while (a + 1 < b) {
      int mid = a + (b - a) / 2;
      if (seg[pos].vet[mid] <= x) {
        a = mid;
      } else {
        b = mid;
      }
    }
    seg[pos].vet.pop_back();
    return a + 1;
  }
  int mid = lx + (rx - lx) / 2;
  int e = getseg(l, r, x, 2 * pos + 1, lx, mid);
  int d = getseg(l, r, x, 2 * pos + 2, mid, rx);
  return e + d;
}
