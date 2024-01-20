void fill(int u = 0, int p = -1) {
  for (auto &v : adj[u]) {
    if (v == p) continue;
    fill(v, u);
    // TODO
  }
}

void reroot(int new_root, int old_root) {  // TODO
}

void solve(int u = 0, int p = -1) {
  // TODO
  for (auto &v : adj[u]) {
    if (v == p) continue;
    reroot(v, u);
    solve(v, u);
    reroot(u, v);
  }
}
