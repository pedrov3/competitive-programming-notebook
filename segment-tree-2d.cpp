struct item {
  int e = -1, d = -1, raiz = -1;
  int val = 0;
};

int tamseg = 1 << 19;

// TODO: copiar aqui o codigo da segment_tree_din.cpp

ll getseg(ll y1, ll x1, ll y2, ll x2, int pos, ll lx, ll rx) {
  if (lx >= x2 || rx <= x1) return 0LL;
  if (pos == -1) return 0LL;
  if (lx >= x1 && rx <= x2) {
    return getseg(y1, y2, seg[pos].raiz, 0, tamseg);
  }
  ll mid = lx + (rx - lx) / 2;
  ll x = getseg(y1, x1, y2, x2, seg[pos].e, lx, mid);
  ll y = getseg(y1, x1, y2, x2, seg[pos].d, mid, rx);
  return x + y;
}

void addseg(ll lin, ll col, int v, int pos, ll lx, ll rx) {
  if (rx - lx == 1) {
    gexist(seg[pos].raiz);
    addseg(lin, v, seg[pos].raiz, 0, tamseg);
    return;
  }
  ll mid = lx + (rx - lx) / 2;
  if (col < mid) {
    gexist(seg[pos].e);
    addseg(lin, col, v, seg[pos].e, lx, mid);
  } else {
    gexist(seg[pos].d);
    addseg(lin, col, v, seg[pos].d, mid, rx);
  }
  gexist(seg[pos].raiz);
  addseg(lin, v, seg[pos].raiz, 0, tamseg);
}
