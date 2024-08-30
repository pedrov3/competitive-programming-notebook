// TODO: lca, distancia entre dois vertices com custo (?), tempo de entrada da
// DFS
int virtual_tree(vi vet) {
  auto cmp = [&](int i, int j) { return in[i] < in[j]; };
  sort(all(vet), cmp);
  for (int i = vet.size() - 1; i; i--) vet.push_back(lca(vet[i - 1], vet[i]));
  sort(all(vet), cmp);
  vet.erase(unique(all(vet)), vet.end());
  for (int i = 0; i < vet.size(); i++) virt[vet[i]].clear();
  for (int i = 1; i < vet.size(); i++) {
    int parent = lca(vet[i - 1], vet[i]);
    int d = dist(parent, vet[i]);
    virt[parent].emplace_back(vet[i], d);
  }
  return vet[0];
}
