vi adj[MAX];
int sz[MAX];
bool mark[MAX];

int dfs_sz(int u, int p = -1) {
  sz[u] = 1;
  for (auto &v : adj[u])
    if (v != p && !mark[v]) sz[u] += dfs_sz(v, u);
  return sz[u];
}

int dfs_cent(int u, int n, int p = -1) {
  for (auto &v : adj[u])
    if (v != p && !mark[v] && sz[v] >= (n >> 1)) return dfs_cent(v, n, u);
  return u;
}

void centroid(int u = 0) {
  int c = dfs_cent(u, dfs_sz(u));
  mark[c] = 1;

  // TODO

  for (auto &v : adj[c])
    if (!mark[v]) centroid(v);
}
