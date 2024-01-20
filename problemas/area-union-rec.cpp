// TODO: simplificar codigo
#define MAX 30005

struct SegLazy {
  struct item {
    bool isValid = false;
    int lazy = 0;
    int mi = 0, qtde = 0;

    item operator+(item oth) {
      item c = item();
      if (this->mi == oth.mi) {
        c.mi = this->mi;
        c.qtde = this->qtde + oth.qtde;
      } else if (this->mi < oth.mi) {
        c.mi = this->mi;
        c.qtde = this->qtde;
      } else {
        c.mi = oth.mi;
        c.qtde = oth.qtde;
      }
      return c;
    }
  };

  void merge(item &c, item a, item oth) {
    c.isValid = false;
    c.lazy = 0;
    if (a.mi == oth.mi) {
      c.mi = a.mi;
      c.qtde = a.qtde + oth.qtde;
    } else if (a.mi < oth.mi) {
      c.mi = a.mi;
      c.qtde = a.qtde;
    } else {
      c.mi = oth.mi;
      c.qtde = oth.qtde;
    }
  }

  item seg[4 * MAX];
  int tamseg;

  void buildseg(int pos, int lx, int rx) {
    if (rx - lx == 1) {
      seg[pos].isValid = false;
      seg[pos].lazy = 0;
      seg[pos].mi = 0;
      seg[pos].qtde = 1;
      return;
    }
    int mid = lx + (rx - lx) / 2;
    buildseg(2 * pos + 1, lx, mid);
    buildseg(2 * pos + 2, mid, rx);
    merge(seg[pos], seg[2 * pos + 1], seg[2 * pos + 2]);
  }

  void push(int pos, int lx, int rx) {
    if (rx - lx == 1) return;
    if (seg[pos].isValid) {
      int lazy = seg[pos].lazy;
      for (int dx = 1; dx <= 2; dx++) {
        seg[2 * pos + dx].mi += lazy;
        seg[2 * pos + dx].lazy += lazy;
        seg[2 * pos + dx].isValid = true;
      }
      seg[pos].lazy = 0;
      seg[pos].isValid = false;
    }
  }

  void setseg(int l, int r, int v, int pos, int lx, int rx) {
    push(pos, lx, rx);
    if (lx >= r || rx <= l) return;
    if (lx >= l && rx <= r) {
      seg[pos].mi += v;
      seg[pos].lazy = v;
      seg[pos].isValid = true;
      return;
    }
    int mid = lx + (rx - lx) / 2;
    setseg(l, r, v, 2 * pos + 1, lx, mid);
    setseg(l, r, v, 2 * pos + 2, mid, rx);
    merge(seg[pos], seg[2 * pos + 1], seg[2 * pos + 2]);
  }

  void set(int l, int r, int v) { setseg(l, r, v, 0, 0, tamseg); }

  item getseg(int l, int r, int pos, int lx, int rx) {
    push(pos, lx, rx);
    if (lx >= r || rx <= l) return item();
    if (lx >= l && rx <= r) return seg[pos];
    int mid = lx + (rx - lx) / 2;
    return getseg(l, r, 2 * pos + 1, lx, mid) +
           getseg(l, r, 2 * pos + 2, mid, rx);
  }
  int get(int l, int r) {
    item bah = getseg(l, r, 0, 0, tamseg);
    int qtde = bah.qtde;
    int mi = bah.mi;
    return (r - l) - (mi == 0 ? qtde : 0);
  }
  void initseg(int n) {
    tamseg = 1;
    while (tamseg < n) tamseg *= 2;
    buildseg(0, 0, tamseg);
  }
};

SegLazy seg;

void add(int l, int r, int v) { seg.set(l, r, v); }

int get(int l, int r) { return seg.get(l, r); }

ll solve(vector<iiii> &rec) {
  int n = rec.size();
  vector<iii> ev;
  int i = 0;
  int maxn = 0;
  for (auto &[lx, ly, rx, ry] : rec) {
    ev.emplace_back(lx, 0, i);
    ev.emplace_back(rx, 1, i);
    maxn = max(maxn, ry + 1);
    ++i;
  }
  int offset = 10;
  seg.initseg(maxn + 20);
  sort(all(ev));
  int prev = -1e9 - 7;
  ll ans = 0;
  for (auto &[_, op, id] : ev) {
    auto [lx, ly, rx, ry] = rec[id];
    if (op == 0) {
      if (prev != (-1e9 - 7)) {
        int qtde = get(-5 + offset, maxn + offset);
        ans += ((ll)(lx - prev)) * qtde;
      }
      add(ly + offset, ry + offset, 1);
      prev = lx;
    } else {
      int qtde = get(-5 + offset, maxn + offset);
      ans += ((ll)(rx - prev)) * qtde;
      add(ly + offset, ry + offset, -1);
      prev = rx;
    }
  }
  return ans;
}
