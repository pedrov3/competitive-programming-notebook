vi adj[MAX];

int low[MAX], tin[MAX], stkd[MAX], tk = 1;
stack<int, vi> stk;

set<int> adj_scc[MAX];  // Grafo comprimido
int raizes[MAX];

void dfs_tarjan(int u) {
  if (tin[u]) return;
  tin[u] = low[u] = tk++;
  stk.push(u);
  stkd[u] = 1;
  for (auto &v : adj[u]) {
    dfs_tarjan(v);
    // forward edge?
    if (stkd[v]) low[u] = min(low[u], low[v]);
  }
  if (tin[u] == low[u]) {
    int v;
    do {
      v = stk.top();
      stk.pop();
      stkd[v] = 0;
      raizes[v] = u;
    } while (v != u);
  }
}
void tarjan(int n) {
  tk = 1;
  memset(tin, 0, sizeof(tin));
  for (int u = 0; u < n; u++) dfs_tarjan(u)
}

void scc(int n) {
  for (int u = 0; u < n; u++)
    for (auto &v : adj[u]) {
      int _u = raizes[u];
      int _v = raizes[v];
      if (_u != _v) adj_scc[_u].insert(_v);
    }
}
