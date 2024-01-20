void dijkstra(int s, int t) {
  priority_queue<ii, vector<ii>, greater<ii>> q;
  fill(dist, dist + MAX, oo);

  dist[s] = 0;
  q.emplace(dist[s], s);
  while (!q.empty()) {
    ll cost, u;
    tie(cost, u) = q.top();
    q.pop();
    if (dist[u] < cost) continue;
    if (u == t) break;
    for (auto& [v, c] : adj[u]) {
      if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        q.emplace(dist[v], v);
      }
    }
  }
}
