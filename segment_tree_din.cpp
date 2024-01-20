struct item {
  int e = -1, d = -1, val = 0;
};

void _merge(item &a, item &b, item &c) { a.val = b.val + c.val; }

vector<item> seg;
item neutro;

int _create() {
  seg.emplace_back();
  return seg.size() - 1;
}

void initseg() { _create(); }  // TODO: chamar antes de usar

ll getseg(ll l, ll r, int pos, ll lx, ll rx) {
  if (lx >= r || rx <= l) return 0LL;
  if (pos == -1) return 0LL;
  if (lx >= l && rx <= r) {
    return seg[pos].val;
  }
  ll mid = lx + (rx - lx) / 2;
  ll x = getseg(l, r, seg[pos].e, lx, mid);
  ll y = getseg(l, r, seg[pos].d, mid, rx);
  return x + y;
}

void addseg(ll i, int v, int pos, ll lx, ll rx) {
  if (rx - lx == 1) {
    seg[pos].val += v;
    return;
  }
  ll mid = lx + (rx - lx) / 2;
  if (i < mid) {
    if (seg[pos].e == -1) {
      int tmp = _create();
      seg[pos].e = tmp;
    }
    addseg(i, v, seg[pos].e, lx, mid);
  } else {
    if (seg[pos].d == -1) {
      int tmp = _create();
      seg[pos].d = tmp;
    }
    addseg(i, v, seg[pos].d, mid, rx);
  }
  int e = seg[pos].e;
  int d = seg[pos].d;
  _merge(seg[pos], e == -1 ? neutro : seg[e], d == -1 ? neutro : seg[d]);
}
