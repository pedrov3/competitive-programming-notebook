vi adj[MAX];

vi sz(MAXN), h(MAXN), par(MAXN), pos(MAXN), sop(MAXN), head(MAXN), tail(MAXN);

void remove_parent(int u = 0){
  for (int v: adj[u]) {
    adj[v].erase(find(all(adj[v]), u));
    remove_parent(v);
  }
}

int fill(int u = 0){
  for (int i = 0; i < adj[u].size(); i++) {
    int& v = adj[u][i];
    h[v] = h[u] + 1;
    par[v] = u;
    sz[u] += fill(v);
    if (sz[adj[u][0]] < sz[v]) swap(adj[u][0], v);
  }
  return ++sz[u];
}

void hld(int u = 0){
  static int ids = 0;
  sop[pos[u] = ids++] = u;
  for (int v : adj[u]) {
    head[v] = (v == adj[u][0] ? head[u] : v);
    hld(v);
  }
  tail[u] = adj[u].size() ? tail[adj[u][0]] : u;
}

void build() {}  // TODO: Sparse table / Seg tree ...

int gethld(int u, int v) {
  int ans = oo;  // TODO:
  if (pos[u] > pos[v]) swap(u, v);
  while (head[u] != head[v]) {
    ans = min(ans, getmin(pos[head[v]], pos[v] + 1));  // TODO
    v = par[head[v]];
    if (pos[u] > pos[v]) swap(u, v);
  }
  return ans = min(ans, getmin(pos[u] + 1 /* TODO: edge = 1*/, pos[v] + 1));  // TODO
}
