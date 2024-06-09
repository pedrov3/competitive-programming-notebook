const int MAX = 212345;
int tamseg = 0; // TODO
vi queries(MAX, -1);
vector<ii> seg[4 * MAX];

dsu_rollback dsu(MAX); // TODO

void add(iiii &val, int pos, int lx, int rx) {
  auto &[l, r, u, v] = val;
  if (lx >= r || rx <= l) return;
  if (lx >= l && rx <= r) {
    seg[pos].emplace_back(u, v);
    return;
  }
  int mid = lx + (rx - lx) / 2;
  add(val, 2 * pos + 1, lx, mid);
  add(val, 2 * pos + 2, mid, rx);
}

void solve(int pos, int lx, int rx) {
  int antes = dsu.checkpoint();
  for (auto &[u, v] : seg[pos]) dsu.join(u, v);
  if (rx - lx == 1) {
    if (queries[lx] != -1) {
        // TODO: resposta no tempo lx
    }
    dsu.undo(antes);
    return;
  }
  int mid = lx + (rx - lx) / 2;
  solve(2 * pos + 1, lx, mid);
  solve(2 * pos + 2, mid, rx);
  dsu.undo(antes);
}

vector<iiii> lifetime;
map<ii, int> edges;

void addEdge(int u, int v, int timer) {
  if (u > v) swap(u, v);
  edges[ii(u, v)] = timer;
}

void remEdge(int u, int v, int timer) { // assume que (u, v) existe
  if (u > v) swap(u, v);
  int l = edges[ii(u, v)], r = timer;
  lifetime.emplace_back(l, r, u, v);
  edges.erase(ii(u, v));
}

void doAll(int timer) {
  map<ii, int> tmp = edges;
  for (auto &[uv, _] : tmp) remEdge(uv.first, uv.second, timer);
  for (auto &val : lifetime) add(val, 0, 0, tamseg);
  solve(0, 0, tamseg); 
}
