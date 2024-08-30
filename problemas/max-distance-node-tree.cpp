vector<ii> adj[MAX];
int fst[MAX], sd[MAX];
int c[MAX];   // maior caminho considerando a subarvore enraizada em u
int cp[MAX];  // maior caminho indo para o pai
int right_border[MAX]; // auxiliar para recuperar a resposta
int up[MAX]; // auxiliar para recuperar a resposta

int ans[MAX], ansu[MAX]; // ans[v]  := distancia mais longe de v, 
                         // ansu[v] := nó que está mais distante

int dfs(int u = 0, int p = -1) {
  fst[u] = sd[u] = -1;
  right_border[u] = u;
  int retval = 0;
  for (auto &[v, _] : adj[u]) {
    if (v == p) continue;
    int r = dfs(v, u);
    retval = max(retval, 1 + r);
    if (fst[u] == -1 || (c[fst[u]] < r)) {
      right_border[u] = right_border[v];
      sd[u] = fst[u];
      fst[u] = v;
    } else if (sd[u] == -1 || c[sd[u]] < r) {
      sd[u] = v;
    }
  }
  c[u] = retval;
  return retval;
}

void dfs2(int u, int p = -1) {
  ans[u] = c[u];
  cp[u] = 0;
  int goup = -1;
  up[u] = u;
  if (p != -1) {
    if (fst[p] != u) {
      goup = right_border[fst[p]];
      cp[u] = 2 + c[fst[p]];
    } else if (sd[p] != -1) {
      goup = right_border[sd[p]];
      cp[u] = 2 + c[sd[p]];
    }
    if (cp[u] < 1 + cp[p]) {
      goup = up[p];
    }
    up[u] = goup;
    cp[u] = max(cp[u], 1 + cp[p]);
  }
  int go = right_border[u];
  if (ans[u] < cp[u]) {
    go = goup;
  }
  ansu[u] = go;
  ans[u] = max(ans[u], cp[u]);
  for (auto &[v, _] : adj[u]) {
    if (v == p) continue;
    dfs2(v, u);
  }
}
