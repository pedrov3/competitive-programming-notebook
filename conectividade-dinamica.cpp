vi p, rnk;
int qtde;  // TODO

vector<pair<int *, int>> stk;

vector<ii> seg[2097152];
int tamseg;  // TODO

void init(int n) {
  p.resize(n);
  rnk.resize(n);
  iota(p.begin(), p.end(), 0);
}

int __find(int u) { return p[u] == u ? u : __find(p[u]); }

void join(int u, int v) {
  u = __find(u);
  v = __find(v);
  if (u == v) return;
  stk.emplace_back(&qtde, qtde);
  qtde--;
  if (rnk[u] > rnk[v]) {
    stk.emplace_back(&p[v], p[v]);
    p[v] = u;
  } else {
    stk.emplace_back(&p[u], p[u]);
    stk.emplace_back(&rnk[v], rnk[v]);
    p[u] = v;
    if (rnk[u] == rnk[v]) rnk[v]++;
  }
}

void undo(int prev_size) {
  while (stk.size() > prev_size) {
    auto [a, b] = stk.back();
    *a = b;
    stk.pop_back();
  }
}

void addseg(iiii &val, int pos, int lx, int rx) {
  auto &[l, r, u, v] = val;  // lifetime of (u, v)
  if (lx >= r || rx <= l) return;
  if (lx >= l && rx <= r) {
    seg[pos].emplace_back(u, v);
    return;
  }
  int mid = lx + (rx - lx) / 2;
  addseg(val, 2 * pos + 1, lx, mid);
  addseg(val, 2 * pos + 2, mid, rx);
}

void solve(int pos, int lx, int rx) {
  int antes = stk.size();
  for (auto &[u, v] : seg[pos]) join(u, v);
  if (rx - lx == 1) {
    cout << qtde << "\n";
    undo(antes);
    return;
  }
  int mid = lx + (rx - lx) / 2;
  solve(2 * pos + 1, lx, mid);
  solve(2 * pos + 2, mid, rx);
  undo(antes);
}
