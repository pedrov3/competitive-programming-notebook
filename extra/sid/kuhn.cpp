int ladj[MAX][MAX], d[MAX], vis[MAX], match[MAX];  // TODO: inicializar d
                                                   // TODO: inicializar match
int aug(int u) {                                   // TODO: qual a complexidade?
  if (vis[u]) return 0;
  vis[u] = 1;
  for (int j = 0; j < d[u]; j++) {
    int v = ladj[u][j];
    if (match[v] == -1 || aug(match[v])) {
      match[v] = u;
      return 1;
    }
  }
  return 0;
}

void add_edge(int u, int v) { ladj[u][d[u]++] = v; }

int maxmatching() {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    memset(vis, 0, sizeof(vis));
    ans += aug(i);
  }
  return ans;
}
