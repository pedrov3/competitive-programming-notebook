// a[i] = max(a[i], x); l <= i <= r
// a[l] + a[l + 1] + ... + a[r]

struct item {
  bool isValid = false;
  int max2 = -oo, max1 = -oo;
  int cnt = 0;
  ll sum = 0;

  item operator+(item oth) {
    item c = item();
    if (this->max1 > oth.max1) {
      c.max1 = this->max1;
      c.cnt = this->cnt;
      c.max2 = max(this->max2, oth.max1);
    } else if (this->max1 == oth.max1) {
      c.max1 = this->max1;
      c.cnt = this->cnt + oth.cnt;
      c.max2 = max(this->max2, oth.max2);
    } else if (this->max1 < oth.max1) {
      c.max1 = oth.max1;
      c.cnt = oth.cnt;
      c.max2 = max(this->max1, oth.max2);
    }
    c.sum = this->sum + oth.sum;
    return c;
  }
};

item seg[4 * MAX];
int tamseg;

void initseg(int n) {
  tamseg = 1;
  while (tamseg < n) tamseg *= 2;
}

void buildseg(vector<int> &a, int pos, int lx, int rx) {
  if (rx - lx == 1) {
    if (lx < (int)a.size()) {
      seg[pos].max1 = seg[pos].sum = a[lx];
      seg[pos].cnt = 1;
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
    int val = seg[pos].max1;
    for (int dx = 1; dx <= 2; dx++) {
      if (seg[2 * pos + dx].max1 > val) {
        seg[2 * pos + dx].sum -=
            (1LL * (seg[2 * pos + dx].max1 - val)) * seg[2 * pos + dx].cnt;
        seg[2 * pos + dx].max1 = val;
        seg[2 * pos + dx].isValid = true;
      }
    }
    seg[pos].isValid = false;
  }
}

void setseg(int l, int r, int v, int pos, int lx, int rx) {
  push(pos, lx, rx);
  if (lx >= r || rx <= l || seg[pos].max1 <= v) return;
  if (lx >= l && rx <= r && seg[pos].max2 < v) {
    assert(seg[pos].max1 >= v);
    seg[pos].sum -= (1LL * (seg[pos].max1 - v)) * (seg[pos].cnt);
    seg[pos].max1 = v;
    // seg[pos].max2 = -oo;
    seg[pos].isValid = true;
    return;
  }
  int mid = lx + (rx - lx) / 2;
  setseg(l, r, v, 2 * pos + 1, lx, mid);
  setseg(l, r, v, 2 * pos + 2, mid, rx);
  seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
}

ll getseg(int l, int r, int pos, int lx, int rx) {
  push(pos, lx, rx);
  if (lx >= r || rx <= l) return 0;
  if (lx >= l && rx <= r) return seg[pos].sum;
  int mid = lx + (rx - lx) / 2;
  return getseg(l, r, 2 * pos + 1, lx, mid) +
         getseg(l, r, 2 * pos + 2, mid, rx);
}
