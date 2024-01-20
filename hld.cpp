vector<ii> adj[MAX];
int pos[MAX], sz[MAX], par[MAX], head[MAX], orig[MAX], ids = 0;

void fillhld(int u = 0, int p = -1) {
  int maior = -1, imaior = -1;
  par[u] = p;
  sz[u] = 1;
  for (int j = 0; j < adj[u].size(); j++) {
    int v = adj[u][j].first;
    if (v == p) continue;
    fillhld(v, u);
    if (maior == -1 || (sz[v] > sz[maior])) {
      maior = v;
      imaior = j;
    }
    sz[u] += sz[v];
  }
  if (imaior != -1) {
    swap(adj[u][0], adj[u][imaior]);
  }
}
void buildhld(int u = 0, int cost = oo /* TODO:? */, int repr = -1) {
  pos[u] = ids;
  orig[ids] = cost;
  ids++;
  if (repr == -1) repr = u;
  head[u] = repr;
  for (int j = 0; j < adj[u].size(); j++) {
    if (adj[u][j].first == par[u]) continue;
    if (j > 0) repr = -1;
    buildhld(adj[u][j].first, adj[u][j].second, repr);
  }
}

void build() {}  // TODO: Sparse table / Seg tree ...

int gethld(int u, int v) {
  int ans = oo;  // TODO:
  if (pos[u] > pos[v]) swap(u, v);
  while (head[u] != head[v]) {  // TODO: porque tem que ser o v
    ans = min(ans, getmin(pos[head[v]], pos[v] + 1));  // TODO
    v = par[head[v]];
    if (pos[u] > pos[v]) swap(u, v);
  }
  return ans = min(ans, getmin(pos[u] + 1 /* TODO?*/, pos[v] + 1));  // TODO
}
