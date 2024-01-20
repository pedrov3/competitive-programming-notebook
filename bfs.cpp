int dist[MAX][MAX];
int vis[MAX][MAX];
int n, m;
int di[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dj[] = {-1, 1, -1, 0, 1, -1, 0, 1};

void bfs(int si, int sj) {
  for (auto &x : dist)
    for (auto &y : x) y = oo;
  for (auto &x : vis)
    for (auto &y : x) y = 0;
  dist[si][sj] = 0;
  queue<ii> q;
  q.emplace(si, sj);
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (vis[i][j]) continue;
    vis[i][j] = true;
    for (int k = 0; k < 8; k++) {
      int i2 = i + di[k];
      int j2 = j + dj[k];
      if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < m &&
          dist[i2][j2] > dist[i][j] + 1) {
        dist[i2][j2] = dist[i][j] + 1;
        q.emplace(i2, j2);
      }
    }
  }
}
// TODO
