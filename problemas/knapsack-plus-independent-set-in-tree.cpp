// problema da mochila combinado com conjunto independente em uma árvore
const int MAX = 303;
int n, x;
int w[MAX], v[MAX], sz[MAX];
vi adj[MAX];

void hld(int u, int p) {
  adj[u].erase(remove(all(adj[u]), p), adj[u].end());
  sz[u] = 1;
  for (auto &v : adj[u]) {
    hld(v, u);
    sz[u] += sz[v];
  }
  sort(all(adj[u]), [&](int u, int v) { return sz[u] > sz[v]; });
}

pair<vi, vi> dfs(int u, const vi &dp) {
  auto d = dp, e = dp;
  if (!adj[u].empty()) {
    tie(d, e) = dfs(adj[u][0], dp);
    for (int i = 1; i < adj[u].size(); i++) {
      d = dfs(adj[u][i], d).first;
      e = dfs(adj[u][i], e).second;
    }
  }
  for (int i = x; i >= 0; i--) {
    e[i] = d[i];
    if (i >= w[u]) d[i] = max(d[i], e[i - w[u]] + v[u]);
  }
  return {d, e};
}

  
signed main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++) 
        cin >> w[i] >> v[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    hld(0, 0);
    auto [d, ignore] = dfs(0, vi(x + 1));
    cout << d[x] << "\n";
}

