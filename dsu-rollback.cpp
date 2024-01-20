vi p(MAX), rnk(MAX);

void init() {
  iota(all(p), 0);
  fill(all(rnk), 0);
}

int __find(int u) { return p[u] == u ? u : __find(p[u]); }

stack<pair<int*, int>> stk;

void join(int u, int v) {
  u = __find(u);
  v = __find(v);
  if (u == v) return;
  if (rnk[u] > rnk[v]) {
    stk.emplace(&p[v], p[v]);
    p[v] = u;
  } else {
    stk.emplace(&p[u], p[u]);
    stk.emplace(&rnk[v], rnk[v]);
    p[u] = v;
    if (rnk[u] == rnk[v]) rnk[v]++;
  }
}

void undo(int prev_size) {
  while (stk.size() > prev_size) {
    auto [a, b] = stk.top();
    *a = b;
    stk.pop();
  }
}
