int in[MAX], low[MAX], id[MAX], tk;  // block-cut-tree
bool art[MAX];
vi adj[MAX], stk;
vector<vi> children, blocks;

void dfs_blk(int u, int p) {
  in[u] = low[u] = ++tk;
  stk.push_back(u);
  for (auto &v : adj[u]) {
    if (v == p) continue;
    if (in[v]) {  // back
      low[u] = min(low[u], in[v]);
    } else {  // fwd
      dfs_blk(v, u);
      low[u] = min(low[u], low[v]);

      if (low[v] >= in[u]) {
        art[u] = (in[u] > 1 || in[v] > 2);
        blocks.push_back({u});
        while (blocks.back().back() != v) {
          // TODO: entender porque não é a outra condicao
          blocks.back().push_back(stk.back());
          stk.pop_back();
        }
      }
    }
  }
}

void blockcut(int n) {
  for (int i = 0; i < n; i++)
    if (!in[i]) dfs_blk(i, i);

  children.resize(blocks.size());
  for (int i = 0; i < n; i++)
    if (art[i]) {
      id[i] = children.size();
      children.emplace_back();
    }
  for (int i = 0; i < blocks.size(); i++) {
    for (auto &u : blocks[i]) {
      if (!art[u]) {
        id[u] = i;
      } else {
        children[id[u]].emplace_back(i);
        children[i].emplace_back(id[u]);
      }
    }
  }
}
