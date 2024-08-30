// TODO: melhorar esse código BGSHOOT

struct item {
  int e = -1, d = -1;
  bool isValid = false;
  // TODO:

  void merge() {
    int e = seg[pos].e;
    int d = seg[pos].d;
    if (e != -1 && d != -1) {
      // TODO:
    } else if (seg[pos].e != -1 || seg[pos].d != -1) {
      // TODO:
    }
  }
};

vector<item> seg;
item neutro;

int _create() {
  seg.emplace_back();
  return seg.size() - 1;
}

void initseg() { _create(); }  // TODO: chamar antes de usar

void push(int pos, int lx, int rx) {
  if (rx - lx == 1) return;

  if (seg[pos].isValid) {
    if (seg[pos].e == -1) {
      int tmp = _create();
      seg[pos].e = tmp;
    }
    if (seg[pos].d == -1) {
      int tmp = _create();
      seg[pos].d = tmp;
    }
    // TODO:
    seg[seg[pos].e].isValid = true;

    // TODO:
    seg[seg[pos].d].isValid = true;

    seg[pos].isValid = false;
  }
}

void assign(ll l, ll r, int v, int pos, ll lx, ll rx) {
  if (lx >= r || rx <= l) return;
  if (pos == -1) return;

  push(pos, lx, rx);

  if (lx >= l && rx <= r) {
    seg[pos].dono = v;
    seg[pos].isValid = true;
    return;
  }
  ll mid = lx + (rx - lx) / 2;
  if (seg[pos].e == -1 && !(lx >= r || mid <= l)) {
    int tmp = _create();
    seg[pos].e = tmp;
  }
  if (seg[pos].d == -1 && !(mid >= r || rx <= l)) {
    int tmp = _create();
    seg[pos].d = tmp;
  }
  assign(l, r, v, seg[pos].e, lx, mid);
  assign(l, r, v, seg[pos].d, mid, rx);
  seg[pos].merge();
}
