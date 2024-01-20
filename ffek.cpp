// TODO: inicializar d e adj
int ladj[MAX][MAX], d[MAX], p[MAX];
ll adj[MAX][MAX], dist[MAX];
queue<int> q;

void add_edge(int u, int v, ll flow) {
  ladj[u][d[u]++] = v;
  adj[u][v] = flow;

  ladj[v][d[v]++] = u;
  adj[v][u] = 0;
}

ll bfs_ffek(int s, int t) {
  fill(dist, dist + MAX, oo);
  q.push(s);
  dist[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = 0; j < d[u]; j++) {
      int v = ladj[u][j];
      if (dist[v] > dist[u] + 1 && adj[u][v] > 0) {
        dist[v] = dist[u] + 1;
        p[v] = u;
        q.push(v);
      }
    }
  }
  if (dist[t] == oo) return 0;
  ll bneck = oo;
  for (int u = t; u != s; u = p[u]) bneck = min(bneck, adj[p[u]][u]);
  return bneck;
}
ll ffek(int s, int t) {
  ll max_flow = 0;
  ll bneck = 0;
  while ((bneck = bfs_ffek(s, t))) {
    for (int u = t; u != s; u = p[u]) {
      adj[p[u]][u] -= bneck;
      adj[u][p[u]] += bneck;
    }
    max_flow += bneck;
  }
  return max_flow;
}
