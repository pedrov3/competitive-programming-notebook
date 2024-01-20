bool big[MAX];
int sz[MAX];

void dfs_sz(int u, int p = -1) {
  sz[u] = 1;
  for (auto &v : adj[u]) {
    if (v == p) continue;
    dfs_sz(v, u);
    sz[u] += sz[v];
  }
}

void add(int x) {  // TODO:
}

void rem(int x) {  // TODO:
}

void add(int u, int p, int x) {
  if (x == 1)
    add(u);
  else
    rem(u);

  for (auto &v : adj[u]) {
    if (v == p || big[v]) continue;
    add(v, u, x);
  }
}

void small(int u, int p = -1, bool keep = 0) {
  int bigchild = -1, mx = -1;
  for (auto &v : adj[u])
    if (v != p && mx < sz[v]) mx = sz[v], bigchild = v;
  for (auto &v : adj[u]) {
    if (v == p || v == bigchild) continue;
    small(v, u, 0);
  }
  if (bigchild != -1) small(bigchild, u, 1), big[bigchild] = 1;
  add(u, p, 1);

  // solve

  if (bigchild != -1) big[bigchild] = 0;
  if (keep == 0) add(u, p, -1);
}
