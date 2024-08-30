// Resolve o problema: https://www.acmicpc.net/problem/13515
// DP em árvore com alteração (HLD + Segment tree)

struct item {
  int color, sz, pref, is_empty = 1;
  item operator+(item oth) {
    if (this->is_empty) return oth;
    if (oth.is_empty) return *this;
    return {this->color, this->sz + oth.sz,
            this->sz == this->pref && this->color == oth.color
                ? this->pref + oth.pref
                : this->pref,
            0};
  }
};

// TODO: adicionar código de HLD

segtree<int> seg_color;
segtree<item> seg_dp;
vector<vi> light;
vi color;

void updateDP(int u) {
  seg_dp.set(pos[u],
             {color[u], light[u][color[u]] + 1, light[u][color[u]] + 1, 0});
}
void build(int n) {
  color = vi(n);
  remove_parent();
  fill();
  hld(head[0] = 0);
  seg_color = segtree<int>(n);
  for (int i = 0; i < n; i++) seg_color.set(i, color[sop[i]]);

  light = vector<vi>(n, vi(2));
  seg_dp = segtree<item>(n);
  for (int u = 1; u < n; u++)
    if (head[u] == u) {
      light[par[u]][color[u]] += sz[u];
    }
  for (int i = 0; i < n; ++i) updateDP(i);
}

void toggle(int u) {
  bool has_changed = 0;
  while (head[u] != 0) {
    light[par[head[u]]][color[head[u]]] -=
        seg_dp.get(pos[head[u]], pos[tail[u]] + 1).pref;
    if (!has_changed) {
      has_changed = 1;
      color[u] ^= 1;
      seg_color.set(pos[u], color[u]);
    }
    updateDP(u);
    light[par[head[u]]][color[head[u]]] +=
        seg_dp.get(pos[head[u]], pos[tail[u]] + 1).pref;
    u = par[head[u]];
  }
  if (!has_changed) {
    has_changed = 1;
    color[u] ^= 1;
    seg_color.set(pos[u], color[u]);
  }
  updateDP(u);
}

int solve(int u) {
  int c = color[u];
  while (head[u] != 0 && color[par[head[u]]] == c &&
         (seg_color.get(pos[head[u]], pos[u] + 1) ==
          (c * (h[u] - h[head[u]] + 1))))
    u = par[head[u]];
  int l = 0;
  int r = h[u] - h[head[u]] + 1;
  while (r - l > 1) {
    int mid = l + (r - l) / 2;
    if (seg_color.get(pos[u] - mid, pos[u] + 1) == (c * (mid + 1)))
      l = mid;
    else
      r = mid;
  }
  u = sop[pos[u] - l];
  return seg_dp.get(pos[u], pos[tail[u]] + 1).pref;
}
