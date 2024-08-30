struct item {
  int e = 0, d = 0, val = 0;
};

void _merge(item &a, item &b, item &c) { a.val = b.val + c.val; }

vector<item> seg;
item neutro;
vi raiz;

int _create() {
  seg.emplace_back();
  return seg.size() - 1;
}

void initseg(int n) {  // TODO: chamar antes de usar
  raiz.resize(n);
  _create();  // neutro
  int tmp = _create();
  raiz[0] = tmp;  // raiz
}

void buildseg(vi &vet, int pos, ll lx, ll rx) {
  if (rx - lx == 1) {
    if (lx < vet.size()) {
      seg[pos].val = vet[lx];
    }
    return;
  }
  int e = _create();
  int d = _create();
  seg[pos].e = e;
  seg[pos].d = d;

  ll mid = lx + (rx - lx) / 2;
  buildseg(vet, seg[pos].e, lx, mid);
  buildseg(vet, seg[pos].d, mid, rx);
  _merge(seg[pos], seg[e], seg[d]);
}

ll getseg(ll l, ll r, int pos, ll lx, ll rx) {
  if (lx >= r || rx <= l) return 0LL;
  if (lx >= l && rx <= r) {
    return seg[pos].val;
  }
  ll mid = lx + (rx - lx) / 2;
  ll x = getseg(l, r, seg[pos].e, lx, mid);
  ll y = getseg(l, r, seg[pos].d, mid, rx);
  return x + y;
}

int addseg(ll i, int v, int pos, ll lx, ll rx) {
  int new_pos = _create();
  seg[new_pos] = seg[pos];

  if (rx - lx == 1) {
    seg[new_pos].val += v;
    return new_pos;
  }

  ll mid = lx + (rx - lx) / 2;
  if (i < mid) {
    int tmp = addseg(i, v, seg[pos].e, lx, mid);
    seg[new_pos].e = tmp;
  } else {
    int tmp = addseg(i, v, seg[pos].d, mid, rx);
    seg[new_pos].d = tmp;
  }
  int e = seg[new_pos].e;
  int d = seg[new_pos].d;
  _merge(seg[new_pos], seg[e], seg[d]);
  return new_pos;
}

void imprimir(int pos, int ident = 0) {
  if (pos == 0) return;
  for (int i = 0; i < ident; i++) {
    cout << " ";
  }
  cout << seg[pos].val;

  bool is_leaf = (!seg[pos].e && !seg[pos].d);
  if (is_leaf) cout << " <-- ";
  cout << " @" << pos << "\n";
  imprimir(seg[pos].e, ident + 1);
  imprimir(seg[pos].d, ident + 1);
}
