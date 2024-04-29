vector<iii> edges;  // {peso, u, v}

int kruskal(int n) {
  sort(all(edges));
  init();
  int cost = 0;
  for (auto &[w, u, v] : edges)
    if (__find(u) != __find(v)) {
      cost += w;
      join(u, v);
    }
  return cost;
}
