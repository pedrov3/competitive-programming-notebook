vector<iii> edges;  // {peso, u, v}

int kruskal(int n) {
  sort(all(edges));
  dsu d(n);
  int cost = 0;
  for (auto &[w, u, v] : edges)
    if (d.find(u) != d.find(v)) {
      cost += w;
      d.join(u, v);
    }
  return cost;
}
