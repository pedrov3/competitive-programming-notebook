int p[MAX], h[MAX], tab[LOGN][MAX];
int n;  // TODO
ll dist[MAX];

void dfs(int u, int _p) {
  p[u] = _p;
  for (auto &[v, c] : adj[u]) {
    if (v == _p) continue;
    dist[v] = dist[u] + c;
    h[v] = h[u] + 1;
    dfs(v, u);
  }
}

void build() {  // TODO
  dfs(0, 0);    // TODO
  for (int j = 0; j < n; j++) tab[0][j] = p[j];
  for (int i = 1; i < LOGN; i++)
    for (int j = 0; j < n; j++) tab[i][j] = tab[i - 1][tab[i - 1][j]];
}

int goup(int u, int k) {
  for (int i = 0; i < LOGN; i++)
    if (k & (1LL << i)) u = tab[i][u];
  return u;
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  u = goup(u, h[u] - h[v]);
  if (u == v) return u;
  for (int i = LOGN - 1; i >= 0; i--)
    if (tab[i][u] != tab[i][v]) {
      u = tab[i][u];
      v = tab[i][v];
    }
  return tab[0][u];
}

ll solve(int u, int v) {  // Distancia entre dois vertices com custo
  if (u > v) swap(u, v);
  if (u == 0) return dist[v]; // TODO
  return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}
