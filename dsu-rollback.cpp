struct dsu_rollback {
  vi p, rnk, sz;
  dsu_rollback(int n) : p(n), rnk(n), sz(n, 1) { iota(all(p), 0); }

  int find(int u) {
    if (p[u] == u) return u;
    return find(p[u]);
  }

  stack<pair<int*, int>> stk;
  stack<int> qt;

  void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v){
        qt.emplace(0);
        return;
    }
    if (rnk[u] > rnk[v]) {
      qt.emplace(2);
      stk.emplace(&p[v], p[v]);
      stk.emplace(&sz[u], sz[u]);
      p[v] = u;
      sz[u] += sz[v];
    } else {
      qt.emplace(3);
      stk.emplace(&p[u], p[u]);
      stk.emplace(&rnk[v], rnk[v]);
      stk.emplace(&sz[v], sz[v]);
      p[u] = v;
      sz[v] += sz[u];
      if (rnk[u] == rnk[v]) rnk[v]++;
    }
  }

  int checkpoint() { return stk.size(); }

  void undo(int prev_size) {
    while (stk.size() > prev_size) {
      auto [a, b] = stk.top();
      *a = b;
      stk.pop();
    }
  }
  void undo(){ // TODO: 
    int q = qt.top();
    qt.pop();
    undo(stk.size() - q);
  }
};
