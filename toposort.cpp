vi adj[MAX];
stack<int> stk;
int vis[MAX];

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (auto &v : adj[u]) dfs(v);
  stk.push(u);
}

vi toposort(int n) {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) dfs(i);
  vi retval;
  while (!stk.empty()) {
    retval.push_back(stk.top());
    stk.pop();
  }
  return retval;
}
