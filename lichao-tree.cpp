int tamseg = 1e9 + 7;
struct item {
  int e = -1, d = -1, a = 0, b = -oo;
};

struct Lichao {
  vector<item> seg;
  item neutro;

  int _create() {
    seg.emplace_back();
    return seg.size() - 1;
  }

  Lichao() { _create(); }

  int get(int x, int pos, ll lx, ll rx) {
    if (pos == -1) return -oo;
    if (rx - lx == 1) return seg[pos].a * x + seg[pos].b;
    int mid = lx + (rx - lx) / 2;
    if (x < mid)
      return max(get(x, seg[pos].e, lx, mid), seg[pos].a * x + seg[pos].b);
    else
      return max(get(x, seg[pos].d, mid, rx), seg[pos].a * x + seg[pos].b);
  }

  int get(int x) { return get(x, 0, -tamseg, tamseg); }

  void add(int a, int b, int pos, ll lx, ll rx) {
    int mid = lx + (rx - lx) / 2;
    if (seg[pos].a * mid + seg[pos].b < a * mid + b) {
      swap(seg[pos].a, a);
      swap(seg[pos].b, b);
    }
    if (rx - lx == 1) {
      return;
    }
    if (seg[pos].a * lx + seg[pos].b < a * lx + b) {
      if (seg[pos].e == -1) {
        int tmp = _create();
        seg[pos].e = tmp;
      }
      add(a, b, seg[pos].e, lx, mid);
    } else {
      if (seg[pos].d == -1) {
        int tmp = _create();
        seg[pos].d = tmp;
      }
      add(a, b, seg[pos].d, mid, rx);
    }
  }

  void add(int a, int b) { add(a, b, 0, -tamseg, tamseg); }
};
