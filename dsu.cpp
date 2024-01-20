vi p(MAX), rnk(MAX);

void init() {
  iota(all(p), 0);
  fill(all(rnk), 0);
}

int __find(int u) { return p[u] = (p[u] == u ? u : __find(p[u])); }

void join(int u, int v) {
  u = __find(u);
  v = __find(v);
  if (u == v) return;
  if (rnk[u] > rnk[v]) {
    p[v] = u;
  } else {
    p[u] = v;
    if (rnk[u] == rnk[v]) rnk[v]++;
  }
}
