vector<vi> adj, adj_rev;
set<int> adj_scc[MAX];
int vis[MAX], raizes[MAX];
vi order, nodos_raiz;
int components[MAX], sz_comp = 0;

void dfs1(int u, vector<vi> &adj) {
  if (vis[u]) return;
  vis[u] = 1;
  for (auto &v : adj[u]) {
    dfs1(v, adj);
  }
  order.push_back(u);
}

void dfs2(int u, vector<vi> &adj_rev) {
  if (vis[u]) return;
  vis[u] = 1;
  components[sz_comp++] = u;
  for (auto &v : adj_rev[u]) {
    dfs2(v, adj_rev);
  }
}

void scc(vector<vi> &adj) {
  int n = adj.size();
  adj_rev.resize(n);
  for (auto &u : adj_rev) u.clear();
  for (int u = 0; u < n; u++) {
    for (auto &v : adj[u]) {
      adj_rev[v].push_back(u);
    }
  }
  memset(vis, 0, sizeof(vis));
  order.clear();
  for (int u = 0; u < n; u++) {
    dfs1(u, adj);
  }

  memset(vis, 0, sizeof(vis));
  reverse(all(order));
  nodos_raiz.clear();
  for (auto &u : order) {
    if (!vis[u]) {
      sz_comp = 0;
      dfs2(u, adj_rev);
      int raiz = components[0];
      for (int i = 0; i < sz_comp; i++) {
        int v = components[i];
        raizes[v] = raiz;
      }
      nodos_raiz.push_back(raiz);
    }
  }
  for (auto &u : adj_scc) {  // TODO
    u.clear();
  }
  for (int u = 0; u < n; u++) {
    for (auto &v : adj[u]) {
      int _u = raizes[u], _v = raizes[v];
      if (_u != _v) {
        adj_scc[_u].insert(_v);
      }
    }
  }
}
