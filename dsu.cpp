struct dsu {
  vi p, rnk;
  dsu(int n) : p(n), rnk(n) {
    iota(all(p), 0);
  }

  int find(int u) {
    if (p[u] == u) return u;
    return p[u] = find(p[u]);
  }

  void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (rnk[u] > rnk[v]) {
      p[v] = u;
    } else {
      p[u] = v;
      if (rnk[u] == rnk[v]) rnk[v]++;
    }
  }
};
