int tk = 0;
vi tin(MAX), low(MAX);
vector<ii> brid;
set<int> arti;
void dfs(int u, int p) {
  tin[u] = low[u] = tk++;
  int ch = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (tin[v] == -1) {
      dfs(v, u);
      ch++;
      if ((low[v] >= tin[u] && p != u) || (ch >= 2 && p == u)) arti.insert(u);
      if (low[v] > tin[u]) brid.push_back(ii(u, v));
      low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], tin[v]);
    }
  }
}

void articbridges(int n) {
  fill(tin.begin(), tin.begin() + n + 5, -1);
  tk = 0;
  arti.clear();
  brid.clear();
  for (int i = 0; i < n; i++) {
    dfs(i, i);  // TODO?
  }
}
