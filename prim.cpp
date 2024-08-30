// TODO
ll dist[MAX];
bool vis[MAX];

ll prim(int s = 0) {
  priority_queue<ii, vector<ii>, greater<ii>> p;
  for (auto &x : dist) x = oo;
  for (auto &x : vis) x = false;

  ll retval = 0;
  p.emplace(dist[s] = 0, s);
  while (!p.empty()) {
    int u, val;
    tie(val, u) = p.top();
    p.pop();
    if (vis[u]) continue;
    vis[u] = true;
    retval += dist[u];
    for (auto &[v, cost] : adj[u]) {
      if (!vis[v] && dist[v] > cost) {
        p.emplace(dist[v] = cost, v);
      }
    }
  }
  return retval;
}
