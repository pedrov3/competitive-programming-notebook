// TODO: copy lca code
int kth(int u, int v, int k) { // k is 0-indexed
  int d = solve(u, v);  // distance between two nodes
  if (d < k) return -1;
  if (k <= solve(u, lca(u, v))) {
    return goup(u, k);
  } else {
    return goup(v, d - k);
  }
}
