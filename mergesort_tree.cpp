struct merge_sort_tree {
  struct item {
    vi vet;
    item operator+(item oth) {
      item c;
      c.vet = vi(this->vet.size() + oth.vet.size());
      for (int k = 0, i = 0, j = 0; k < c.vet.size(); k++) {
        if (j == oth.vet.size() ||
            (i < this->vet.size() && this->vet[i] < oth.vet[j])) {
          c.vet[k] = this->vet[i++];
        } else {
          c.vet[k] = oth.vet[j++];
        }
      }
      return c;
    }
  };

  int n;
  vector<item> seg;

  merge_sort_tree(vi &vet) : seg(4 * vet.size()), n(vet.size()) {
    build(vet, 0, 0, n);
  }

  void build(vi &vet, int pos, int lx, int rx) {
    if (rx - lx == 1) {
      seg[pos].vet.emplace_back(vet[lx]);
      return;
    }
    int mid = lx + (rx - lx) / 2;
    build(vet, 2 * pos + 1, lx, mid);
    build(vet, 2 * pos + 2, mid, rx);
    seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
  }

  int get(int l, int r, int x, int pos, int lx, int rx) {
    if (lx >= r || rx <= l) return 0;
    if (lx >= l && rx <= r) {
      if (seg[pos].vet[0] > x) return 0;
      int a = 0;                    // good
      int b = seg[pos].vet.size();  // bad
      while (a + 1 < b) {
        int mid = a + (b - a) / 2;
        if (seg[pos].vet[mid] <= x) a = mid;
        else b = mid;
      }
      return a + 1;
    }
    int mid = lx + (rx - lx) / 2;
    return get(l, r, x, 2 * pos + 1, lx, mid) +
           get(l, r, x, 2 * pos + 2, mid, rx);
  }
  
  // #qtde <= x no intervalo [l, r)?
  int get(int l, int r, int x) { return get(l, r, x, 0, 0, n); }
};
